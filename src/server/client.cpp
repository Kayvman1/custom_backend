#include "client.h"
#include <sys/socket.h>

client::client()
{
    user = new account;
    int size = RING_SIZE;
    buffer = new ring_buffer(size);
}

int client::read_from_socket(int len)
{
    return buffer->write_from_socket(socket_fd, len);
}

void client::read_message(packet *p)
{
    uint8_t *read_pointer = (uint8_t *)p;

    buffer->read_buf(26,read_pointer);
}