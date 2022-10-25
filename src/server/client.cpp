#include "client.h"
#include <sys/socket.h>

client::client()
{
    user = new account;
    socket = new socket_wrapper;
}

socket_wrapper::socket_wrapper()
{
    vs = new virtual_socket;
    
}

ssize_t socket_wrapper::read(int sockfd, uint8_t *ibuff, size_t num_bytes)
{

    int val_read = -1;
#ifdef qwerty
    val_read = vs->read(virtual_fd::SERVER, ibuff, num_bytes);
#else
    val_read = read(socket_fd, ibuff, num_bytes);
#endif
    return val_read ;
}

ssize_t socket_wrapper::write(int sockfd, uint8_t *ibuff, size_t num_bytes)
{
    #define qwerty 5
    int val_read = -1;
#ifdef qwerty
    val_read = vs->write(virtual_fd::CLIENT, ibuff, num_bytes);
#else
    val_read = send(socket_fd, ibuff, num_bytes, 0);
#endif
    return val_read;
}