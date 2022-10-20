#include "packet_handlers.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"
#include "server.h"
#include <stdio.h>
#include <sw/redis++/redis++.h>
// # include <iostream>
// using namespace sw::redis;

extern sw::redis::Redis *redis;

class response
{
public:
    int status;
    std::string message;
};

// CORRECT id generation
// Create an interface or wrapper class that contains either a vs or socket
//Create error message with status code (that you define, and a response with text explaining the issue )
void packet_handlers::login_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");

    login_request *message = new login_request;
    login_request::unpack(message, raw_msg);
    login_response *resp = new login_response();
    packet *p = new packet;
    p->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    p->message_id = CONTROL_PACKET_IDS::login_response_id;
    uint8_t *buffer = (uint8_t *)malloc(3000);

    auto response = redis->get("username:" + message->username);

    if (response)
    {
        p->flags = 0;
        p->magic = 54321;
        p->session_token = 0;
        resp->status = 400;

        int packet_size = packet::pack(p, buffer, resp);
        vs->write(virtual_fd::CLIENT, buffer, packet_size);
        free(raw_msg);
        free(buffer);
        return;
    }
    else
        std::cout << "no response" << std::endl;

    auto incr = redis->incr("userIdCount");
    std::string id = std::to_string(incr);
    redis->set("username:" + message->username, id);
    std::string value = "username " + message->username + " password " + message->password;
    std::string key = "user:" + id;
    redis->hset(key, "USERNAME", message->username);
    redis->hset(key, "PASSWORD", message->password);

    p->flags = 0;
    p->magic = 12345;
    p->session_token = 0;
    resp->status = 201;
    resp->user = new account;

    int packet_size = packet::pack(p, buffer, resp);
    vs->write(virtual_fd::CLIENT, buffer, packet_size);
    free(raw_msg);
    free(buffer);
    return;
}

void packet_handlers::test_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    test_request *req = new test_request();
    test_response *resp = new test_response();
    uint8_t *buf = (uint8_t *)std::malloc(500);
    test_request::unpack(req, raw_msg);
    resp->val = req->val;

    packet *p = new packet();
    p->message_type = TEST_PACKET;
    p->message_id = TEST_PACKET_IDS::test_response_id;
    size_t packet_size = packet::pack(p, buf, resp);
    vs->write(virtual_fd::CLIENT, buf, packet_size);

    return;
}

void packet_handlers::response_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    return;
}