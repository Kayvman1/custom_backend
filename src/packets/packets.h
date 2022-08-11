#include <iostream>
#define USERNAME_LEN 31
#define PASSWORD_LEN 31
#define TOKEN_LEN 31
#define EMAIL_LEN 127

// TODO MOVE THESE MACROS
#define TITLE_LEN 50
#define CONTENT_LEN 50

// TODO THIS MUST BE MOVED
class account
{
public:
    std::string username;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static uint32_t unpack(void *raw_msg, uint8_t *buf);
};

class poem
{
public:
    int poem_id;
    std::string title;
    std::string content;
    account *author;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static uint32_t unpack(void *raw_msg, uint8_t *buf);
};

class packet
{
public:
    uint8_t message_type;
    uint8_t message_id;
    uint64_t magic;
    uint64_t session_token;
    uint32_t flags;

    uint32_t buf_size;

    static uint32_t pack(packet *msg, uint8_t *buf, void *raw_msg);
    static void *unpack(packet *msg, uint8_t *buf);
    static void *message_unpack(uint8_t *buf, uint8_t m_type, uint8_t m_id);
};

// MESSAGE CLASS 0: CONTROL PACKETS

class login_request
{
public:
    std::string username;
    std::string password;
    uint8_t username_length;
    uint8_t password_length;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class login_response
{
public:
    uint16_t status;
    std::string auth_token;
    uint8_t auth_token_length;
    account *user;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class refresh_token_request
{
public:
    std::string refresh_token;
    uint8_t refresh_token_length;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class refresh_token_response
{
public:
    std::string auth_token;
    uint8_t auth_token_length;
    uint16_t status;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class create_user_request
{
public:
    std::string username;
    std::string password;
    std::string email;
    uint8_t username_length;
    uint8_t password_length;
    uint8_t email_length;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class create_user_response
{
public:
    uint16_t status;
    account *user;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

//////////////////////////// POEMS   //////////////////////////////////////////////////

class poem_create_request
{
public:
    std::string auth_token;
    uint8_t auth_token_length;
    poem *poem_create;
    account *user;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_create_response
{
public:
    uint16_t status;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_feed_request
{
public:
    std::string auth_token;
    uint8_t auth_token_length;
    account *user;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_feed_response
{
public:
    uint16_t status;
    // list of poems
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_detail_view_request
{
public:
    std::string auth_token;
    uint32_t poem_id;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_detail_view_response
{
public:
    uint16_t status;
    poem poem_response;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_delete_request
{
public:
    std::string auth_token;
    // USER
    // POEM or just ID
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_delete_response
{
public:
    uint16_t status;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_interaction_request
{
public:
    std::string auth_token;
    // USER
    // POEM
    // TODO MAKE AN ENUM FOR THIS
    uint8_t action;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_interaction_response
{
public:
    uint16_t status;
    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
// poem_paginated_response (useful helper method)