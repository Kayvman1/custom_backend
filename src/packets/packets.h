#include <iostream>
#define USERNAME_LEN 31
#define PASSWORD_LEN 31
#define TOKEN_LEN 31
#define EMAIL_LEN 127

//TODO ALL STATUS MUST BE 2 BYTES ?

class test_message
{
public:
    std::string str1;
    uint32_t int1;

    static int pack();

    // static void unpack(test_message *msg, void *buf);
};

class login_request
{
public:
    std::string username;
    std::string password;
    const u_int8_t id = 1;
    // Furth auth cookies ?
    static void pack(login_request *msg, uint8_t *buf);
    static void unpack(login_request *msg, uint8_t *buf);
};

class login_response
{
public:
    uint8_t status;
    std::string auth_token;
    const u_int8_t id = 2;
    // User class TBD Based on database

    static void pack(login_response *msg, uint8_t *buf);
    static void unpack(login_response *msg, uint8_t *buf);
};

class refresh_token_request
{
public:
    const uint8_t id = 3;
    std::string refresh_token;
    std::string csrf_token;

    static void pack(refresh_token_request *msg, uint8_t *buf);
    static void unpack(refresh_token_request *msg, uint8_t *buf);
};

class refresh_token_response
{
public:
    const uint8_t id = 4;
    std::string auth_token;
    //TODO ADD STATUS
    static void pack(refresh_token_response *msg, uint8_t *buf);
    static void unpack(refresh_token_response *msg, uint8_t *buf);
};

class create_user_request
{
public:
    uint8_t id = 5;
    std::string username;
    std::string password;
    std::string email;
    static void pack(create_user_request *msg, uint8_t *buf);
    static void unpack(create_user_request *msg, uint8_t *buf);
};
class create_user_response // TODO SHOULD THIS BE THE SAME AS A LOGIN REQUEST RESPONSE
{
public:
    uint8_t id = 6;
    int status;
    // USER CLASS
    static void pack(create_user_response *msg, uint8_t *buf);
    static void unpack(create_user_response *msg, uint8_t *buf);
};

//////////////////////////// POEMS   //////////////////////////////////////////////////

class poem_create_request
{
public:
    // User class;
    // POEM;
    uint8_t id = 7;
    std::string auth_token;
    static void pack(poem_create_request *msg, uint8_t *buf);
    static void unpack(poem_create_request *msg, uint8_t *buf);
};
class poem_create_response
{
public:
    uint8_t id = 8;
    uint8_t status;
    static void pack(poem_create_response *msg, uint8_t *buf);
    static void unpack(poem_create_response *msg, uint8_t *buf);
};


class poem_feed_request
{
public:
    uint8_t id = 9;
    // USER
    std::string auth_token;
    static void pack(poem_feed_request *msg, uint8_t *buf);
    static void unpack(poem_feed_request *msg, uint8_t *buf);
};

class poem_feed_response
{
public:
    uint8_t id = 10;
    uint8_t status;
    // list of poems
    static void pack(poem_feed_response *msg, uint8_t *buf);
    static void unpack(poem_feed_response *msg, uint8_t *buf);
};
class poem_detail_view_request
{
public:
    uint8_t id = 11;
    std::string auth_token;
    //POEM ID OR POEM CLASS ?
    static void pack(poem_detail_view_request *msg, uint8_t *buf);
    static void unpack(poem_detail_view_request *msg, uint8_t *buf);
};

class poem_detail_view_response
{
public:
    uint8_t id = 12;
    // POEM
    uint8_t status;
    static void pack(poem_detail_view_response *msg, uint8_t *buf);
    static void unpack(poem_detail_view_response *msg, uint8_t *buf);
};

class poem_delete_request
{
public:
    uint8_t id = 13;
    std::string auth_token;
    // USER
    // POEM or just ID
    static void pack(poem_delete_request *msg, uint8_t *buf);
    static void unpack(poem_delete_request *msg, uint8_t *buf);
};
class poem_delete_response
{
public:
    uint8_t id = 14;
    uint8_t status;
    static void pack(poem_delete_response *msg, uint8_t *buf);
    static void unpack(poem_delete_response *msg, uint8_t *buf);
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
    static void pack(poem_interaction_request *msg, uint8_t *buf);
    static void unpack(poem_interaction_request *msg, uint8_t *buf);
};

class poem_interaction_response
{
public:
    uint8_t id = 16;
    uint8_t status;
    static void pack(poem_interaction_response *msg, uint8_t *buf);
    static void unpack(poem_interaction_response *msg, uint8_t *buf);
};
// poem_paginated_response (useful helper method)
