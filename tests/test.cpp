#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/packets/packets.h"
#include "../src/packets/packet_ids.h"
#include "../src/ring_buffer/ring_buffer.h"
#include <thread>
#include "../src/server/server.h"
#include <string.h>
#include <functional>

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#include <thread>
#include <chrono>
#include <iostream>

// Helper functions
int read_packet_from_ringbuf(ring_buffer *ring_buf, int read_number, int message_len);

TEST_CASE("SerializeLoginRequest", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(100);
    login_request *msg1 = new login_request;
    login_request *msg2 = new login_request;

    msg1->username = "Hello";
    msg1->password = "World!";

    int size = login_request::pack(msg1, buf);
    login_request::unpack(msg2, buf);

    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
    REQUIRE(msg2->username_length == msg1->username.length());
    REQUIRE(msg2->password_length == msg1->password.length());
    REQUIRE(size == 66);
}

TEST_CASE("SerializeLoginResponse", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(100);
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;

    msg1->status = 201;
    msg1->auth_token = "ABCDEFGHI";
    msg1->user = new account;
    msg1->user->username = "username";

    login_response::pack(msg1, buf);
    login_response::unpack(msg2, buf);

    REQUIRE(msg1->status == msg2->status);
    REQUIRE(msg1->auth_token == msg2->auth_token);
    REQUIRE(msg2->auth_token_length == msg1->auth_token.length());
    REQUIRE(msg1->user->username == msg2->user->username);
}

TEST_CASE("SerializeRefreshRequest", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(100);
    refresh_token_request *msg1 = new refresh_token_request;
    refresh_token_request *msg2 = new refresh_token_request;

    msg1->refresh_token = "refresh_token";

    refresh_token_request::pack(msg1, buf);
    refresh_token_request::unpack(msg2, buf);

    REQUIRE(msg1->refresh_token == msg2->refresh_token);
    REQUIRE(msg2->refresh_token_length == msg1->refresh_token.length());
}

TEST_CASE("SerializeRefreshResponse", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(100);
    refresh_token_response *msg1 = new refresh_token_response;
    refresh_token_response *msg2 = new refresh_token_response;

    msg1->status = 200;
    msg1->auth_token = "AUTH_TOKEN";

    refresh_token_response::pack(msg1, buf);
    refresh_token_response::unpack(msg2, buf);

    REQUIRE(msg1->status == msg2->status);
    REQUIRE(msg1->auth_token == msg2->auth_token);
    REQUIRE(msg2->auth_token_length == msg1->auth_token.length());
}

TEST_CASE("SerializeCreateUserRequest", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(1000);
    create_user_request *msg1 = new create_user_request;
    create_user_request *msg2 = new create_user_request;

    msg1->username = "username";
    msg1->password = "password";
    msg1->email = "emial@email.com";

    create_user_request::pack(msg1, buf);
    create_user_request::unpack(msg2, buf);

    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
    REQUIRE(msg1->email == msg2->email);
}

TEST_CASE("SerializeCreateUserResponse", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(1000);
    create_user_response *msg1 = new create_user_response;
    create_user_response *msg2 = new create_user_response;

    msg1->status = 200;
    msg1->user = new account;
    msg1->user->username = "username";

    create_user_response::pack(msg1, buf);
    create_user_response::unpack(msg2, buf);

    REQUIRE(msg1->status == msg2->status);
    REQUIRE(msg1->user->username == msg2->user->username);
}

///////////////POEMS\\\\\\\\\\\\\\\\\\\\\\\\\

// TEST_CASE("SerializePoemCreateRequest", "[serialize]")
// {
//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_create_request *msg1 = new poem_create_request;
//     poem_create_request *msg2 = new poem_create_request;

//     msg1->auth_token = "Auth_TOKEN";
//     msg1->user = new account;

//     poem_create_request::pack(msg1, buf);
//     poem_create_request::unpack(msg2, buf);

