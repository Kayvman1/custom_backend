#define TEST_PACKET_TABLE \
    X(test_request, 1)    \
    X(test_response, 2)

#define CONTROL_PACKET_TABLE     \
    X(login_request, 1)          \
    X(login_response, 2)         \
    X(refresh_token_request, 3)  \
    X(refresh_token_response, 4) \
    X(create_user_request, 5)    \
    X(create_user_response, 6)

// BUILD OUT TABLE

enum TEST_PACKET_IDS
{
#define X(ClassName, ClassID) ClassName##_id = ClassID,
    TEST_PACKET_TABLE
#undef X
};

enum CONTROL_PACKET_IDS
{
#define X(ClassName, ClassID) ClassName##_id = ClassID,
    CONTROL_PACKET_TABLE
#undef X
};

enum MESSAGE_TYPE
{
    TEST_PACKET = -1,
    CONTROL_PACKET = 0,
};
