#include "post.h"
#include <cstring>

uint32_t poem::pack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    uint32_t index = 0;
    uint8_t title_length = msg->title.length();
    uint8_t content_length = msg->content.length();

    std::memcpy(buf + index, &msg->poem_id, sizeof(msg->poem_id));
    index += sizeof(msg->poem_id);

    std::memcpy(buf + index, &title_length, sizeof(title_length));
    index += sizeof(title_length);

    strncpy((char *)buf + index, msg->title.c_str(), TITLE_LEN + 1);
    index += TITLE_LEN + 1;

    strncpy((char *)buf + index, msg->content.c_str(), CONTENT_LEN + 1);
    index += CONTENT_LEN + 1;

    index += account::pack(&msg->author, buf + index);

    return index;
}

uint32_t poem::unpack(void *raw_msg, uint8_t *buf)
{
    poem *msg = (poem *)raw_msg;

    uint32_t index = 0;
    uint8_t title_length;
    uint8_t content_length;

    std::memcpy(&msg->poem_id, buf + index, sizeof(msg->poem_id));
    index += sizeof(msg->poem_id);

    std::memcpy(&title_length, buf + index, sizeof(title_length));
    index += sizeof(title_length);

    msg->title = std::string((char *)buf + index);
    index += TITLE_LEN + 1;

    msg->content = std::string((char *)buf + index);
    index += CONTENT_LEN + 1;

    msg->author = new account;
    index += account::unpack(&msg->author, buf + index);

    return index;
}
