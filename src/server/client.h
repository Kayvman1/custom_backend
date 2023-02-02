#pragma once
#include <sys/epoll.h>
#include "../accounts/account.h"

class client
{
public:
    client();
    account *user;
    int session_id;
    int socket_fd;
    bool is_active = true;
    bool is_reading = false;
};
