#pragma once
#include "server.h"
#include "client.h"

class packet_handlers
{
public:
    static void response_handler(server *s, uint8_t *raw_msg, client *user);
    static void test_request_handler(server *s, uint8_t *raw_msg, client *user);
    static void test_connection();
    static void login_request_handler(server *s, uint8_t *raw_msg, client *user);
    static void create_user_request_handler(server *s, uint8_t *raw_msg, client *user);
};