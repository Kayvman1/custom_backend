#include <stdio.h>
#include <functional>
#include <optional>
#include <iterator>
#include <unistd.h>
#include <iostream>

#include <openssl/sha.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sw/redis++/redis++.h>

#include "../accounts/account.h"
#include "../posts/post.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"

#include "server.h"
#include "packet_handlers.h"

extern sw::redis::Redis *redis;

uint64_t generate_token(std::size_t length)
{
    const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

    std::string random_string;

    for (std::size_t i = 0; i < 8; ++i)
    {
        random_string += CHARACTERS[distribution(generator)];
    }

    return (uint64_t)random_string.c_str();
}

void packet_handlers::create_user_request_handler(packet *in, client *user)
{
    packet *out = new packet;
    uint8_t write_buffer[3000];
    create_user_response *response = new create_user_response();
    create_user_request *request = new create_user_request;
    create_user_request::unpack(request, in->payload);

    auto redis_response = redis->get("username:" + request->username);

    out->head->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    out->head->message_id = CONTROL_PACKET_IDS::create_user_response_id;
    out->head->flags = 0;
    out->head->magic = 12345;

    // User already exists
    if (redis_response)
    {
        response->status = control_errors::create_user_failed;
        response->user = new account;
        response->user->username = '\0';

        // TODO this is a point of failure beacause a user might generate a session token of 0
        out->head->session_token = 0;
    }

    else
    {
        std::hash<std::string> hasher;
        unsigned char hash_out[64];
        SHA256((const unsigned char *)request->username.c_str(), request->username.length(), hash_out);
        uint64_t *val = (uint64_t *)hash_out;
        auto id = std::to_string(*val);
        std::string key = "user:" + id;
        redis->set("username:" + request->username, id);
        redis->hset(key, "USERNAME", request->username);
        redis->hset(key, "PASSWORD", request->password);
        int token = generate_token(TOKEN_LEN);

        redis->hset(key, "TOKEN", std::to_string(token));

        account *new_user = new account();
        new_user->username = request->username;
        user->user = new_user;
        user->session_id = token;

        response->status = 201;
        response->user = new_user;
        response->user->username = request->username;
        response->token = token;
        out->head->session_token = token;
    }
    out->payload = (uint8_t *)response;
    int packet_size = packet::pack(out, write_buffer);
    write(user->socket_fd, write_buffer, packet_size);
    return;
}

void packet_handlers::login_request_handler(packet *in, client *user)
{
    uint8_t write_buf[3000];
    packet *out = new packet;
    login_response *response = new login_response;
    login_request *request = new login_request;
    login_request::unpack(request, in->payload);

    out->head->message_type = MESSAGE_TYPE::CONTROL_PACKET;
    out->head->message_id = CONTROL_PACKET_IDS::login_response_id;
    out->head->flags = 0;
    out->head->magic = 54321;

    std::optional<std::string> redis_response_id = redis->get("username:" + request->username);

    // User not found
    if (!redis_response_id)
    {
        response->auth_token = "INVALID";
        response->user = new account;
        response->status = control_errors::user_not_found;
        out->payload = (uint8_t *)response;
        int packet_size = packet::pack(out, write_buf);
        write(user->socket_fd, write_buf, packet_size);
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
    if (password->second != request->password)
    {
        response->auth_token = "INVALID";
        response->user = new account;
        response->status = control_errors::incorrect_password;
    }

    // Valid Login
    else
    {
        int token = generate_token(TOKEN_LEN);

        account *logged_in = new account;
        logged_in->username = request->username;
        user->user = logged_in;
        user->session_id = token;

        response->user = logged_in;
        response->auth_token = token;
        redis->hset("user:" + redis_response_id.value(), "TOKEN", "" + token);
        response->status = 200;
    }

    out->payload = (uint8_t *)response;
    int packet_size = packet::pack(out, write_buf);
    write(user->socket_fd, write_buf, packet_size);
    free(response);
    return;
}

void packet_handlers::test_request_handler(packet *in, client *user)
{
    test_request *request = new test_request();
    test_request::unpack(request, in->payload);
    packet *out = new packet;
    test_response *response = new test_response();
    uint8_t write_buf[3000];

    out->head->message_type = TEST_PACKET;
    out->head->message_id = TEST_PACKET_IDS::test_response_id;
    out->head->session_token = in->head->session_token;

    response->val = request->val;

    out->payload = (uint8_t *)response;
    size_t packet_size = packet::pack(out, write_buf);
    send(user->socket_fd, write_buf, packet_size, MSG_NOSIGNAL);

    free(request);
    free(response);
    return;
}

void packet_handlers::response_handler(packet *in, client *user)
{
    return;
}

void packet_handlers::poem_create_request_handler(packet *in, client *c)
{
    poem_create_request *request = new poem_create_request;
    poem_create_request::unpack(request, in->payload);

    if (in->head->session_token != c->session_id)
    {
        error_response *response = new error_response;
        response->status = 14;

        redis->hdel("user" + c->user->id, "TOKEN");
    }

    else
    {
        std::cout << "LALALA a pretty poem by" << c->user->username << std::endl;
    }
}