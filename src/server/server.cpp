#include <unistd.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include <cstddef>

#include "server.h"
#include "../packets/packet_ids.h"
#include "packet_handlers.h"

#include "client.h"

#include <errno.h>
#include "spdlog/spdlog.h"
#include "sem.h"

#include <poll.h>

#include <sys/ioctl.h>
sw::redis::Redis *redis;
void handle_new_connection(client *c);

void server::start(int port_number)
{
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

        spdlog::info("Successfully listening");
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
            // spdlog::error("connection acception failed");
        }

        else
        {
            spdlog::debug("New connection on fd {}", new_socket);
            client *c = new client;
            c->is_active = true;
            c->session_id = 0; // TODO generate this
            c->socket_fd = new_socket;

            int flags = fcntl(new_socket, F_GETFL, 0);
            fcntl(new_socket, F_SETFL, flags | O_NONBLOCK);

            m.insert(std::pair<int, client *>(c->socket_fd, c));
            spdlog::info("{}", c->socket_fd);

            pollers[connections] = pollfd();
            pollers[connections].events = POLLIN;
            pollers[connections].fd = new_socket;
            connections++;
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

        if (poll(pollers, connections, 1000) > 0)
        {
            for (int i = 0; i < connections; i++)
            {
                if (pollers[i].revents & POLLIN)
                {
                    int fd = pollers[i].fd;
                    client *c = m.at(fd);
                    int num_bytes = 0;

                    ioctl(fd, FIONREAD, &num_bytes);
                    spdlog::info("Number of bytes available: {}", num_bytes);
                    char blah[3000];
                    if (num_bytes == 0)
                    {
                        num_bytes = read(fd, blah, UINT32_MAX);
                        spdlog::info("Errno: {}, read: {}", errno, num_bytes);
                    }
                    if (read(fd, blah, 0) == -1)
                    {
                        break;
                    }
                    handle_new_connection(c);
                }
            }
        }
    }
}

// use client
// anything that is kind of uniquely belonging to the connection
// thread dedicated to poll and select, pass in a list of FDs
// wake which ever threads have data on them so they can continue (signal sempahore)

int read_attribute(uint8_t *buf, int size, client *c)
{
    spdlog::debug("Attribute read size {}: ", size);
    int b_count = 0;
    int val_read;

    while (b_count < size)
    {
        val_read = read(c->socket_fd, buf + b_count, size - b_count);

        if (errno != 0 && errno != EWOULDBLOCK)
        {
            spdlog::debug("Non-0 Errno {}: Valread {}: ", errno, val_read);
        }

        if (val_read > 0)
        {
            b_count += val_read;
        }

        if (val_read == 0 && errno != EWOULDBLOCK)
        {
            spdlog::debug("Connection closed");
            return -1;
        }

        if (val_read + b_count < size)
        {
            if (errno == EWOULDBLOCK)
            {
                spdlog::debug("EWOULDBLOCK");
                // sleep
                // semaphore
                // your gonna have some table of semaphores
                if (val_read != 0)
                    spdlog::info("{}", val_read);
            }
            else
            {
                if (val_read != 0)
                    spdlog::info("{}", val_read);
            }
        }
    }
    return 1;
}

void server::disconnect_from_client(client *c)
{
    shutdown(c->socket_fd, SHUT_RDWR);
    connections --;

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
        spdlog::error("ERROR on read");
        return;
    }
    if (read_attribute((uint8_t *)&unpack->magic, sizeof(packet::magic), c) == -1)
    {
        spdlog::error("ERROR on read");
        return;
    }
    if (read_attribute((uint8_t *)&unpack->session_token, sizeof(packet::session_token), c) == -1)
    {
        spdlog::error("ERROR on read");
        return;
    }
    if (read_attribute((uint8_t *)&unpack->flags, sizeof(packet::flags), c) == -1)
    {
        spdlog::error("ERROR on read");
        return;
    }
    if (read_attribute((uint8_t *)&unpack->buf_size, sizeof(packet::buf_size), c) == -1)
    {
        spdlog::error("ERROR on read");
        return;
    }
    if (read_attribute(message_buffer, unpack->buf_size, c) == -1)
    {
        spdlog::error("ERROR on read");
        return;
    }
    spdlog::debug("Complete Read \n");

    // unpack->message_unpack(message_buffer);

    handler_pointer func = GET_HANDLER_FOR_MESSAGE(unpack);

    func(message_buffer, unpack, c);
    c->is_reading = false;
}