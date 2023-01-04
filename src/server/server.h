#pragma once

#include "../packets/packets.h"
#include <vector>
#include <mutex>
#include <sw/redis++/redis++.h>
#include "client.h"



class server
{
public:
   
    std::mutex lock;
    

    void start(int port_number);
    void handle_message(client *user);
};
