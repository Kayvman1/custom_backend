#include "../ring_buffer/virtual_socket.h"
#include <vector>
#include <mutex>
class server
{
public:
    void start(int port_number);

    std::mutex lock;
    std::vector<virtual_socket*> connections;
    virtual_socket *new_virtual_connection();
    void terminate_virtual_connections(virtual_socket *connection);
};