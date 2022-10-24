#pragma once 
#include <iostream>
#include "../accounts/account.h"

#define TITLE_LEN 50
#define CONTENT_LEN 50

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
