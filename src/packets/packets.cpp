#include <iostream>
#include <string>
#include <cstring>
#include "packets.h"
#include <catch2/catch_test_macros.hpp>

// login request
// CAN I MAKE THIS A UINT 8 BUF SO I CAN INCREMENT

// CONSUME FIRST BYTE OF PACKED BUFFER
void login_request::pack(login_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);
    // Should this be type aliased

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index = index + sizeof(username_length);

    std::strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index = index + USERNAME_LEN + 1;

    std::memcpy(buf + index, &password_length, sizeof(password_length));
    index = index + sizeof(password_length);

    std::strncpy((char *)buf + index, msg->password.c_str(), PASSWORD_LEN) + 1;

    return;
}
void login_request::unpack(login_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t username_length;
    uint8_t password_length;

    std::memcpy(&username_length, buf + index, sizeof(username_length));
    index = index + sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index = index + USERNAME_LEN + 1;

    std::memcpy((&password_length), buf + index, sizeof(password_length));
    index = index + sizeof(password_length);

    msg->password = std::string((char *)buf + index);

    return;
}

void login_response::pack(login_response *msg, uint8_t *buf)
{
    // TODO add user class serialization
    int index = 0;
    uint8_t token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(buf + index, &token_length, sizeof(token_length));
    index = index + sizeof(token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
}

void login_response::unpack(login_response *msg, uint8_t *buf)
{
    // TODO add user class deserialization
    int index = 0;
    uint8_t token_length;

    std::memcpy(&(msg->status), buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(&token_length, buf + index, sizeof(token_length));
    index = index + sizeof(token_length);

    msg->auth_token = std::string((char *)buf + index);
    index = index + TOKEN_LEN + 1;
}

void refresh_token_request::pack(refresh_token_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t refresh_token_length = msg->refresh_token.length();
    uint8_t csrf_token_length = msg->csrf_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &refresh_token_length, sizeof(refresh_token_length));
    index = index + sizeof(refresh_token_length);

    strncpy((char *)buf + index, msg->refresh_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    std::memcpy(buf + index, &csrf_token_length, sizeof(csrf_token_length));
    index = index + sizeof(csrf_token_length);

    strncpy((char *)buf + index, msg->csrf_token.c_str(), TOKEN_LEN + 1);
}
void refresh_token_request::unpack(refresh_token_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t refresh_token_length;
    uint8_t csrf_token_length;

    std::memcpy(&refresh_token_length, buf + index, sizeof(refresh_token_length));
    index = index + sizeof(refresh_token_length);

    msg->refresh_token = std::string((char *)buf + index);
    index += TOKEN_LEN + 1;

    std::memcpy(&csrf_token_length, buf + index, sizeof(csrf_token_length));
    index = index + sizeof(csrf_token_length);

    msg->csrf_token = std::string((char *)buf + index);
}

void refresh_token_response::pack(refresh_token_response *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;
}

void refresh_token_response::unpack(refresh_token_response *msg, uint8_t *buf)

{
    int index = 0;
    uint8_t auth_token_length;
    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
    index += TOKEN_LEN + 1;
}

void create_user_request::pack(create_user_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();
    uint8_t email_length = msg->email.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index = index + sizeof(username_length);

    strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index += USERNAME_LEN + 1;

    std::memcpy(buf + index, &password_length, sizeof(password_length));
    index = index + sizeof(password_length);

    strncpy((char *)buf + index, msg->password.c_str(), PASSWORD_LEN + 1);
    index += PASSWORD_LEN + 1;

    std::memcpy(buf + index, &email_length, sizeof(email_length));
    index = index + sizeof(email_length);

    strncpy((char *)buf + index, msg->email.c_str(), EMAIL_LEN + 1);
}

void create_user_request::unpack(create_user_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t username_length;
    uint8_t password_length;
    uint8_t email_length;

    std::memcpy(&username_length, buf + index, sizeof(username_length));
    index = index + sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index += USERNAME_LEN + 1;

    std::memcpy(&password_length, buf + index, sizeof(password_length));
    index = index + sizeof(password_length);

    msg->password = std::string((char *)buf + index);
    index += PASSWORD_LEN + 1;

    std::memcpy(&email_length, buf + index, sizeof(email_length));
    index = index + sizeof(email_length);

    msg->email = std::string((char *)buf + index);
}
void create_user_response::pack(create_user_response *msg, uint8_t *buf)
{
    // TODO add user class deserialization
    int index = 0;
    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);
    // ADD USER STUFF
    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
}

void create_user_response::unpack(create_user_response *msg, uint8_t *buf)
{
    // TODO add user class deserialization
    int index = 0;
    // ADD CLASS STUFF
    std::memcpy(&(msg->status), buf + index, sizeof(msg->status));
}

///////////////////////////POEMS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void poem_create_request::pack(poem_create_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}
void poem_create_request::unpack(poem_create_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_create_response::pack(poem_create_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}
void poem_create_response::unpack(poem_create_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_feed_request::pack(poem_feed_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_feed_request::unpack(poem_feed_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_feed_response::pack(poem_feed_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_feed_response::unpack(poem_feed_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_detail_view_request::pack(poem_detail_view_request *msg, uint8_t *buf)
{
    int index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
}

void poem_detail_view_request::unpack(poem_detail_view_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_detail_view_response::pack(poem_detail_view_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_detail_view_response::unpack(poem_detail_view_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_delete_request::pack(poem_delete_request *msg, uint8_t *buf)
{
    int index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_delete_request::unpack(poem_delete_request *msg, uint8_t *buf)
{
    int index = 0;
    u_int8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_delete_response::pack(poem_delete_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_delete_response::unpack(poem_delete_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_interaction_request::pack(poem_interaction_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);

    // TODO MAKE SURE ALL_LEN + 1

    index = index + TOKEN_LEN + 1;

    std::memcpy(buf + index, &msg->action, sizeof(msg->action));
    index += sizeof(msg->action);
}

void poem_interaction_request::unpack(poem_interaction_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);

    // TODO MAKE SURE ALL_LEN + 1

    index = index + TOKEN_LEN + 1;

    std::memcpy(&msg->action, buf + index, sizeof(msg->action));
    index += sizeof(msg->action);
}

void poem_interaction_response::pack(poem_interaction_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(msg->id);

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_interaction_response::unpack(poem_interaction_response *msg, uint8_t *buf)
{
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}
