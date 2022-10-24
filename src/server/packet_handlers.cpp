#include "packet_handlers.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"
#include "server.h"
#include <stdio.h>
#include <sw/redis++/redis++.h>
#include <openssl/sha.h>
#include <functional>
#include "../accounts/account.h"
#include "../posts/post.h"
// # include <iostream>
// using namespace sw::redis;

extern sw::redis::Redis *redis;

class response
{
public:
    int status;
    std::string message;
};

void packet_handlers::create_user_request_handler(server *s, uint8_t *raw_msg, client *user)
{
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");
    packet *p = new packet;
    // Ring Buffer ?
    uint8_t *buffer = (uint8_t *)malloc(3000);

    create_user_request *message = new create_user_request;
    create_user_request::unpack(message, raw_msg);

    auto redis_response = redis->get("username:" + message->username);

    if (redis_response)
    {
        p->message_type = ERROR_PACKET;
        p->message_id = error_response_id;
        p->flags = 0;
        p->magic = 54321;
        p->session_token = 0;
        error_response response = error_response();
        response.response = "User Already Exists";
        response.status = 0;
        int packet_size = packet::pack(p, buffer, &response);
        user->socket.write(virtual_fd::CLIENT, buffer, packet_size);
        free(raw_msg);
        free(buffer);
        return;
    }

    p->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    p->message_id = CONTROL_PACKET_IDS::login_response_id;
    p->flags = 0;
    p->magic = 12345;
    p->session_token = 0;
    create_user_response response = create_user_response();

    std::hash<std::string> hasher;
    unsigned char hash_out[64];
    SHA256((const unsigned char *)message->username.c_str(), message->username.length(), hash_out);
    uint64_t *val = (uint64_t *)hash_out;
    auto id = std::to_string(*val);
    std::string key = "user:" + id;
    redis->set("username:" + message->username, id);
    redis->hset(key, "USERNAME", message->username);
    redis->hset(key, "PASSWORD", message->password);

    response.status = 201;
    response.user = new account;

    int packet_size = packet::pack(p, buffer, &response);
    user->socket.write(virtual_fd::CLIENT, buffer, packet_size);
    free(raw_msg);
    free(buffer);
    return;
}

// CORRECT id generation
// Create an interface or wrapper class that contains either a vs or socket
// Create error message with status code (that you define, and a response with text explaining the issue )
void packet_handlers::login_request_handler(server *s, uint8_t *raw_msg, client *user)
{
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");

    uint8_t *buffer = (uint8_t *)malloc(3000);
    packet *p = new packet;
    login_request *msg = new login_request;
    login_request::unpack(msg, raw_msg);

    auto redis_response_id = redis->get("username:" + msg->username);

    if (!redis_response_id)
    {
        // USERNOT FOUND
        p->message_type = ERROR_PACKET;
        p->message_id = error_response_id;
        p->flags = 0;
        p->magic = 54321;
        p->session_token = 0;
        error_response response = error_response();
        response.response = "User Not Found";
        response.status = 0;
        int packet_size = packet::pack(p, buffer, &response);
        user->socket.write(virtual_fd::CLIENT, buffer, packet_size);
        free(raw_msg);
        free(buffer);
        return;
    }
    // std::unordered_map<std::string, std::string> m = {
    //     {"field1", "val1"},
    //     {"field2", "val2"}};
    // m.clear();

    // auto redis_response = redis->hgetall("user:" + *redis_response_id, m);

    // auto password = m.find("PASSWORD");
    // if (password->first != msg->password)
    // {
    //     p->message_type = ERROR_PACKET;
    //     p->message_id = error_response_id;
    //     p->flags = 0;
    //     p->magic = 54321;
    //     p->session_token = 0;
    //     error_response response = error_response();
    //     response.response = "Incorrect Password";
    //     response.status = 0;
    //     int packet_size = packet::pack(p, buffer, &response);
    //     vs->write(virtual_fd::CLIENT, buffer, packet_size);
    //     free(raw_msg);
    //     free(buffer);
    //     return;
    // }

    // create client instance
}

void packet_handlers::test_request_handler(server *s, uint8_t *raw_msg, client *user)
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
    user->socket.write(virtual_fd::CLIENT, buf, packet_size);

    return;
}

void packet_handlers::response_handler(server *s, uint8_t *raw_msg, client *user)
{
    return;
}