//     REQUIRE(msg1->auth_token == msg2->auth_token);
// }

// TEST_CASE("SerializePoemCreateResponse", "[serialize]")
// {
//     poem_create_response *msg1 = new poem_create_response;
//     poem_create_response *msg2 = new poem_create_response;
//     uint8_t *buf = (uint8_t *)malloc(1000);

//     msg1->status = 200;

//     poem_create_response::pack(msg1, buf);
//     poem_create_response::unpack(msg2, buf);

//     REQUIRE(msg1->status == msg2->status);
// }

// TEST_CASE("SerializePoemFeedRequest", "[serialize]")
// {
//     poem_feed_request *msg1 = new poem_feed_request;
//     msg1->auth_token = "Auth_TOKEN";

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_feed_request *msg2 = new poem_feed_request;

//     poem_feed_request::pack(msg1, buf);
//     poem_feed_request::unpack(msg2, buf);

//     REQUIRE(msg1->auth_token == msg2->auth_token);
// }

// TEST_CASE("SerializePoemFeedResponse", "[serialize]")
// {
//     poem_feed_response *msg1 = new poem_feed_response;
//     msg1->status = 200;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_feed_response *msg2 = new poem_feed_response;

//     poem_feed_response::pack(msg1, buf);
//     poem_feed_response::unpack(msg2, buf);

//     REQUIRE(msg1->status == msg2->status);
// }

// TEST_CASE("SerializePoemDetailRequest", "[serialize]")
// {
//     poem_detail_view_request *msg1 = new poem_detail_view_request;
//     msg1->auth_token = "AUTH_TOKEN";

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_detail_view_request *msg2 = new poem_detail_view_request;

//     poem_detail_view_request::pack(msg1, buf);
//     poem_detail_view_request::unpack(msg2, buf);

//     REQUIRE(msg1->auth_token == msg2->auth_token);
// }

// TEST_CASE("SerializePoemDetailResponse", "[serialize]")
// {
//     poem_detail_view_response *msg1 = new poem_detail_view_response;
//     msg1->status = 400;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_detail_view_response *msg2 = new poem_detail_view_response;

//     poem_detail_view_response::pack(msg1, buf);
//     poem_detail_view_response::unpack(msg2, buf);

//     REQUIRE(msg1->status == msg2->status);
// }

// TEST_CASE("SerializePoemDeleteRequest", "[serialize]")
// {
//     poem_delete_request *msg1 = new poem_delete_request;
//     msg1->auth_token = "AUTH TOKEN";

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_delete_request *msg2 = new poem_delete_request;

//     poem_delete_request::pack(msg1, buf);
//     poem_delete_request::unpack(msg2, buf);

//     REQUIRE(msg1->auth_token == msg2->auth_token);
// }

// TEST_CASE("SerializePoemDeleteResponse", "[serialize]")
// {
//     poem_delete_response *msg1 = new poem_delete_response;
//     msg1->status = 200;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_delete_response *msg2 = new poem_delete_response;

//     poem_delete_response::pack(msg1, buf);
//     poem_delete_response::unpack(msg2, buf);

//     REQUIRE(msg1->status == msg2->status);
// }

// TEST_CASE("SerializePoemActionRequest", "[serialize]")
// {
//     poem_interaction_request *msg1 = new poem_interaction_request;
//     msg1->auth_token = "AUTH_TOKEN";
//     msg1->action = 1;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_interaction_request *msg2 = new poem_interaction_request;

//     poem_interaction_request::pack(msg1, buf);
//     poem_interaction_request::unpack(msg2, buf);

//     REQUIRE(msg1->action == msg2->action);
//     REQUIRE(msg1->auth_token == msg2->auth_token);
// }
// TEST_CASE("SerializePoemActionResponse", "[serialize]")
// {
//     poem_interaction_response *msg1 = new poem_interaction_response;
//     msg1->status = 200;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem_interaction_response *msg2 = new poem_interaction_response;

