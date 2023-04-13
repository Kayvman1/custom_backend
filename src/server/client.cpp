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
    header *h = (header *)calloc(26, 1);
    uint8_t *read_pointer = (uint8_t *)h;

    buffer->read_buf(26, read_pointer);

    p->head = h;

    uint8_t *m = (uint8_t *)malloc(400);
    p->payload = m;

    buffer->read_buf(h->buf_size,m);

    // void *x1 = p->unpack_from_ringbuffer(p, buffer);
}