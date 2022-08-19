#pragma once
//#ifndef __VIRTUAL_SOCKET__
//#define __VIRTUAL_SOCKET__
#include "ring_buffer.h"

class virtual_socket
{
public:
    virtual_socket();
    ring_buffer server_endpoint;
    ring_buffer client_endpoint;

    ssize_t read(int sockfd, void *buffer, size_t num_bytes);
    ssize_t write(int sockfd, void *buffer, size_t num_bytes);
};

enum virtual_fd
{
    SERVER,
    CLIENT
};
//#endif