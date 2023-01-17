#pragma once

#define qwerty 5
//TODO fix this qwerty bullshit, its currently used as a 
//signal for when a virtual socket is being used
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
