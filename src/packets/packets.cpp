#include <iostream>
#include <string>
#include <cstring>
#include "packets.h"
#include <catch2/catch_test_macros.hpp>

// login request
// CAN I MAKE THIS A UINT 8 BUF SO I CAN INCREMENT
void login_request::pack(login_request *msg, uint8_t *buf)
{
    int index = 0;
    uint8_t username_length = msg->username.length();
    uint8_t password_length = msg->password.length();

    std::memcpy(buf + index, &(msg->id), sizeof(msg->id));
    index = index + sizeof(id);
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

    std::memcpy(&(msg->id), buf + index, sizeof(msg->id));
    index = index + sizeof(id);

    std::memcpy(&username_length, buf + index, sizeof(username_length));
    index = index + sizeof(username_length);

    msg->username = std::string((char *)buf + index);
    index = index + USERNAME_LEN + 1;

    std::memcpy((&password_length), buf + index, sizeof(password_length));
    index = index + sizeof(password_length);

    msg->password = std::string((char *)buf + index);

    return;
}

// POEMS
