// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include <thread>
#include <chrono>
#include <iostream>

//#define PORT 8080

enum Endian
{
    big,
    small
};

Endian endianCheck()
{
    uint16_t checkVal = 0x0001;
    uint8_t *byte = reinterpret_cast<uint8_t *>(&checkVal);
    if (byte[0] == 0x01)
    {
        return Endian::small;
    }
    return Endian::big;
}

uint32_t endianSwap(uint32_t val)
{
    uint32_t newVal = 0;
    // increaming the pointer incremants size of data type in memory
    // cast the address the pointer type of the correct type
    u_int8_t *pointer = reinterpret_cast<uint8_t *>(&val);
    for (int i = 0; i < sizeof(uint32_t); i++)
    {
        newVal = newVal << 8;
        newVal = (newVal | pointer[i]);
    }
    return newVal;
}

uint32_t my_htons(uint32_t val)
{
    if (endianCheck() == Endian::big)
        return val;

    return endianSwap(val);
}

// Message id 1 for now
//double ** pointer
//what happens when using a single pointer
uint32_t pack_auth_message(uint8_t *buffer)
{
    u_int8_t id = 1;
    char username[1024];
    scanf("%s", username);

    // we want to use Strlen beacuse size of gives us size of the memory block not the null terminated string
    uint32_t size = strlen(username);

    memcpy(buffer + 0, &id, 1);
    memcpy(buffer + 1, &size, 4);
    memcpy(buffer + 5, username, size);

    printf("Id: %i Size: %i\n", id, size);
    return 1 + 4 + size;
}

int main(int argc, char const *argv[])
{

    // using namespace std::chrono_literals;

    int sock = 0;
    long valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    //char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    int user_port = 8080;
    if (argc == 2)
    {
        user_port = atoi(argv[1]);
    }

    serv_addr.sin_port = htons(user_port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    while (true)
    {
        // Eventually this will become a ring buffer

        //Keep in mind sizes my change on different systems
        uint8_t *buffer = (uint8_t *)calloc(3000, sizeof(u_int8_t));
        uint32_t pack_size = pack_auth_message(buffer);


        printf("packetsize: %i\n", pack_size);

        uint8_t id;
        memcpy(&id, buffer , 1);
        printf("packet id: %i \n", id);

        uint32_t size;
        memcpy(&size, buffer + 1, 4);
        printf("payload size: %i \n", size);

        int x = send(sock, buffer, pack_size, 0);
        printf("message sent\n");

        valread = read(sock, buffer, 1024);

        // double check number of bytes read
        if (valread < 0)
        {
            printf("Unable to read message from server");
        }
        else
        {
            // printf("%s\n", buffer);
            printf("Read a message from server");
        }
    }
    return 0;
}