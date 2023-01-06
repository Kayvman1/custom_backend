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
#include <postgresql/libpq-fe.h>
#include "client.h"

#include <errno.h>
sw::redis::Redis *redis;
void handle_new_connection(client *c);

void server::start(int port_number)
{
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

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Successful binding on port %i\n", port_number);
    }
    if (listen(server_fd, 50) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Successfully listening\n");
    }

    // accept client and then pass forward to code
    // that handels communications

    printf("\n+++++++ Waiting for new connection ++++++++\n\n");

    int i = 0;

    while (true) // TODO WAKE ON CONNECTION
    {
        addr_size = sizeof(serverStorage);
        new_socket = accept(server_fd,
                            (struct sockaddr *)&serverStorage,
                            &addr_size);
        if (new_socket < 0)
        {
            perror("connection acception failed");
        }

        else
        {
            printf("CONNECTION\n");
            client *c = new client;
            c->is_active = true;
            c->session_id = 0; // TODO generate this
            c->socket_fd = new_socket;

            handle_new_connection(c);
            // std::thread clientThread(handle_new_connection, c);
            // clientThread.detach();
        }
        // lru
    }
    return;
}

// use client
// anything that is kind of uniquely belonging to the connection
// thread dedicated to poll and select, pass in a list of FDs
// wake which ever threads have data on them so they can continue (signal sempahore)

void read_attribute(uint8_t *buf, int size, client *c)
{
    printf("new attribute\n");
    int b_count = 0;
    int val_read;
    while (b_count < size)
    {
        val_read = read(c->socket_fd, buf + b_count, size - b_count);
        b_count += val_read;

        if (val_read + b_count < size)
        {
            if (errno = EWOULDBLOCK)
            {
                // sleep
                // semaphore
                // your gonna have some table of semaphores
            }
            else
            {
                read(c->socket_fd, buf + b_count, size - b_count);
            }
        }
    }
}

void handle_new_connection(client *c)
{
    printf("new thread\n");
    while (c->is_active)
    {
        uint8_t message_buffer[3000];
        uint8_t assembly_buffer[3000];
        packet *unpack = new packet;
        int val_read = 0;
        int b_count = 0;

        read_attribute(&unpack->message_type, sizeof(packet::message_type), c);
        read_attribute(&unpack->message_id, sizeof(packet::message_id), c);
        read_attribute((uint8_t *)&unpack->magic, sizeof(packet::magic), c);
        read_attribute((uint8_t *)&unpack->session_token, sizeof(packet::session_token), c);
        read_attribute((uint8_t *)&unpack->flags, sizeof(packet::flags), c);
        read_attribute((uint8_t *)&unpack->buf_size, sizeof(packet::buf_size), c);
        read_attribute(message_buffer, unpack->buf_size, c);
        printf("Complete Read \n");
        // unpack->message_unpack(message_buffer);

        handler_pointer func = GET_HANDLER_FOR_MESSAGE(unpack);

        func(message_buffer, unpack, c);
    }
}

void server::handle_message(client *user)
{

    uint8_t message_buffer[3000];
    packet *unpack = new packet;

    long val_read;
    val_read = read(user->socket_fd, &unpack->message_type, sizeof(packet::message_type));
    val_read = read(user->socket_fd, (uint8_t *)&unpack->magic, sizeof(packet::magic));
    val_read = read(user->socket_fd, &unpack->message_id, sizeof(packet::message_id));
    val_read = read(user->socket_fd, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
    val_read = read(user->socket_fd, (uint8_t *)&unpack->flags, sizeof(packet::flags));
    val_read = read(user->socket_fd, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
    val_read = read(user->socket_fd, message_buffer, unpack->buf_size);

    handler_pointer func = GET_HANDLER_FOR_MESSAGE(unpack);

    // func(this, message_buffer, user);
}
