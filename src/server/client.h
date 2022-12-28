#pragma once

#define qwerty 5
//TODO fix this qwerty bullshit, its currently used as a 
//signal for when a virtual socket is being used
#include "../ring_buffer/virtual_socket.h"
#include "../accounts/account.h"

class socket_wrapper
{
public:
    socket_wrapper();
    ssize_t read(int sockfd, uint8_t *ibuff, size_t num_bytes);
    ssize_t write(int sockfd, uint8_t *ibuff, size_t num_bytes);
    virtual_socket *vs;
    int socket_fd;

};

class client
{
public:
    client();
    account *user;
    socket_wrapper *socket;
    int session_id;
};
