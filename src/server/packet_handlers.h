#pragma once
#include "server.h"
#include "client.h"
#include <spdlog/spdlog.h>
#include <signal.h>
#include "../packets/packets.h"

class packet_handlers
{
public:
    static void response_handler( packet *in, client *user);
    static void test_request_handler( packet *in, client *user);
    static void login_request_handler( packet *in, client *user);
    static void create_user_request_handler( packet *in, client *user);
    static void poem_create_request_handler(packet*in, client *c);
};