//     poem_interaction_response::pack(msg1, buf);
//     poem_interaction_response::unpack(msg2, buf);

//     REQUIRE(msg1->status == msg2->status);
// }

// TEST_CASE("SerializePoem", "[serialize]")
// {
//     poem *msg1 = new poem;
//     msg1->author = new account();
//     msg1->author->username = "Username";
//     msg1->content = "content";
//     msg1->title = "title";
//     msg1->poem_id = 1;

//     uint8_t *buf = (uint8_t *)malloc(1000);
//     poem *msg2 = new poem;

//     poem::pack(msg1, buf);
//     poem::unpack(msg2, buf);

//     INFO(msg1->author->username);

//     REQUIRE(msg1->content == msg2->content);
//     REQUIRE(msg1->title == msg2->title);
//     REQUIRE(msg1->poem_id == msg2->poem_id);
//     REQUIRE(msg1->author->username == msg2->author->username);
// }

TEST_CASE("SerializeAccount", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(100);
    account *user1 = new account;
    account *user2 = new account;

    user1->username = "username";

    account::pack(user1, buf);
    account::unpack(user2, buf);

    REQUIRE(user1->username == user2->username);
}

TEST_CASE("SerializePacket", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(1000);
    packet *pac1 = new packet;
    packet *pac2 = new packet;
    login_request *msg1 = new login_request;
    login_request *msg2 = new login_request;

    msg1->username = "username";
    msg1->password = "password";

    pac1->message_type = CONTROL_PACKET;
    pac1->message_id = login_request_id;
    pac1->magic = 1;
    pac1->session_token = 1;
    pac1->flags = 4;

    packet::pack(pac1, buf, msg1);
    msg2 = (login_request *)packet::unpack(pac2, buf);

    // TODO CANT COMPARE MESGAGES BECAUSE DESERIALZED message arent returned
    REQUIRE(pac1->message_type == pac2->message_type);
    REQUIRE(pac1->message_id == pac2->message_id);
    REQUIRE(pac1->magic == pac2->magic);
    REQUIRE(pac1->session_token == pac2->session_token);
    REQUIRE(pac1->flags == pac2->flags);
    REQUIRE(pac1->buf_size == pac2->buf_size);
    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
}

///////////Ring Buffer \\\\\\\\\\\\\

TEST_CASE("RingBufferWrite", "[ring_buffer]")
{
    ring_buffer *ring_buf = new ring_buffer(10);

    for (int i = 1; i < 12; i++)
    {
        uint8_t val = i;
        ring_buf->write(&val, 1);
    }

    REQUIRE(ring_buf->buf[0] == 11);
}

TEST_CASE("RingBufferRead", "[ring_buffer]")
{
    ring_buffer *ring_buf = new ring_buffer(10);

    uint8_t write_val;
    for (int i = 1; i <= 11; i++)
    {
        write_val = i;
        ring_buf->write(&write_val, 1);
    }

    uint8_t read_val;

    ring_buf->read(1, &read_val);
    REQUIRE(read_val == 11);

    for (int i = 2; i <= 11; i++)
    {

        ring_buf->read(1, &read_val);
        REQUIRE(read_val == i);
    }
}

TEST_CASE("RingBufferUseCaseNoWrap", "[ring_buffer]")
{
    ring_buffer *ring_buf = new ring_buffer(300);
    uint8_t *in_buf = (uint8_t *)malloc(100);
    uint8_t *out_buf = (uint8_t *)malloc(100);

    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int message_len;

    user->username = "username";
    msg1->status = 1;
    msg1->auth_token = "1";
    msg1->user = user;
    msg2->status = 2;
    msg2->auth_token = "2";
    msg2->user = user;
    msg3->status = 3;
    msg3->auth_token = "3";
    msg3->user = user;
    msg4->status = 4;
    msg4->auth_token = "4";
    msg4->user = user;

    // All messages being written are the same length
    message_len = login_response::pack(msg1, in_buf);
    ring_buf->write(in_buf, message_len);
    login_response::pack(msg2, in_buf);
    ring_buf->write(in_buf, message_len);
    login_response::pack(msg3, in_buf);
    ring_buf->write(in_buf, message_len);
    login_response::pack(msg4, in_buf);
    ring_buf->write(in_buf, message_len);

    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "1");

    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "2");

    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "3");

    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "4");
}

