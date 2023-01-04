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
#include <optional>
#include <iterator>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
// # include <iostream>
// using namespace sw::redis;

extern sw::redis::Redis *redis;

void packet_handlers::create_user_request_handler(server *s, uint8_t *raw_msg, client *user)
{
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");
    packet *p = new packet;

    uint8_t *buffer = (uint8_t *)malloc(3000);

    create_user_request *message = new create_user_request;
    create_user_request::unpack(message, raw_msg);

    auto redis_response = redis->get("username:" + message->username);

    p->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    p->message_id = CONTROL_PACKET_IDS::create_user_response_id;
    p->flags = 0;
    p->magic = 12345;
    p->session_token = 0;

    create_user_response * response = new create_user_response();
    if (redis_response)
    {
        response->status = control_errors::create_user_failed;
        response->user = new account;
        response->user->username = '\0';
    }

    else
    {
        std::hash<std::string> hasher;
        unsigned char hash_out[64];
        SHA256((const unsigned char *)message->username.c_str(), message->username.length(), hash_out);
        uint64_t *val = (uint64_t *)hash_out;
        auto id = std::to_string(*val);
        std::string key = "user:" + id;
        redis->set("username:" + message->username, id);
        redis->hset(key, "USERNAME", message->username);
        redis->hset(key, "PASSWORD", message->password);

        response->status = 201;
        response->user = new account;
        response->user->username = message->username;
    }

    int packet_size = packet::pack(p, buffer, response);
    //user->socket->write(virtual_fd::CLIENT, buffer, packet_size);
    write(user->socket_fd,buffer,packet_size);
    free(raw_msg);
    free(buffer);
    return;
}

void packet_handlers::login_request_handler(server *s, uint8_t *raw_msg, client *user)
{
    redis = new sw::redis::Redis("tcp://127.0.0.1:6379");

    uint8_t *buffer = (uint8_t *)malloc(3000);
    packet *p = new packet;
    login_request *msg = new login_request;
    login_request::unpack(msg, raw_msg);

    p->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    p->message_id = CONTROL_PACKET_IDS::login_response_id;
    p->flags = 0;
    p->magic = 54321;
    p->session_token = 0;
    login_response *response = new login_response;

    std::optional<std::string> redis_response_id = redis->get("username:" + msg->username);

    // User not found
    if (!redis_response_id)
    {
        response->auth_token = "INVALID";
        response->user = new account;
        response->status = control_errors::user_not_found;
        int packet_size = packet::pack(p, buffer, response);
        //user->socket->write(virtual_fd::CLIENT, buffer, packet_size);
        free(raw_msg);
        free(buffer);
        free(response);
        return;
    }

    std::unordered_map<std::string, std::string> m = {
        {"field1", "val1"},
        {"field2", "val2"}};
    m.clear();

    redis->hgetall("user:" + redis_response_id.value(), std::inserter(m, m.begin()));
    auto password = m.find("PASSWORD");

    // Incorrect password
    if (password->second != msg->password)
    {
        response->auth_token = "INVALID";
        response->user = new account;
        response->status = control_errors::incorrect_password;
    }

    // Valid Login
    else
    {
        response->user = new account;
        response->auth_token = "123123123";
        response->status = 200;
    }

    int packet_size = packet::pack(p, buffer, response);
    write(user->socket_fd, buffer, packet_size);
    free(raw_msg);
    free(buffer);
    free(response);
    return;
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
    write(user->socket_fd, buf, packet_size);

    return;
}

void packet_handlers::response_handler(server *s, uint8_t *raw_msg, client *user)
{
    return;
}