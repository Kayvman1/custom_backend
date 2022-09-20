#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/packets/packets.h"
#include "../src/packets/packet_ids.h"
#include "../src/ring_buffer/ring_buffer.h"
#include <thread>
#include "../src/ring_buffer/virtual_socket.h"
#include "../src/server/server.h"

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

    msg1->status = 200;
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

    pac1->message_type = 0;
    pac1->message_id = login_request_id;
    pac1->magic = 1;
    pac1->session_token = 1;
    pac1->flags = 4;
    pac1->buf_size = login_request::pack(msg1, buf);

    msg1->username = "username";
    msg1->password = "password";

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

TEST_CASE("RingBufferWrite", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(10);

    for (int i = 1; i < 12; i++)
    {
        uint8_t val = i;
        buf->write(&val, 1);
    }

    REQUIRE(buf->buf[0] == 11);
}

TEST_CASE("RingBufferRead", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(10);

    for (int i = 1; i < 12; i++)
    {
        uint8_t val = i;
        buf->write(&val, 1);
    }

    uint8_t *x = (uint8_t *)buf->read();
    REQUIRE((uint8_t)*x == 11);
}

TEST_CASE("RingBufferUseCaseNoWrap", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(300);
    uint8_t *b = (uint8_t *)malloc(100);
    uint8_t *read = (uint8_t *)malloc(100);
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int len;

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

    len = login_response::pack(msg1, b);
    buf->write(b, len);
    len = login_response::pack(msg2, b);
    buf->write(b, len);
    len = login_response::pack(msg3, b);
    buf->write(b, len);
    len = login_response::pack(msg4, b);
    buf->write(b, len);

    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "1");
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "2");
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "3");
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "4");
}

TEST_CASE("RingBufferUseCaseWithWrap", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(200);
    uint8_t *b = (uint8_t *)malloc(100);
    uint8_t *read = (uint8_t *)malloc(100);
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int len;

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

    len = login_response::pack(msg1, b);
    buf->write(b, len);
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "1");

    len = login_response::pack(msg2, b);
    buf->write(b, len);
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "2");

    len = login_response::pack(msg3, b);
    buf->write(b, len);
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "3");

    len = login_response::pack(msg4, b);
    buf->write(b, len);
    login_response::unpack(ret, (uint8_t *)buf->read());
    REQUIRE(ret->auth_token == "4");
}

int test(ring_buffer *ring_buf, int read_number);
TEST_CASE("RingBufferReadBytesSingleThread", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(400);
    uint8_t *b = (uint8_t *)malloc(100);
    uint8_t *read = (uint8_t *)malloc(100);
    packet *p = new packet;
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int len;

    p->message_id = login_response_id;
    p->message_type = 0;
    p->magic = 123456;
    p->session_token = 1;
    p->flags = 0;
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

    len = packet::pack(p, b, msg1);
    buf->write(b, len);
    len = packet::pack(p, b, msg2);
    buf->write(b, len);
    len = packet::pack(p, b, msg3);
    buf->write(b, len);
    len = packet::pack(p, b, msg4);
    buf->write(b, len);

    test(buf, 1);
    test(buf, 2);
    test(buf, 3);
    test(buf, 4);
}
TEST_CASE("RingBufferReadBytesMultiThread", "[ring_buffer]")
{
    ring_buffer *buf = new ring_buffer(400);
    uint8_t *b = (uint8_t *)malloc(100);
    uint8_t *read = (uint8_t *)malloc(100);
    packet *p = new packet;
    login_response *msg1 = new login_response;
    login_response *msg2 = new login_response;
    login_response *msg3 = new login_response;
    login_response *msg4 = new login_response;
    login_response *ret = new login_response;
    account *user = new account;
    int len;

    p->message_id = login_response_id;
    p->message_type = 0;
    p->magic = 123456;
    p->session_token = 1;
    p->flags = 0;
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

    len = packet::pack(p, b, msg1);
    buf->write(b, len);
    len = packet::pack(p, b, msg2);
    buf->write(b, len);
    len = packet::pack(p, b, msg3);
    buf->write(b, len);
    len = packet::pack(p, b, msg4);
    buf->write(b, len);

    std::thread clientThread1(test, buf, 1);
    std::thread clientThread2(test, buf, 2);
    std::thread clientThread3(test, buf, 3);
    std::thread clientThread4(test, buf, 4);

    clientThread1.join();
    clientThread2.join();
    clientThread3.join();
    clientThread4.join();
}

int test(ring_buffer *ring_buf, int read_number)
{
    packet *unpack = new packet;
    ring_buf->read_bytes(&unpack->message_type, 1);
    ring_buf->read_bytes(&unpack->message_id, 1);
    ring_buf->read_bytes(&unpack->magic, 8);
    ring_buf->read_bytes(&unpack->session_token, 8);
    ring_buf->read_bytes(&unpack->flags, 4);
    ring_buf->read_bytes(&unpack->buf_size, 4);

    std::cout << unpack->buf_size << std::endl;

    uint8_t *team = (uint8_t *)malloc(unpack->buf_size);
    ring_buf->read_bytes(team, unpack->buf_size);

    login_response *msg;
    msg = (login_response *)unpack->message_unpack(team);

    REQUIRE(msg->status == atoi(msg->auth_token.c_str()));
    return 0;
}

TEST_CASE("VirtualSocketServerRead", "[virtualSocket]")
{
    virtual_socket *vs = new virtual_socket();

    uint8_t *buf = (uint8_t *)malloc(100);
    uint32_t val = 55;
    memcpy(buf, &val, sizeof(val));

    vs->write(virtual_fd::SERVER, buf, sizeof(val));

    vs->read(virtual_fd::CLIENT, buf, sizeof(val));

    memcpy(&val, buf, sizeof(val));

    REQUIRE(val == 55);
}

TEST_CASE("VirtualConnection", "[Server]")
{
    server *s = new server();
    virtual_socket *vs = s->new_virtual_connection();
    packet *p = new packet();
    test_request *msg1 = new test_request();
    uint8_t *buf = (uint8_t *)malloc(100);
    int packet_size;

    msg1->val = 5;
    packet_size = packet::pack(p, buf, msg1);

    vs->write(virtual_fd::SERVER, buf, packet_size);
    s->handle_message(vs);
    vs->read(virtual_fd::CLIENT,buf,1);

    uint8_t val;
    memcpy(&val,buf,1);

    std::cout<<val;
    //make s read from vs and then call handle message
}
