#include <unistd.h>
#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include <cstddef>
#include <errno.h>
#include <signal.h>
#include <poll.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include "spdlog/spdlog.h"
#include <sys/epoll.h>
#include <sys/ioctl.h>

#include "../packets/packet_ids.h"
#include "packet_handlers.h"

#include "../lru_cache/lru_cache.h"

#include "client.h"
#include "server.h"

sw::redis::Redis *redis;
void handle_new_connection(client *c);

void server::start(int port_number)
{

    cache = new lru_cache(6);
    epollfd = epoll_create(1);

    if (epollfd == -1)
    {
        spdlog::error("Error creating epoll instance");
    }

    spdlog::set_level(spdlog::level::debug);
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");
    int server_fd, new_socket;

    long valread;

    /* Structure describing an Internet socket address.  */
    struct sockaddr_in address;
    // IDK
    struct sockaddr_storage serverStorage;

    // idk int
    socklen_t addr_size;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_number);

    // removes the garabage values from the rest of the address
    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    int reuse = 1;

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuse, sizeof(reuse));
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, (const char *)&reuse, sizeof(reuse));

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        spdlog::error("Error binding to port");
        exit(EXIT_FAILURE);
    }
    else
    {
        spdlog::info("Successful binding on port {}", port_number);
    }
    if (listen(server_fd, 50) < 0)
    {
        spdlog::error("Error listening to port");
        exit(EXIT_FAILURE);
    }
    else
    {

        spdlog::info("Successfully listening\n");
    }

    // accept client and then pass forward to code
    // that handels communications

    spdlog::info("Waiting for connections");

    int i = 0;

    std::thread listen_thread(&server::poll_listener_thread, this);
    while (true) // TODO WAKE ON CONNECTION
    {
        addr_size = sizeof(serverStorage);
        new_socket = accept(server_fd,
                            (struct sockaddr *)&serverStorage,
                            &addr_size);
        if (new_socket < 0)
        {
            spdlog::error("connection acception failed");
        }

        else
        {
            spdlog::info("New connection on FD: {}", new_socket);

            client *c = new client;
            c->is_active = true;
            c->session_id = 0; // TODO generate this
            c->socket_fd = new_socket;

            int flags = fcntl(new_socket, F_GETFL, 0);
            fcntl(new_socket, F_SETFL, flags | O_NONBLOCK);

            m.insert(std::pair<int, client *>(c->socket_fd, c));

            client *evicted = cache->put(new_socket, c);

            if (evicted != NULL)
            {
                spdlog::info("Evicting FD: {}", evicted->socket_fd);
                disconnect_from_client(evicted);
            }

            connections++;

            struct epoll_event ev;
            ev.events = POLL_IN;
            ev.data.fd = new_socket;

            epoll_ctl(epollfd, EPOLL_CTL_ADD, new_socket, &ev);
        }
        // TODO SPAWN LRU tread
    }
    return;
}

void server::poll_listener_thread()
{

    spdlog::info("Poll thread created");

    while (true)
    {
        client *has_messages[100];
        struct epoll_event events[MAX_EVENTS];
        spdlog::debug("Pre wait");
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        spdlog::debug("Post wait NFDS: {}", nfds);
        for (int i = 0; i < nfds; i++)
        {

            int fd = events[i].data.fd;
            spdlog::debug("Handling FD: {}", fd);
            client *c = m.at(fd);
            c = cache->get(fd);

            int num_bytes = 0;
            ioctl(fd, FIONREAD, &num_bytes);
            spdlog::debug("Number of bytes available: {}", num_bytes);

            has_messages[i] = c;
            handle_new_connection(c);
        }
    }
}

// use client
// anything that is kind of uniquely belonging to the connection
// thread dedicated to poll and select, pass in a list of FDs
// wake which ever threads have data on them so they can continue (signal sempahore)

int server::read_attribute(uint8_t *buf, int size, client *c)
{
    int b_count = 0;
    int val_read;

    while (b_count < size)
    {
        val_read = read(c->socket_fd, buf + b_count, size - b_count);

        // Real error on reading
        if (errno != EAGAIN && val_read == -1)
        {
            spdlog::debug("Errno {}: ", errno);
        }

        // Poll event was disconnect
        if (val_read == 0)
        {
            spdlog::debug("Connection closed");
            c->failedCycles = 0;
            return -1;
        }

        if (val_read > 0)
        {
            b_count += val_read;
        }

        if (b_count < size)
        {
            if (errno == EWOULDBLOCK)
            {
                usleep(250000);
                c->failedCycles ++;

                if (c->failedCycles == 100)
                {
                    spdlog::error("Too many EAGAIN errors", size, b_count);
                    disconnect_from_client(c);
                }
            }

            else
            {
                spdlog::error("Expected {}, but read {}", size, b_count);
                c->failedCycles = 0;
                return b_count;
            }
        }
    }

    spdlog::debug("Attribute Size: {}, Attribute Read : {}", size, b_count);
    return b_count;
}

void server::disconnect_from_client(client *c)
{
    spdlog::info("Disconnecting from FD: {}", c->socket_fd);
    shutdown(c->socket_fd, SHUT_RDWR);
    connections--;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, c->socket_fd, NULL);
    c->is_active = false;
}

void server::handle_new_connection(client *c)
{

    uint8_t message_buffer[3000];
    uint8_t assembly_buffer[3000];
    packet *unpack = new packet;
    int val_read = 0;
    int b_count = 0;

    if (read_attribute(&unpack->message_type, sizeof(packet::message_type), c) == -1)
    {
        spdlog::debug("Disconncet");
        disconnect_from_client(c);

        return;
    }
    if (read_attribute(&unpack->message_id, sizeof(packet::message_id), c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, MessageID", c->socket_fd);
        return;
    }
    if (read_attribute((uint8_t *)&unpack->magic, sizeof(packet::magic), c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, Magic", c->socket_fd);
        return;
    }
    if (read_attribute((uint8_t *)&unpack->session_token, sizeof(packet::session_token), c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, Session Token", c->socket_fd);
        return;
    }
    if (read_attribute((uint8_t *)&unpack->flags, sizeof(packet::flags), c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, Flags", c->socket_fd);
        return;
    }
    if (read_attribute((uint8_t *)&unpack->buf_size, sizeof(packet::buf_size), c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, BufSize", c->socket_fd);
        return;
    }
    if (read_attribute(message_buffer, unpack->buf_size, c) == -1)
    {
        spdlog::error("Error durning read on FD: {}, Buffer", c->socket_fd);
        return;
    }
    spdlog::debug("Complete Read \n");

    // unpack->message_unpack(message_buffer);

    handler_pointer func = GET_HANDLER_FOR_MESSAGE(unpack);

    func(message_buffer, unpack, c);
    c->is_reading = false;
}