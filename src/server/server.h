#pragma once

#include "../packets/packets.h"
#include <vector>
#include <mutex>
#include <sw/redis++/redis++.h>
#include "client.h"
#include <map>
#include "sem.h"

class server
{
public:
    std::mutex lock;

    void start(int port_number);

private:
    std::map<int, semaphore> m;
};



