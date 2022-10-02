#pragma once
#include "../ring_buffer/virtual_socket.h"

class packet_handlers
{
public:
    static void response_handler(uint8_t *raw_msg, virtual_socket *vs);
    static void test_request_handler(uint8_t *raw_msg, virtual_socket *vs);
    static void test_connection();
};