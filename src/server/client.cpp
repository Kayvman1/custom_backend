#include "client.h"
#include <sys/socket.h>
#include "../packets/packets.h"

client::client()
{
    user = new account;
    int size = RING_SIZE;
    buffer = new ring_buffer(size);
    desired_bytes = 0;
    received_bytes = 0;
}

int client::read_from_socket(int len)
{
    return buffer->write_from_socket(socket_fd, len);
}

void client::read_message(packet *p)
{
    header *x = (header *)calloc(26, 1);
    uint8_t *read_pointer = (uint8_t *)x;

    // buffer->read_buf(26,read_pointer);

    void *x1 = p->unpack_from_ringbuffer(p, buffer);
}