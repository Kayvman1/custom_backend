#pragma once 

#include<iostream>

#define USERNAME_LEN 31
#define PASSWORD_LEN 31
#define TOKEN_LEN 31
#define EMAIL_LEN 127

class account
{
public:
    std::string username;

    static uint32_t pack(void *raw_msg, uint8_t *buf);
    static uint32_t unpack(void *raw_msg, uint8_t *buf);
};