TEST_CASE("RingBufferUseCaseWithWrap", "[ring_buffer]")
{
    // The messages in this test are 35 bytes, so it does wrap

    ring_buffer *ring_buf = new ring_buffer(100);
    uint8_t *in_buf = (uint8_t *)malloc(100);
    uint8_t *out_buf = (uint8_t *)malloc(100);

    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int message_len;

    user->username = "username";
    msg1->status = 1;
    msg1->auth_token = "1";
    msg1->user = user;
    msg2->status = 2;
    msg2->auth_token = "2";
    msg2->user = user;
    msg3->status = 3;
    msg3->auth_token = "3";
    msg3->user = user;
    msg4->status = 4;
    msg4->auth_token = "4";
    msg4->user = user;

    message_len = login_response::pack(msg1, in_buf);
    ring_buf->write(in_buf, message_len);
    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "1");

    message_len = login_response::pack(msg2, in_buf);
    ring_buf->write(in_buf, message_len);
    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "2");

    message_len = login_response::pack(msg3, in_buf);
    ring_buf->write(in_buf, message_len);
    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "3");

    message_len = login_response::pack(msg4, in_buf);
    ring_buf->write(in_buf, message_len);
    ring_buf->read(message_len, out_buf);
    login_response::unpack(ret, out_buf);
    REQUIRE(ret->auth_token == "4");
}

TEST_CASE("RingBufferReadBytesSingleThread", "[ring_buffer]")
{
    ring_buffer *ring_buf = new ring_buffer(400);
    uint8_t *in_buf = (uint8_t *)malloc(100);
    uint8_t *read = (uint8_t *)malloc(100);

    packet *pac = new packet;
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int message_len;

    pac->message_id = login_response_id;
    pac->message_type = 0;
    pac->magic = 123456;
    pac->session_token = 1;
    pac->flags = 0;
    user->username = "username";
    msg1->status = 1;
    msg1->auth_token = "1";
    msg1->user = user;
    msg2->status = 2;
    msg2->auth_token = "2";
    msg2->user = user;
    msg3->status = 3;
    msg3->auth_token = "3";
    msg3->user = user;
    msg4->status = 4;
    msg4->auth_token = "4";
    msg4->user = user;

    message_len = packet::pack(pac, in_buf, msg1);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg2);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg3);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg4);
    ring_buf->write(in_buf, message_len);

    read_packet_from_ringbuf(ring_buf, 1, message_len);
    read_packet_from_ringbuf(ring_buf, 2, message_len);
    read_packet_from_ringbuf(ring_buf, 3, message_len);
    read_packet_from_ringbuf(ring_buf, 4, message_len);
}

