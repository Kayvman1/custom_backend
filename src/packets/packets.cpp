#include <iostream>
#include <string>
#include <cstring>
#include "packets.h"
#include "packet_ids.h"

void packet::pack(packet *msg, uint8_t *buf, void *raw_msg)
{
    uint8_t index = 0;

    std::memcpy(buf + index, &msg->message_type, sizeof(msg->message_type));
    index = index + sizeof(msg->message_type);

    std::memcpy(buf + index, &msg->message_id, sizeof(msg->message_id));
    index = index + sizeof(msg->message_id);

    std::memcpy(buf + index, &msg->magic, sizeof(msg->magic));
    index = index + sizeof(msg->magic);

    std::memcpy(buf + index, &msg->session_token, sizeof(session_token));
    index = index + sizeof(msg->session_token);

    std::memcpy(buf + index, &msg->flags, sizeof(msg->flags));
    index = index + sizeof(msg->flags);

    // /poem_interaction_response::pack(raw_msg, buf + index);

    switch (msg->message_type)
    {
    case CONTROL_PACKET:
        switch (msg->message_id)
        {
#define X(ClassName, ClassID)                  \
    case ClassID:                              \
        ClassName::pack(raw_msg, buf + index); \
        break;
            CONTROL_PACKET_TABLE
#undef X
            break;
        }
        break;
    }
}

void packet::unpack(packet *msg, uint8_t *buf, void *raw_msg)
{
    //Do pass in a raw buff or instantiate one here 

    uint8_t index = 0;

    std::memcpy(&msg->message_type, buf + index, sizeof(msg->message_type));
    index = index + sizeof(msg->message_type);

    std::memcpy(&msg->message_id, buf + index, sizeof(msg->message_id));
    index = index + sizeof(msg->message_id);

    std::memcpy(&msg->magic, buf + index, sizeof(msg->magic));
    index = index + sizeof(msg->magic);

    std::memcpy(&msg->session_token, buf + index, sizeof(session_token));
    index = index + sizeof(msg->session_token);

    std::memcpy(&msg->flags, buf + index, sizeof(msg->flags));
    index = index + sizeof(msg->flags);

    // poem_interaction_response::unpack(raw_msg, buf + index + 1);

    switch (msg->message_type)
    {
    case CONTROL_PACKET:
        switch (msg->message_id)
        {
#define X(ClassName, ClassID)                        \
    case ClassID:                                    \
        ClassName::unpack(raw_msg, buf + index ); \
        break;
            CONTROL_PACKET_TABLE
#undef X
            break;
        }
        break;
    }
}

// login request
// CAN I MAKE THIS A UINT 8 BUF SO I CAN INCREMENT

