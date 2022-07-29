#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/packets/packets.h"

TEST_CASE("SerializeLoginRequest", "[serialize]")
{
    login_request *msg1 = new login_request;
    msg1->username = "Hello";
    msg1->password = "World!";

    uint8_t *buf = (uint8_t *)malloc(100);
    login_request *msg2 = new login_request;

    login_request::pack(msg1, buf);
    login_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
}

TEST_CASE("SerializeLoginResponse", "[serialize]")
{
    login_response *msg1 = new login_response;
    msg1->status = 200;
    msg1->auth_token = "ABCDEFGHI";

    uint8_t *buf = (uint8_t *)malloc(100);
    login_response *msg2 = new login_response;

    login_response::pack(msg1, buf);
    login_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializeRefreshRequest", "[serialize]")
{
    refresh_token_request *msg1 = new refresh_token_request;
    msg1->csrf_token = "csrf_token";
    msg1->refresh_token = "refresh_token";

    uint8_t *buf = (uint8_t *)malloc(100);
    refresh_token_request *msg2 = new refresh_token_request;

    refresh_token_request::pack(msg1, buf);
    refresh_token_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->csrf_token == msg2->csrf_token);
    REQUIRE(msg1->refresh_token == msg2->refresh_token);
}

TEST_CASE("SeralizeRefreshResponse")
{
    refresh_token_response *msg1 = new refresh_token_response;
    msg1->auth_token = "AUTH_TOKEN";
    uint8_t *buf = (uint8_t *)malloc(100);
    refresh_token_response *msg2 = new refresh_token_response;

    refresh_token_response::pack(msg1, buf);
    refresh_token_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializeCreateUserRequest", "[serialize]")
{
    create_user_request *msg1 = new create_user_request;
    msg1->username = "username";
    msg1->password = "password";
    msg1->email = "emial@email.com";

    uint8_t *buf = (uint8_t *)malloc(1000);
    create_user_request *msg2 = new create_user_request;

    create_user_request::pack(msg1, buf);
    create_user_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
    REQUIRE(msg1->email == msg2->email);
}

TEST_CASE("SerializeCreateUserResponse", "[serialize]")
{
    create_user_response *msg1 = new create_user_response;
    msg1->status = 200;

    uint8_t *buf = (uint8_t *)malloc(1000);
    create_user_response *msg2 = new create_user_response;

    create_user_response::pack(msg1, buf);
    create_user_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

///////////////POEMS\\\\\\\\\\\\\\\\\\\\\\\\\

TEST_CASE("SerializePoemCreateRequest", "[serialize]")
{
    poem_create_request *msg1 = new poem_create_request;
    msg1->auth_token = "Auth_TOKEN";

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_create_request *msg2 = new poem_create_request;

    poem_create_request::pack(msg1, buf);
    poem_create_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializePoemCreateResponse", "[serialize]")
{
    poem_create_response *msg1 = new poem_create_response;
    msg1->status = 200;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_create_response *msg2 = new poem_create_response;

    poem_create_response::pack(msg1, buf);
    poem_create_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

TEST_CASE("SerializePoemFeedRequest", "[serialize]")
{
    poem_feed_request *msg1 = new poem_feed_request;
    msg1->auth_token = "Auth_TOKEN";

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_feed_request *msg2 = new poem_feed_request;

    poem_feed_request::pack(msg1, buf);
    poem_feed_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializePoemFeedResponse", "[serialize]")
{
    poem_feed_response *msg1 = new poem_feed_response;
    msg1->status = 200;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_feed_response *msg2 = new poem_feed_response;

    poem_feed_response::pack(msg1, buf);
    poem_feed_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

TEST_CASE("SerializePoemDetailRequest", "[serialize]")
{
    poem_detail_view_request *msg1 = new poem_detail_view_request;
    msg1->auth_token = "AUTH_TOKEN";

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_detail_view_request *msg2 = new poem_detail_view_request;

    poem_detail_view_request::pack(msg1, buf);
    poem_detail_view_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializePoemDetailResponse", "[serialize]")
{
    poem_detail_view_response *msg1 = new poem_detail_view_response;
    msg1->status = 400;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_detail_view_response *msg2 = new poem_detail_view_response;

    poem_detail_view_response::pack(msg1, buf);
    poem_detail_view_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

TEST_CASE("SerializePoemDeleteRequest", "[serialize]")
{
    poem_delete_request *msg1 = new poem_delete_request;
    msg1->auth_token = "AUTH TOKEN";

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_delete_request *msg2 = new poem_delete_request;

    poem_delete_request::pack(msg1, buf);
    poem_delete_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}

TEST_CASE("SerializePoemDeleteResponse", "[serialize]")
{
    poem_delete_response *msg1 = new poem_delete_response;
    msg1->status = 200;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_delete_response *msg2 = new poem_delete_response;

    poem_delete_response::pack(msg1, buf);
    poem_delete_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

TEST_CASE("SerializePoemActionRequest", "[serialize]")
{
    poem_interaction_request *msg1 = new poem_interaction_request;
    msg1->auth_token = "AUTH_TOKEN";
    msg1->action = 1;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_interaction_request *msg2 = new poem_interaction_request;

    poem_interaction_request::pack(msg1, buf);
    poem_interaction_request::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->action == msg2->action);
    REQUIRE(msg1->auth_token == msg2->auth_token);
}
TEST_CASE("SerializePoemActionResponse", "[serialize]")
{
    poem_interaction_response *msg1 = new poem_interaction_response;
    msg1->status = 200;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem_interaction_response *msg2 = new poem_interaction_response;

    poem_interaction_response::pack(msg1, buf);
    poem_interaction_response::unpack(msg2, buf + 1);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);
}

// WHERE DOES THIS GO

TEST_CASE("SerializeUser", "[serialize]")
{
    user *msg1 = new user;
    msg1->username = "username";

    uint8_t *buf = (uint8_t *)malloc(1000);
    user *msg2 = new user;

    user::pack(msg1, buf);
    user::unpack(msg2, buf);

    REQUIRE(msg1->username == msg2->username);
}

TEST_CASE("SerializePoem", "[serialize]")
{
    poem *msg1 = new poem;
    msg1->author = user();
    msg1->author.username = "Username";
    msg1->content = "content";
    msg1->title = "title";
    msg1->poem_id = 1;

    uint8_t *buf = (uint8_t *)malloc(1000);
    poem *msg2 = new poem;

    poem::pack(msg1, buf);
    poem::unpack(msg2, buf);

    INFO(msg1->author.username);

    REQUIRE(msg1->content == msg2->content);
    REQUIRE(msg1->title == msg2->title);
    REQUIRE(msg1->poem_id == msg2->poem_id);
    REQUIRE(msg1->author.username == msg2->author.username);
}

TEST_CASE("SerializePacket", "[serialize]")
{
    uint8_t *buf = (uint8_t *)malloc(1000);

    packet *pac1 = new packet;
    pac1->message_type = 0;
    pac1->message_id = 5;
    pac1->magic = 1;
    pac1->session_token = 1;
    pac1->flags = 4;


    poem_interaction_response *msg1 = new poem_interaction_response;
    msg1->status = 200;

    packet::pack(pac1, buf, msg1);

    poem_interaction_response *msg2 = new poem_interaction_response;
    packet *pac2 = new packet;

    packet::unpack(pac2,buf,(void *)msg2);

    INFO((int)msg1->status);
    INFO((int)msg2->status);
    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->status == msg2->status);

    REQUIRE(pac1->message_type == pac2->message_type);
    REQUIRE(pac1->message_id == pac2->message_id);
    REQUIRE(pac1->magic == pac2->magic);
    REQUIRE(pac1->session_token == pac2->session_token);
    REQUIRE(pac1->flags == pac2->flags);
}