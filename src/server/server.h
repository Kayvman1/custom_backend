#pragma once

#include "../packets/packets.h"
#include <vector>
#include <mutex>
#include <sw/redis++/redis++.h>
#include "client.h"
#include <map>
#include "sem.h"
#include <poll.h>

class server
{
public:
    std::mutex lock;

    void start(int port_number);

private:
    std::map<int, client *> m;
    void poll_listener_thread();
    pollfd pollers [100];
    int connections = 0;
    static void poop(void *);
    void disconnect_from_client(client *c);
    void handle_new_connection(client *c);
};



