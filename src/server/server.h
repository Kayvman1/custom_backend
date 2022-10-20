#pragma once

#include "../ring_buffer/virtual_socket.h"
#include "../packets/packets.h"
#include <vector>
#include <mutex>
#include <sw/redis++/redis++.h>



class server
{
public:
   
    std::mutex lock;
    std::vector<virtual_socket *> connections;
    virtual_socket *new_virtual_connection();


    void start(int port_number);
    void terminate_virtual_connections(virtual_socket *connection);
    void handle_message(virtual_socket *socket);
};