TEST_CASE("RingBufferReadBytesMultiThread", "[ring_buffer]")
{
    ring_buffer *ring_buf = new ring_buffer(400);
    uint8_t *in_buf = (uint8_t *)malloc(100);

    packet *pac = new packet;
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int message_len;

    pac->message_id = login_response_id;
    pac->message_type = 0;
    pac->magic = 123456;
    pac->session_token = 1;
    pac->flags = 0;
    user->username = "username";
    msg1->status = 1;
    msg1->auth_token = "1";
    msg1->user = user;
    msg2->status = 2;
    msg2->auth_token = "2";
    msg2->user = user;
    msg3->status = 3;
    msg3->auth_token = "3";
    msg3->user = user;
    msg4->status = 4;
    msg4->auth_token = "4";
    msg4->user = user;

    message_len = packet::pack(pac, in_buf, msg1);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg2);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg3);
    ring_buf->write(in_buf, message_len);
    message_len = packet::pack(pac, in_buf, msg4);
    ring_buf->write(in_buf, message_len);

    std::thread clientThread1(read_packet_from_ringbuf, ring_buf, 1, message_len);
    std::thread clientThread2(read_packet_from_ringbuf, ring_buf, 2, message_len);
    std::thread clientThread3(read_packet_from_ringbuf, ring_buf, 3, message_len);
    std::thread clientThread4(read_packet_from_ringbuf, ring_buf, 4, message_len);

    // TODO not sure how thread safe this actually is on scale
    clientThread1.join();
    clientThread2.join();
    clientThread3.join();
    clientThread4.join();
}

int read_packet_from_ringbuf(ring_buffer *ring_buf, int read_number, int message_len)
{

    packet *unpack = new packet;

    uint8_t *out_buf = (uint8_t *)malloc(100);
    ring_buf->read(message_len, out_buf);

    login_response *msg;

    msg = (login_response *)packet::unpack(unpack, out_buf);

    REQUIRE(unpack->message_id == login_response_id);
    REQUIRE(msg->status == atoi(msg->auth_token.c_str()));
    return 0;
}

// //////////////// SERVER \\\\\\\\\\\\\\\\\\\

// void start_server(int port)
// {
//     server *s = new server();
//     s->start(port);
// }

// int create_socket(int server_port)
// {
//     // using namespace std::chrono_literals;

//     int sock = 0;
//     long valread;
//     struct sockaddr_in serv_addr;
//     char *hello = "Hello from client";
//     // char buffer[1024] = {0};
//     if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//     {
//         printf("\n Socket creation error \n");
//         return -1;
//     }

//     memset(&serv_addr, '0', sizeof(serv_addr));

//     serv_addr.sin_family = AF_INET;

//     serv_addr.sin_port = htons(server_port);

//     // Convert IPv4 and IPv6 addresses from text to binary form
//     // if (inet_pton(AF_INET, "192.168.1.177", &serv_addr.sin_addr) <= 0)
//     // if (inet_pton(AF_INET, "108.48.69.131", &serv_addr.sin_addr) <= 0)
//     if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
//     {
//         printf("\nInvalid address/ Address not supported \n");
//         return -1;
//     }

//     if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
//     {
//         printf("\nConnection Failed \n");
//         return -1;
//     }
//     return sock;
// }

// int sock;
// TEST_CASE("Test Message", "[Server]")
// {
//     // std::thread serverThread(start_server, 8080);

//     // int x1;
//     // std::cout << "Enter Server Port ";
//     // std::cin >> x1;
//     sock = create_socket(47479);

//     packet *p = new packet();
//     test_request *msg1 = new test_request();
//     uint8_t *buf = (uint8_t *)malloc(100);
//     int packet_size;

//     p->message_type = TEST_PACKET;
//     msg1->val = 5;
//     p->message_id = TEST_PACKET_IDS::test_request_id;

//     packet_size = packet::pack(p, buf, msg1);

//     write(sock, buf, packet_size);

//     uint8_t message_buffer[3000];
//     packet *unpack = new packet;
//     long val_read;
//     read(sock, &unpack->message_type, sizeof(packet::message_type));
//     read(sock, &unpack->message_id, sizeof(packet::message_id));
//     read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     read(sock, message_buffer, unpack->buf_size);

//     test_response *x = new test_response();
//     x = (test_response *)unpack->message_unpack(message_buffer);

//     REQUIRE(x->val == 5);
// }

// TEST_CASE("TestMessage with one delayed byte", "[Server]")
// {
//     packet *p = new packet();
//     test_request *msg1 = new test_request();
//     uint8_t *buf = (uint8_t *)malloc(100);
//     int packet_size;

