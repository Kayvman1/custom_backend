#pragma once
//#ifndef __VIRTUAL_SOCKET__
//#define __VIRTUAL_SOCKET__
#include "ring_buffer.h"

class virtual_socket
{
public:
    virtual_socket();
    ring_buffer* server_endpoint;
    ring_buffer* client_endpoint;

    ssize_t read(int sockfd, uint8_t *buffer, size_t num_bytes);
    ssize_t write(int sockfd, uint8_t *buffer, size_t num_bytes);
};

enum virtual_fd
{
    SERVER,
    CLIENT
};
//#endif


//IMPLEMENT POLL AND SELECT 

/*think about how you would use epoll if you were using actually sockets
	your not going to use all the different events and blocks and ... epoll in out whatever the fuck
if your just using this to tell when to read you can make your own simulated epoll.
	you can make epoll hang artifically such that it creates a simialr interaction to real server
	effiency is not important*/
    