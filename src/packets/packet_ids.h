#pragma once

#include "../server/packet_handlers.h"
#include "../packets/packets.h"
#include "../server/client.h"

using handler_pointer = void (*)(uint8_t *, packet *, client *);
using pack_pointer = uint32_t (*)(void *, uint8_t *);
using unpack_pointer = void (*)(void *raw_msg, uint8_t *buf);

#define ERROR_PACKET_TABLE(XX) \
    XX(error_response, 1, packet_handlers::response_handler, error_response::pack, error_response::unpack)

#define TEST_PACKET_TABLE(XX)                                                                            \
    XX(test_request, 1, packet_handlers::test_request_handler, test_request::pack, test_request::unpack) \
    XX(test_response, 2, packet_handlers::response_handler, test_response::pack, test_response::unpack)

#define CONTROL_PACKET_TABLE(XX)                                                                      \
    XX(login_request, 1, packet_handlers::login_request_handler, login_request::pack, login_request::unpack)                            \
    XX(login_response, 2, NULL, login_response::pack, login_response::unpack)                         \
    XX(refresh_token_request, 3, NULL, refresh_token_request::pack, refresh_token_request::unpack)    \
    XX(refresh_token_response, 4, NULL, refresh_token_response::pack, refresh_token_response::unpack) \
    XX(create_user_request, 5, packet_handlers::create_user_request_handler, create_user_request::pack, create_user_request::unpack)            \ 
    XX(create_user_response, 6, NULL, create_user_response::pack, create_user_response::unpack)

#define POEM_PACKET_TABLE(XX)                                                                           \
    XX(poem_create_request, 1 , packet_handlers::poem_create_request_handler, poem_create_request::pack, poem_create_request::unpack )

enum MESSAGE_TYPE
{
    TEST_PACKET = 100,
    CONTROL_PACKET = 0,
    ERROR_PACKET = 1,
    POEM_PACKET = 2
};

enum ERROR_PACKETS_IDS
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    CLASS##_id = ID,
    ERROR_PACKET_TABLE(PACKET_HANDLER)
};

enum TEST_PACKET_IDS
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    CLASS##_id = ID,
    TEST_PACKET_TABLE(PACKET_HANDLER)

#undef PACKET_HANDLER
};

enum CONTROL_PACKET_IDS
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    CLASS##_id = ID,
    CONTROL_PACKET_TABLE(PACKET_HANDLER)

#undef PACKET_HANDLER
};

enum POEM_PACKET_IDS
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    CLASS##_id = ID,
    POEM_PACKET_TABLE(PACKET_HANDLER)

#undef PACKET_HANDLER
};

#define expand                                   \
    switch (p->message_type)                     \
    {                                            \
    case TEST_PACKET:                            \
        switch (p->message_id)                   \
        {                                        \
            TEST_PACKET_TABLE(PACKET_HANDLER)    \
        }                                        \
    case CONTROL_PACKET:                         \
        switch (p->message_id)                   \
        {                                        \
            CONTROL_PACKET_TABLE(PACKET_HANDLER) \
        }                                        \
    case ERROR_PACKET:                           \
        switch (p->message_id)                   \
        {                                        \
            ERROR_PACKET_TABLE(PACKET_HANDLER)   \
        }                                        \
    default:                                     \
        return NULL;                             \
    }

static handler_pointer GET_HANDLER_FOR_MESSAGE(packet *p)
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    case ID:                                             \
        return HANDLER;

    expand

#undef PACKET_HANDLER
}

static pack_pointer GET_PACK_FOR_MESSAGE(packet *p)
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    case ID:                                             \
        return PACK;
    expand
#undef PACKET_HANDLER
}

static unpack_pointer GET_UNPACK_FOR_MESSAGE(packet *p)
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    case ID:                                             \
        return UNPACK;
    expand
#undef PACKET_HANDLER
}

static void *GET_POINTER_MESSAGE(packet *p)
{
#define PACKET_HANDLER(CLASS, ID, HANDLER, PACK, UNPACK) \
    case ID:                                             \
        return new CLASS();
    expand
#undef PACKET_HANDLER
}

// Control Packet Errors
enum control_errors
{
    create_user_failed = 1,
    incorrect_password = 2,
    user_not_found = 3
};