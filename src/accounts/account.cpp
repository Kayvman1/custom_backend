#include "account.h"
#include <cstring>


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
