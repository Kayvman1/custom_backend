#include <iostream>
#define USERNAME_LEN  31 // +1 for \0
#define PASSWORD_LEN  31

class test_message {
    public:
    std::string str1;
    uint32_t int1;

    static int pack();

    //static void unpack(test_message *msg, void *buf);
};

class login_request
{
public:
    std::string username;
    std::string password;
    u_int8_t id = 1;
    // Furth auth cookies ?
    static void pack(login_request *msg, uint8_t *buf);
    static void unpack(login_request *msg, uint8_t *buf);
};

class login_response
{
public:
    std::string auth_token;
};

class refresh_token_rquest
{
public:
    std::string auth_token;
    // cookies?
};

class refresh_token_response
{
public:
    std::string auth_token;
};

class create_user_request
{
public:
    std::string username;
    std::string password;
    std::string email;
};
class create_user_response
{
public:
    int status;
};