//     p->message_type = TEST_PACKET;
//     msg1->val = 5;
//     p->message_id = TEST_PACKET_IDS::test_request_id;

//     packet_size = packet::pack(p, buf, msg1);

//     write(sock, buf, packet_size - 1);
//     sleep(1);
//     write(sock, buf + packet_size - 1, 1);

//     uint8_t message_buffer[3000];
//     packet *unpack = new packet;
//     long val_read;
//     read(sock, &unpack->message_type, sizeof(packet::message_type));
//     read(sock, &unpack->message_id, sizeof(packet::message_id));
//     read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     read(sock, message_buffer, unpack->buf_size);

//     test_response *x = new test_response();
//     x = (test_response *)unpack->message_unpack(message_buffer);

//     REQUIRE(x->val == 5);
//     // make s read from vs and then call handle message
// }

// TEST_CASE("Test Message with split packet", "[Server]")
// {
//     packet *p = new packet();
//     test_request *msg1 = new test_request();
//     uint8_t *buf = (uint8_t *)malloc(100);
//     int packet_size;

//     p->message_type = TEST_PACKET;
//     msg1->val = 5;
//     p->message_id = TEST_PACKET_IDS::test_request_id;
//     p->session_token = 54321;
//     test_request::pack(msg1, buf);

//     uint32_t si = 1;

//     write(sock, &p->message_type, sizeof(packet::message_type));
//     write(sock, &p->message_id, sizeof(packet::message_id));
//     write(sock, (uint8_t *)&p->magic, sizeof(packet::magic));
//     write(sock, (uint8_t *)&p->session_token, sizeof(packet::session_token) / 2);

//     for (int i = 1; i < 3; i++)
//     {
//         sleep(1);
//     }

//     write(sock, (uint8_t *)&p->session_token + 4, sizeof(packet::session_token) / 2);
//     write(sock, (uint8_t *)&p->flags, sizeof(packet::flags));
//     write(sock, (uint8_t *)&si, sizeof(packet::buf_size));
//     write(sock, buf, si);

//     uint8_t message_buffer[3000];
//     packet *unpack = new packet;
//     long val_read;
//     read(sock, &unpack->message_type, sizeof(packet::message_type));
//     read(sock, &unpack->message_id, sizeof(packet::message_id));
//     read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     read(sock, message_buffer, unpack->buf_size);

//     test_response *x = new test_response();
//     x = (test_response *)unpack->message_unpack(message_buffer);

//     REQUIRE(x->val == 5);
//     REQUIRE(unpack->session_token == 54321);
//     // make s read from vs and then call handle message
// }

// TEST_CASE("Test Message one byte sent at a time", "[Server]")
// {
//     packet *p = new packet();
//     test_request *msg1 = new test_request();
//     uint8_t *buf = (uint8_t *)malloc(100);
//     int packet_size;

//     p->message_type = TEST_PACKET;
//     msg1->val = 5;
//     p->message_id = TEST_PACKET_IDS::test_request_id;

//     packet_size = packet::pack(p, buf, msg1);

//     for (int i = 0; i < packet_size; i++)
//     {
//         write(sock, buf + i, 1);
//         usleep(10000);
//     }

//     uint8_t message_buffer[3000];
//     packet *unpack = new packet;
//     long val_read;
//     read(sock, &unpack->message_type, sizeof(packet::message_type));
//     read(sock, &unpack->message_id, sizeof(packet::message_id));
//     read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     read(sock, message_buffer, unpack->buf_size);

//     test_response *x = new test_response();
//     x = (test_response *)unpack->message_unpack(message_buffer);

//     REQUIRE(x->val == 5);

//     // make s read from vs and then call handle message
// }

