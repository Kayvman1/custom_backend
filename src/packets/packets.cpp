
#include <iostream>
#include <string>
#include <cstring>
#include "packets.h"
#include "packet_ids.h"

/////////////////////////// PACKETS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

uint32_t packet::pack(packet *msg, uint8_t *buf, void *raw_msg)
{
    uint8_t index = 0;
    int buf_size_addr;
    uint32_t message_size;

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

    buf_size_addr = index;
    index = index + sizeof(msg->buf_size);

    pack_pointer func = GET_PACK_FOR_MESSAGE(msg);
    message_size = func(raw_msg, buf + index);

    // TODO REMOVE THIS, DEBUGGING ?
    msg->buf_size = message_size;

    std::memcpy(buf + buf_size_addr, &message_size, sizeof(message_size));
    index += message_size;
    return index;
}

void *packet::unpack(packet *msg, uint8_t *buf)
{
    // Do pass in a raw buff or instantiate one here

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

    std::memcpy(&msg->buf_size, buf + index, sizeof(msg->buf_size));
    index = index + sizeof(msg->buf_size);

    void *m = GET_POINTER_MESSAGE(msg);
    unpack_pointer func = GET_UNPACK_FOR_MESSAGE(msg);
    func(m, buf + index);

    return m;
}

void *packet::message_unpack(uint8_t *buf)
{
    void *m = GET_POINTER_MESSAGE(this);
    unpack_pointer func = GET_UNPACK_FOR_MESSAGE(this);
    func(m, buf);

    return m;
}

////////////////////////// ERROR MESSAGES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

uint32_t error_response::pack(void *raw_msg, uint8_t *buf)
{
    error_response *msg = (error_response *)raw_msg;
    uint8_t response_length = msg->response.length();

    int index = 0;
    memcpy(buf, &msg->status, sizeof(msg->status));
    index += sizeof(msg->status);

    memcpy(buf, &response_length, sizeof(response_length));
    index += response_length;
    memcpy(buf, msg->response.c_str(), msg->response.length());
}

void error_response::unpack(void *raw_msg, uint8_t * buf)
{
    error_response * msg = (error_response *) raw_msg;
    int index = 0;
    uint8_t response_length;

    memcpy(&msg->status, buf + index, sizeof(msg->status));
    index += sizeof(msg->status);
    memcpy(&response_length, buf, sizeof(response_length));
    index += sizeof(response_length);
    memcpy(&msg->response, buf, response_length);
}

/////////////////////////// TEST Messages \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

uint32_t test_request::pack(void *raw_msg, uint8_t *buf)
{
    test_request *msg = (test_request *)raw_msg;
    std::memcpy(buf, &(msg->val), sizeof(msg->val));

    return sizeof(msg->val);
}

void test_request::unpack(void *raw_msg, uint8_t *buf)
{
    test_request *msg = (test_request *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->val, buf + index, sizeof(msg->val));

    return;
}

uint32_t test_response::pack(void *raw_msg, uint8_t *buf)
{
    test_response *msg = (test_response *)raw_msg;
    std::memcpy(buf, &(msg->val), sizeof(val));

    return sizeof(val);
}

void test_response::unpack(void *raw_msg, uint8_t *buf)
{
    test_response *msg = (test_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->val, buf + index, sizeof(msg->val));

    return;
}

/////////////////////////// CONTROL MESSAGES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


uint32_t login_request::pack(void *raw_msg, uint8_t *buf)
{
    login_request *msg = (login_request *)raw_msg;
    uint32_t index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index = index + sizeof(username_length);

    std::strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index = index + USERNAME_LEN + 1;

    std::memcpy(buf + index, &password_length, sizeof(password_length));
    index = index + sizeof(password_length);

    std::strncpy((char *)buf + index, msg->password.c_str(), PASSWORD_LEN + 1);
    index += PASSWORD_LEN + 1;

    return index;
}
void login_request::unpack(void *raw_msg, uint8_t *buf)
{
    login_request *msg = (login_request *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->username_length, buf + index, sizeof(username_length));
    index = index + sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index = index + USERNAME_LEN + 1;

    std::memcpy((&msg->password_length), buf + index, sizeof(password_length));
    index = index + sizeof(password_length);

    msg->password = std::string((char *)buf + index);

    return;
}

