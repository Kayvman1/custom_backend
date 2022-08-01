// Server side C program to demonstrate Socket programming
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

#include "../packets/packets.h";
#include "../ring_buffer/ring_buffer.h"

//#define PORT 8080

enum Endian
{
    big,
    small
};

sem_t x, y;

void signal_callback_handler(int e)
{
    std::cout << "signal callback" << std::endl;
}

// consider what happens if you want to retransmit whats in a socket when a conenction fails.
// Each client might have listening thread and an execute
// control packet vs streaming packets
// learn byte protcol for web
// learn http protocol standards
// terminate called without an active exception
// select or poll reading out of socket
//  Spin reading?


//Where is the handshake handled?
void handle_thread(int socket)
{
    signal(SIGPIPE, signal_callback_handler);
    while (true)
    {
        
        char buffer[30000] = {0};
        uint8_t id;
        uint32_t size;

        long valread;

        if ((valread = read(socket, &id, 1)) == sizeof(id))
        {
            printf("id: %i\n", id);

            switch (id)
            {
            case 1:
                handle_auth_message();
                break;
            default:
                printf("A");
            }
        }

        else
        {

            printf("Read 1 fail");
            break;
            // Write better logging and import class for logging;
            //  on every read that is zero you want to continue
        }

        // Begin deseralizing and sending structs to correct threads

        if (valread = read(socket, &size, 4) == sizeof(size))
        {
            printf("size: %i\n", size);
        }

        else
        {
            printf("Read 2 fail");
            break;
        }

        if (valread = read(socket, buffer, size) == size)
        {

            printf("Payload: %s \n", buffer);
        }
        else
        {

            printf("Read 3 %li\n", valread);
            break;
        }

        write(socket, "test", strlen("test"));
        printf("------------------message sent-------------------\n");
    }

    return;
}

// TODO SET THREAD AS BLOCKING SO YOU CAN'T READ PACKET SEGMANTS
// What to do when whole message isnt sent

int main(int argc, char const *argv[])
{ // server   //client
    int server_fd, new_socket;

    long valread;

    /* Structure describing an Internet socket address.  */
    struct sockaddr_in address;
    // IDK
    struct sockaddr_storage serverStorage;

    // idk int
    socklen_t addr_size;

    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    int user_port = 8080;
    if (argc == 2)
    {
        user_port = atoi(argv[1]);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(user_port);

    // removes the garabage values from the rest of the address
    memset(address.sin_zero, '\0', sizeof address.sin_zero);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Successful binding on port %i\n", user_port);
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
            std::thread clientThread(handle_thread, new_socket);
            clientThread.detach();
        }
    }
    return 0;
}
