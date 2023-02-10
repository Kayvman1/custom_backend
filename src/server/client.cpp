#include "client.h"
#include <sys/socket.h>

client::client()
{
    user = new account;
    int size = RING_SIZE;
    buffer = new ring_buffer (size);
}

