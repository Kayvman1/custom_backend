#include <iostream>
#include <string>
#include <cstring>
#include "ring_buffer.h"

ring_buffer::ring_buffer()
{
    size = RING_SIZE;
    buf = (uint8_t *)malloc(size);
    read_pointer = buf;
    write_pointer = buf;
}

void ring_buffer::write(void *raw_data, int len)
{
    // first check to see if write fits

    if (write_pointer + len > buf + size)
    {
        int partial_len = buf + size - write_pointer;
        int remaining_len = len - partial_len;

        std::memcpy(write_pointer, raw_data, partial_len);
        std::memcpy(buf, raw_data, remaining_len);
        write_pointer = buf + remaining_len + 1;

        return;
    }

    std::memcpy(write_pointer, raw_data, len);
    write_pointer += len;
    if (write_pointer == buf + size){
        write_pointer = buf;
    }
}