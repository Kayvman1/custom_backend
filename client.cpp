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


#define PORT 8080

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

int main(int argc, char const *argv[])
{

    //using namespace std::chrono_literals;

    int sock = 0; long valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
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
        
        //std::this_thread::sleep_for(50000ms);

        std::string username;
        std::cin >> username;
        std::cout << "username " << username << "Lenght " << username.length() << std::endl ;

        uint8_t byte_array [0];
        memset(byte_array, 0,sizeof(username) + 4);
        uint32_t size = (uint32_t) sizeof(username);



        int x = send(sock , "hello" , strlen("hello") , 0 );
        printf("%i", x);
        printf("Hello message sent\n");
        valread = read( sock , buffer, 1024);
        //double check number of bytes read
        if (valread < 0){
            printf("No Good");
        }
        else {
            printf("%s\n",buffer );
        }
    }
    return 0;
}