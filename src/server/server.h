#pragma once

#include "../packets/packets.h"
#include <mutex>
#include <sw/redis++/redis++.h>
#include "client.h"
#include <map>
#include <poll.h>
#include "../lru_cache/lru_cache.h"
#include <semaphore.h>


#define MAX_EVENTS 10
class server
{
public:
    std::mutex lock;

    void start(int port_number);

private:
    std::map<int, client *> m;
    lru_cache *cache;

    void poll_listener_thread();
    pollfd pollers[100];
    int connections = 0;
    void disconnect_from_client(client *c);
    void handle_new_connection(client *c);
    int read_attribute(uint8_t *buf, int size, client *c);
    int epollfd;

    void read_in(client *c);
    void handle_read_to_client(client *c);

    std::queue <int> has_message = std::queue<int>();
    void handle_message();

    sem_t handler_sem;
};
