#include "virtual_socket.h"

void *virtual_socket::server_read()
{
    server_endpoint.read();
}

int virtual_socket::read_bytes(void *write_byte, int size)
{
    server_endpoint.lock; 
}