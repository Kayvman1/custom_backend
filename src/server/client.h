#pragma once
#include "../accounts/account.h"
#include "../ring_buffer/ring_buffer.h"

class client
{
public:

//TODO do i need to lock on read and write calls? This doesn't fully solve race conditions because messages can still
//be split over multiple reads. Does this need to be solved idiomatically? 
    client();
    account *user;
    int session_id;
    int socket_fd;
    bool is_active = true;
    bool is_reading = false;
    ring_buffer *buffer;

};
