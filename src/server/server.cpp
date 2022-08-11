#include <unistd.h>

#include <arpa/inet.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include <cstddef>

#include "../packets/packets.h"
#include "server.h"

void server::start(int port_number)
{
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

    while (true)
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
            // std::thread clientThread(handle_thread, new_socket);
            // clientThread.detach();
        }
    }
    return;
}

virtual_socket *server::new_virtual_connection()
{
    virtual_socket *sock = new virtual_socket;
    lock.lock();
    connections.push_back(sock);
    lock.unlock();
    return sock;
}

void server::terminate_virtual_connections(virtual_socket *connection)
{
    lock.lock();
    for (int i = 0; i < connections.size(); i++)
    {
        if (connections[i] == connection)
        {
            connections.erase(connections.begin() + i - 1);
        }
    }
    lock.unlock();
}