uint32_t login_response::pack(void *raw_msg, uint8_t *buf)
{
    login_response *msg = (login_response *)raw_msg;
    uint32_t index = 0;
    uint8_t token_length = msg->auth_token.length();

    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(buf + index, &token_length, sizeof(token_length));
    index = index + sizeof(token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    if (msg->status == 201)
    {
        index += account::pack(msg->user, buf + index);
    }
    return index;
}

void login_response::unpack(void *raw_msg, uint8_t *buf)
{
    login_response *msg = (login_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&(msg->status), buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(&msg->auth_token_length, buf + index, sizeof(msg->auth_token_length));
    index = index + sizeof(msg->auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
    index = index + TOKEN_LEN + 1;

    // TODO verify this logic
    if (msg->status == 201)
    {
        msg->user = new account;
        index += account::unpack(msg->user, buf + index);
    }
}
uint32_t refresh_token_request::pack(void *raw_msg, uint8_t *buf)
{
    refresh_token_request *msg = (refresh_token_request *)raw_msg;
    uint32_t index = 0;
    uint8_t refresh_token_length = msg->refresh_token.length();

    std::memcpy(buf + index, &refresh_token_length, sizeof(refresh_token_length));
    index = index + sizeof(refresh_token_length);

    strncpy((char *)buf + index, msg->refresh_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    return index;
}
void refresh_token_request::unpack(void *raw_msg, uint8_t *buf)
{
    refresh_token_request *msg = (refresh_token_request *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->refresh_token_length, buf + index, sizeof(refresh_token_length));
    index = index + sizeof(refresh_token_length);

    msg->refresh_token = std::string((char *)buf + index);
    index += TOKEN_LEN + 1;
}

uint32_t refresh_token_response::pack(void *raw_msg, uint8_t *buf)
{
    refresh_token_response *msg = (refresh_token_response *)raw_msg;
    uint32_t index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
    index += TOKEN_LEN + 1;

    return index;
}

void refresh_token_response::unpack(void *raw_msg, uint8_t *buf)

{
    refresh_token_response *msg = (refresh_token_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);

    std::memcpy(&msg->auth_token_length, buf + index, sizeof(msg->auth_token_length));
    index = index + sizeof(msg->auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
    index += TOKEN_LEN + 1;
}

uint32_t create_user_request::pack(void *raw_msg, uint8_t *buf)
{
    create_user_request *msg = (create_user_request *)raw_msg;
    uint32_t index = 0;
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
    index = index + EMAIL_LEN + 1;

    return index;
}

void create_user_request::unpack(void *raw_msg, uint8_t *buf)
{
    create_user_request *msg = (create_user_request *)raw_msg;
    uint32_t index = 0;
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
uint32_t create_user_response::pack(void *raw_msg, uint8_t *buf)
{
    create_user_response *msg = (create_user_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &(msg->status), sizeof(msg->status));
    index = index + sizeof(msg->status);

    index += account::pack(msg->user, buf + index);

    return index;
}

void create_user_response::unpack(void *raw_msg, uint8_t *buf)
{
    create_user_response *msg = (create_user_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&(msg->status), buf + index, sizeof(msg->status));
    index += sizeof(msg->status);

    msg->user = new account;
    index += account::unpack(msg->user, buf + index);
}

/////////////////////////// POEMS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

uint32_t poem_create_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_create_request *msg = (poem_create_request *)raw_msg;
    uint32_t index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);

    index += poem::pack(msg->poem_create, buf + index);
    index += account::pack(msg->user, buf + index);
}

void poem_create_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_create_request *msg = (poem_create_request *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);

    msg->user = new account;
    msg->poem_create = new poem;

    index += poem::unpack(msg->poem_create, buf + index);
    index += account::unpack(msg->user, buf + index);
}

uint32_t poem_create_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_create_response *msg = (poem_create_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}
void poem_create_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_create_response *msg = (poem_create_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

uint32_t poem_feed_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_feed_request *msg = (poem_feed_request *)raw_msg;
    uint32_t index = 0;
    uint8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_feed_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_feed_request *msg = (poem_feed_request *)raw_msg;
    uint32_t index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

uint32_t poem_feed_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_feed_response *msg = (poem_feed_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_feed_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_feed_response *msg = (poem_feed_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

uint32_t poem_detail_view_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_request *msg = (poem_detail_view_request *)raw_msg;
    uint32_t index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN + 1);
}

void poem_detail_view_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_request *msg = (poem_detail_view_request *)raw_msg;
    uint32_t index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

uint32_t poem_detail_view_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_response *msg = (poem_detail_view_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_detail_view_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_detail_view_response *msg = (poem_detail_view_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

uint32_t poem_delete_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_delete_request *msg = (poem_delete_request *)raw_msg;
    uint32_t index = 0;
    u_int8_t auth_token_length = msg->auth_token.length();

    std::memcpy(buf + index, &auth_token_length, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    std::strncpy((char *)buf + index, msg->auth_token.c_str(), TOKEN_LEN);
}

void poem_delete_request::unpack(void *raw_msg, uint8_t *buf)
{
    poem_delete_request *msg = (poem_delete_request *)raw_msg;
    uint32_t index = 0;
    u_int8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);
}

uint32_t poem_delete_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_delete_response *msg = (poem_delete_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_delete_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_delete_response *msg = (poem_delete_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

uint32_t poem_interaction_request::pack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_request *msg = (poem_interaction_request *)raw_msg;
    uint32_t index = 0;
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
    uint32_t index = 0;
    uint8_t auth_token_length;

    std::memcpy(&auth_token_length, buf + index, sizeof(auth_token_length));
    index = index + sizeof(auth_token_length);

    msg->auth_token = std::string((char *)buf + index);

    // TODO MAKE SURE ALL_LEN + 1

    index = index + TOKEN_LEN + 1;

    std::memcpy(&msg->action, buf + index, sizeof(msg->action));
    index += sizeof(msg->action);
}

uint32_t poem_interaction_response::pack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_response *msg = (poem_interaction_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(buf + index, &msg->status, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

void poem_interaction_response::unpack(void *raw_msg, uint8_t *buf)
{
    poem_interaction_response *msg = (poem_interaction_response *)raw_msg;
    uint32_t index = 0;

    std::memcpy(&msg->status, buf + index, sizeof(msg->status));
    index = index + sizeof(msg->status);
}

///////////MOVE \\\\\\\\\\\\\\\\\\\\\\\\\

uint32_t account::pack(void *raw_msg, uint8_t *buf)
{
    account *msg = (account *)raw_msg;

    uint32_t index = 0;
    uint8_t username_length = msg->username.length();

    std::memcpy(buf + index, &username_length, sizeof(username_length));
    index += sizeof(username_length);

    strncpy((char *)buf + index, msg->username.c_str(), USERNAME_LEN + 1);
    index += USERNAME_LEN + 1;

    return index;
}

uint32_t account::unpack(void *raw_msg, uint8_t *buf)
{
    account *msg = (account *)raw_msg;

    uint32_t index = 0;
    uint8_t username_length;

    std::memcpy(&username_length, buf + index, sizeof(username_length));
    index += sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index += USERNAME_LEN + 1;

    return index;
}

uint32_t poem::pack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    uint32_t index = 0;
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

    index += account::pack(&msg->author, buf + index);

    return index;
}

uint32_t poem::unpack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    uint32_t index = 0;
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

    msg->author = new account;
    index += account::unpack(&msg->author, buf + index);

    return index;
}
