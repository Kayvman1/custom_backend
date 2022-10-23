#pragma once
#include "../ring_buffer/virtual_socket.h"
#include "server.h"

class packet_handlers
{
public:
    static void response_handler(server *s, uint8_t *raw_msg, virtual_socket *vs);
    static void test_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs);
    static void test_connection();
    static void login_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs);
    static void create_user_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs);
};