// TEST_CASE("Invalid Login", "[Infrastructure]")
// {
//     uint8_t *buf = (uint8_t *)malloc(1000);
//     login_request *req = new login_request();
//     req->username = "abcds";
//     req->password = "password";
//     packet *outgoing = new packet;
//     outgoing->message_type = CONTROL_PACKET;
//     outgoing->message_id = login_request_id;
//     outgoing->magic = 1;
//     outgoing->session_token = 1;
//     outgoing->flags = 1;

//     int packet_size = packet::pack(outgoing, buf, req);

//     packet *unpack = new packet;

//     uint8_t message_buffer[1000];
//     write(sock, buf, packet_size);
//     int val_read;
//     val_read = read(sock, &unpack->message_type, sizeof(packet::message_type));
//     val_read = read(sock, &unpack->message_id, sizeof(packet::message_id));

//     val_read = read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     val_read = read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     val_read = read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     val_read = read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     val_read = read(sock, message_buffer, unpack->buf_size);

//     login_response *resp = (login_response *)unpack->message_unpack(message_buffer);
//     REQUIRE(resp->auth_token == "INVALID");
//     REQUIRE(resp->status == control_errors::user_not_found);

//     // std::cout << unpack->magic << std::endl;
// }
// std::string random_string(std::size_t length)
// {
//     const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

//     std::random_device random_device;
//     std::mt19937 generator(random_device());
//     std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

//     std::string random_string;

//     for (std::size_t i = 0; i < length; ++i)
//     {
//         random_string += CHARACTERS[distribution(generator)];
//     }

//     return random_string;
// }
// TEST_CASE("Test Create New User", "[USER]")
// {
//     uint8_t *buf = (uint8_t *)malloc(1000);
//     create_user_request *req = new create_user_request;
//     req->email = "test user*";
//     req->username = random_string(25);
//     req->password = "password";
//     packet *outgoing = new packet;
//     outgoing->message_type = CONTROL_PACKET;
//     outgoing->message_id = create_user_request_id;
//     packet *unpack = new packet;

//     int packet_size = packet::pack(outgoing, buf, req);

//     int val_read;

//     uint8_t message_buffer[3000];

//     write(sock, buf, packet_size);

//     val_read = read(sock, &unpack->message_type, sizeof(packet::message_type));
//     val_read = read(sock, &unpack->message_id, sizeof(packet::message_id));

//     val_read = read(sock, (uint8_t *)&unpack->magic, sizeof(packet::magic));
//     val_read = read(sock, (uint8_t *)&unpack->session_token, sizeof(packet::session_token));
//     val_read = read(sock, (uint8_t *)&unpack->flags, sizeof(packet::flags));
//     val_read = read(sock, (uint8_t *)&unpack->buf_size, sizeof(packet::buf_size));
//     val_read = read(sock, message_buffer, unpack->buf_size);

//     create_user_response *resp = (create_user_response *)unpack->message_unpack(message_buffer);

//     REQUIRE(resp->status == 201);
// }

// TEST_CASE("Test malformed message - Too Short", "[Networking]")
// {
//     uint8_t *buf = (uint8_t *)malloc(1000);
//     create_user_request *req = new create_user_request;
//     req->email = "test user*";
//     req->username = random_string(25);
//     req->password = "password";
//     packet *outgoing = new packet;
//     outgoing->message_type = CONTROL_PACKET;
//     outgoing->message_id = create_user_request_id;
//     packet *unpack = new packet;

//     uint32_t fake = 555;

//     int packet_size = packet::pack(outgoing, buf, req);

//     std::memcpy(buf + 22, &fake, sizeof(uint32_t));

//     int val_read;

//     uint8_t message_buffer[3000];

//     write(sock, buf, packet_size);

//     val_read = read(sock, &unpack->message_type, sizeof(packet::message_type));
// }

// TEST_CASE("CLEANUP", "[ADMIN]")
// {
//     shutdown(sock, SHUT_RDWR);
//     close(sock);
// }