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
#include <signal.h>

sw::redis::Redis *redis;
void handle_new_connection(client *c);

void server::start(int port_number)
{

    cache = new lru_cache(100);
    epollfd = epoll_create(1);
    sem_init(&handler_sem, 0, 0);

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
    std::thread handle_thread(&server::handle_message, this);

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

void server::handle_message()
{
    while (true)
    {
        sem_wait(&handler_sem);
        if (has_message.size() != 0)
        {
            lock.lock();
            int sock = has_message.front();
            has_message.pop();
            lock.unlock();

            client *c = m.at(sock);

            packet *p = new packet;
            c->read_message(p);

            handler_pointer message_handler = GET_HANDLER_FOR_MESSAGE(p->head);
            message_handler(p, c);
        }
    }
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
            // if evicted
            if (c == NULL)
            {
                continue;
            }

            int num_bytes = 0;
            ioctl(fd, FIONREAD, &num_bytes);
            spdlog::debug("Number of bytes available: {}", num_bytes);

            has_messages[i] = c;
            // handle_new_connection(c);

            if (num_bytes > 400)
            {
                continue;
            }

            read_in(c);
        }
    }
}
void server::handle_read_to_client(client *c)
{
    int bytes_read = c->read_from_socket(c->desired_bytes - c->received_bytes);
    if (bytes_read == -1)
    {
        std::cout << "TOO SLOW" << std::endl;
        disconnect_from_client(c);
        return;
    }

    c->received_bytes += bytes_read;
    if (c->received_bytes == c->desired_bytes)
    {
        c->received_bytes = 0;
        c->desired_bytes = 0;

        // if body is completed add to queue to be processed
        if (c->completed_header)
        {

            has_message.push(c->socket_fd);
            sem_post(&handler_sem);
        }

        c->completed_header = !c->completed_header;
    }
}
void server::read_in(client *c)
{
    // Finish unfinished read
    if (c->received_bytes < c->desired_bytes)
    {
        handle_read_to_client(c);
    }

    // Read in payload
    if (c->completed_header == true)
    {

        header *h = (header *)(c->buffer->expose_write_pointer() - sizeof(header) - 1);
        uint8_t *t = (c->buffer->expose_write_pointer() - sizeof(header::buf_size));
        uint32_t *payload_size = reinterpret_cast<uint32_t *>(t);
        c->desired_bytes = *payload_size;
        c->received_bytes = 0;

        handle_read_to_client(c);
    }

    // Read in a header
    else
    {
        c->desired_bytes = 26;
        c->received_bytes = 0;

        handle_read_to_client(c);
    }

    // // If a read finishes then continue until eAgain
    // if (c->desired_bytes == 0)
    // {
    //     int bytes_on_wire = 0;
    //     ioctl(c->socket_fd, FIONREAD, &bytes_on_wire);
    //     if (bytes_on_wire > 0)
    //         read_in(c);
    // }
}

// use client
// anything that is kind of uniquely belonging to the connection
// thread dedicated to poll and select, pass in a list of FDs
// wake which ever threads have data on them so they can continue (signal sempahore)

void server::disconnect_from_client(client *c)
{
    spdlog::info("Disconnecting from FD: {}", c->socket_fd);
    shutdown(c->socket_fd, SHUT_RDWR);
    connections--;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, c->socket_fd, NULL);
    c->is_active = false;
}
