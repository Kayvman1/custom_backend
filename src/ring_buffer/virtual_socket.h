#include "../ring_buffer/ring_buffer.h"

class virtual_socket
{
public:
    ring_buffer server_endpoint;
    ring_buffer client_endpoint;
    void *server_read();
    void server_write();
    void *client_read();
    void client_write();
};