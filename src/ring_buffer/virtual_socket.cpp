#include "virtual_socket.h"
#include "ring_buffer.h"

virtual_socket::virtual_socket()
{
    ring_buffer *x = new ring_buffer();
    return;
}

ssize_t virtual_socket::write(int sockfd, void *buffer, size_t num_bytes)
{
    if (sockfd == virtual_fd::SERVER)
    {
        server_endpoint.write(buffer, num_bytes);
    }

    else if (sockfd == virtual_fd::CLIENT)
    {
        client_endpoint.write(buffer, num_bytes);
    }
}

ssize_t virtual_socket::read(int sockfd, void *buffer, size_t num_bytes)
{
    if (sockfd == virtual_fd::SERVER)
    {
        server_endpoint.read_bytes(buffer, num_bytes);
    }

    else if (sockfd == virtual_fd::CLIENT)
    {
        client_endpoint.read_bytes(buffer, num_bytes);
    }
}