#pragma once
#include "../accounts/account.h"
#include "../ring_buffer/ring_buffer.h"

class client
{
public:
    client();
    account *user;
    int session_id;
    int socket_fd;
    bool is_active = true;
    bool is_reading = false;
    ring_buffer *buffer;
};
