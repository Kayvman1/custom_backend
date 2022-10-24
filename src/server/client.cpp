#include "client.h"
#include <sys/socket.h>

ssize_t socket_wrapper::read(int sockfd, uint8_t *ibuff, size_t num_bytes)
{
    int val_read = -1;
#ifdef VIRTUAL
    val_read = vs->read(virtual_fd::SERVER, ibuff, num_bytes);
#else
    val_read = read(socket_fd, ibuff, num_bytes);
#endif
    return val_read ;
}

ssize_t socket_wrapper::write(int sockfd, uint8_t *ibuff, size_t num_bytes)
{
    int val_read = -1;
#ifdef VIRTUAL
    val_read = vs->write(virtual_fd::SERVER, ibuff, num_bytes);
#else
    val_read = send(socket_fd, ibuff, num_bytes, 0);
#endif
    return val_read;
}