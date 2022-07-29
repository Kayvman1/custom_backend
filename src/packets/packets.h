#include <iostream>
#define USERNAME_LEN 31
#define PASSWORD_LEN 31
#define TOKEN_LEN 31
#define EMAIL_LEN 127
// TODO MOVE THESE MACROS
#define TITLE_LEN 50
#define CONTENT_LEN 50

// TODO ALL STATUS MUST BE 2 BYTES ?

class packet
{
public:
    uint8_t message_type;
    uint8_t message_id;
    uint64_t magic;
    uint64_t session_token;
    uint32_t flags;

    //uint64_t buf_size;
    //uint8_t *buf;

    static void pack(packet *msg, uint8_t *buf, void *raw_msg);
    static void unpack(packet *msg, uint8_t *buf, void *raw_msg);
};

// MESSAGE CLASS 0: CONTROL PACKETS

class login_request
{
public:
    std::string username;
    std::string password;

    //TODO : username/password len
    const u_int8_t id = 1;
    // Furth auth cookies ?
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class login_response
{
public:
    uint8_t status;
    std::string auth_token;
    const u_int8_t id = 2;
    // User class TBD Based on database

    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class refresh_token_request
{
public:
    const uint8_t id = 3;
    std::string refresh_token;
    std::string csrf_token;

    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class refresh_token_response
{
public:
    const uint8_t id = 4;
    std::string auth_token;
    // TODO ADD STATUS
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

// TODO THIS MUST BE MOVED
class user
{
public:
    std::string username;

    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem
{
public:
    int poem_id;
    std::string title;
    std::string content;
    user author;

    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

// PACKET

// MESSAGES

class create_user_request
{
public:
    uint8_t id = 5;
    std::string username;
    std::string password;
    std::string email;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class create_user_response // TODO SHOULD THIS BE THE SAME AS A LOGIN REQUEST RESPONSE
{
public:
    uint8_t id = 6;
    int status;
    // USER CLASS
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

//////////////////////////// POEMS   //////////////////////////////////////////////////

class poem_create_request
{
public:
    // User class;
    // POEM;
    uint8_t id = 7;
    std::string auth_token;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_create_response
{
public:
    uint8_t id = 8;
    uint8_t status;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_feed_request
{
public:
    uint8_t id = 9;
    // USER
    std::string auth_token;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_feed_response
{
public:
    uint8_t id = 10;
    uint8_t status;
    // list of poems
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_detail_view_request
{
public:
    uint8_t id = 11;
    std::string auth_token;
    // POEM ID OR POEM CLASS ?
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_detail_view_response
{
public:
    uint8_t id = 12;
    // POEM
    uint8_t status;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_delete_request
{
public:
    uint8_t id = 13;
    std::string auth_token;
    // USER
    // POEM or just ID
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_delete_response
{
public:
    uint8_t id = 14;
    uint8_t status;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
class poem_interaction_request
{
public:
    uint8_t id = 15;
    std::string auth_token;
    // USER
    // POEM
    // TODO MAKE AN ENUM FOR THIS
    uint8_t action;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};

class poem_interaction_response
{
public:
    uint8_t id = 16;
    uint8_t status;
    static void pack(void *raw_msg, uint8_t *buf);
    static void unpack(void *raw_msg, uint8_t *buf);
};
// poem_paginated_response (useful helper method)