// CONSUME FIRST BYTE OF PACKED BUFFER
void  login_request::pack(void *raw_msg, uint8_t *buf)
{
    login_request *msg = (login_request *)raw_msg;
    int index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();

    // Should this be type aliased

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index = index + sizeof(username_length);

    std::strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index = index + USERNAME_LEN + 1;

    std::memcpy(buf + index, &password_length, sizeof(password_length));
    index = index + sizeof(password_length);

    std::strncpy((char *)buf + index, msg->password.c_str(), PASSWORD_LEN + 1);
    index += PASSWORD_LEN + 1;

    return ;
}
void login_request::unpack(void *raw_msg, uint8_t *buf)
{
    login_request *msg = (login_request *)raw_msg;
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

int login_response::pack(void *raw_msg, uint8_t *buf)
{
    login_response *msg = (login_response *)raw_msg;
    // TODO add user class serialization
    int index = 0;
    uint8_t token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(buf + index, &token_length, sizeof(token_length));
    index = index + sizeof(token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    return index;
}


void login_response::unpack(void *raw_msg, uint8_t *buf)
{
    login_response *msg = (login_response *)raw_msg;
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

void refresh_token_request::pack(void *raw_msg, uint8_t *buf)
{
    refresh_token_request *msg = (refresh_token_request *)raw_msg;
    int index = 0;
    uint8_t refresh_token_length = msg->refresh_token.length();
    uint8_t csrf_token_length = msg->csrf_token.length();

    std::memcpy(buf + index, &refresh_token_length, sizeof(refresh_token_length));
    index = index + sizeof(refresh_token_length);

    strncpy((char *)buf + index, msg->refresh_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    std::memcpy(buf + index, &csrf_token_length, sizeof(csrf_token_length));
    index = index + sizeof(csrf_token_length);

    strncpy((char *)buf + index, msg->csrf_token.c_str(), TOKEN_LEN + 1);
}
void refresh_token_request::unpack(void *raw_msg, uint8_t *buf)
{
    refresh_token_request *msg = (refresh_token_request *)raw_msg;
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

void refresh_token_response::pack(void *raw_msg, uint8_t *buf)
{
    refresh_token_response *msg = (refresh_token_response *)raw_msg;
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;
}

void refresh_token_response::unpack(void *raw_msg, uint8_t *buf)

{
    refresh_token_response *msg = (refresh_token_response *)raw_msg;
    int index = 0;
    uint8_t auth_token_length;
    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
    index += TOKEN_LEN + 1;
}

void create_user_request::pack(void *raw_msg, uint8_t *buf)
{
    create_user_request *msg = (create_user_request *)raw_msg;
    int index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();
    uint8_t email_length = msg->email.length();

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

void create_user_request::unpack(void *raw_msg, uint8_t *buf)
{
    create_user_request *msg = (create_user_request *)raw_msg;
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
void create_user_response::pack(void *raw_msg, uint8_t *buf)
{
    create_user_response *msg = (create_user_response *)raw_msg;
    // TODO add user class deserialization
    int index = 0;

    // ADD USER STUFF
    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
}

void create_user_response::unpack(void *raw_msg, uint8_t *buf)
{
    create_user_response *msg = (create_user_response *)raw_msg;
    // TODO add user class deserialization
    int index = 0;
    // ADD CLASS STUFF
    std::memcpy(&(msg->status), buf + index, sizeof(msg->status));
}

///////////////////////////POEMS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void poem_create_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_create_request *msg = (poem_create_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_create_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_create_request *msg = (poem_create_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_create_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_create_response *msg = (poem_create_response *)raw_msg;
    int index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}
void poem_create_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_create_response *msg = (poem_create_response *)raw_msg;
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_feed_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_feed_request *msg = (poem_feed_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_feed_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_feed_request *msg = (poem_feed_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_feed_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_feed_response *msg = (poem_feed_response *)raw_msg;
    int index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_feed_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_feed_response *msg = (poem_feed_response *)raw_msg;
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_detail_view_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_request *msg = (poem_detail_view_request *)raw_msg;
    int index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
}

void poem_detail_view_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_request *msg = (poem_detail_view_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_detail_view_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_response *msg = (poem_detail_view_response *)raw_msg;
    int index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_detail_view_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_response *msg = (poem_detail_view_response *)raw_msg;
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_delete_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_delete_request *msg = (poem_delete_request *)raw_msg;
    int index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_delete_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_delete_request *msg = (poem_delete_request *)raw_msg;
    int index = 0;
    u_int8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

void poem_delete_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_delete_response *msg = (poem_delete_response *)raw_msg;
    int index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_delete_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_delete_response *msg = (poem_delete_response *)raw_msg;
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_interaction_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_request *msg = (poem_interaction_request *)raw_msg;
    int index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);

    // TODO MAKE SURE ALL_LEN + 1

    index = index + TOKEN_LEN + 1;

    std::memcpy(buf + index, &msg->action, sizeof(msg->action));
    index += sizeof(msg->action);
}

void poem_interaction_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_request *msg = (poem_interaction_request *)raw_msg;
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

void poem_interaction_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_response *msg = (poem_interaction_response *)raw_msg;
    int index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_interaction_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_response *msg = (poem_interaction_response *)raw_msg;
    int index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

///////////MOVE \\\\\\\\\\\\\\\\\\\\\\\\\


void user::pack(void *raw_msg, uint8_t *buf)
{
    user *msg = (user *)raw_msg;

    int index = 0;
    uint8_t username_length = msg->username.length();

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index += sizeof(username_length);

    strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index += USERNAME_LEN + 1;
}

void user::unpack(void *raw_msg, uint8_t *buf)
{
    user *msg = (user *)raw_msg;

    int index = 0;
    uint8_t username_length;

    std::memcpy(&username_length, buf + index, sizeof(username_length));
    index += sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index += USERNAME_LEN + 1;
}

void poem::pack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    int index = 0;
    uint8_t title_length = msg->title.length();
    uint8_t content_length = msg->content.length();

    std::memcpy(buf + index, &msg->poem_id, sizeof(msg->poem_id));
    index += sizeof(msg->poem_id);

    std::memcpy(buf + index, &title_length, sizeof(title_length));
    index += sizeof(title_length);

    strncpy((char *)buf + index, msg->title.c_str(), TITLE_LEN + 1);
    index += TITLE_LEN + 1;

    strncpy((char *)buf + index, msg->content.c_str(), CONTENT_LEN + 1);
    index += CONTENT_LEN + 1;

    user::pack(&msg->author, buf + index);
}

void poem::unpack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    int index = 0;
    uint8_t title_length;
    uint8_t content_length;

    std::memcpy(&msg->poem_id, buf + index, sizeof(msg->poem_id));
    index += sizeof(msg->poem_id);

    std::memcpy(&title_length, buf + index, sizeof(title_length));
    index += sizeof(title_length);

    msg->title = std::string((char *)buf + index);
    index += TITLE_LEN + 1;

    msg->content = std::string((char *)buf + index);
    index += CONTENT_LEN + 1;

    user::unpack(&msg->author, buf + index);
}


