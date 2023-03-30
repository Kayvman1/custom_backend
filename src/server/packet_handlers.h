#pragma once
#include "server.h"
#include "client.h"
#include <spdlog/spdlog.h>
#include <signal.h>

class packet_handlers
{
public:
    static void response_handler(uint8_t *raw_msg, packet *in, client *user);
    static void test_request_handler(uint8_t *raw_msg, packet *in, client *user);
    static void login_request_handler(uint8_t *raw_msg, packet *in, client *user);
    static void create_user_request_handler(uint8_t *raw_msg, packet *in, client *user);
};
