#include <iostream>
#include <string>
#include <cstring>
#include "ring_buffer.h"
#include <mutex>

ring_buffer::ring_buffer()
{
    buf = (uint8_t *)malloc(size);
    read_pointer = buf;
    write_pointer = buf;
    stack = std::queue<uint8_t *>();
}

ring_buffer::ring_buffer(int l)
{
    size = l;
    buf = (uint8_t *)malloc(size);
    read_pointer = buf;
    write_pointer = buf;
    stack = std::queue<uint8_t *>();
}

uint16_t ring_buffer::write(uint8_t *raw_data, uint16_t len)
{
    // SEGMENT 1 AND 2
    //  first check to see if write fits
    int segment_right = buf + size - write_pointer;
    int segment_left = len - segment_right;

    int bytes_written = 0; // TODO should i use this and count when i write or just return len?

    if (segment_right > len)
    {
        std::memcpy(write_pointer, raw_data, len);
        write_pointer = write_pointer + len;
    }
    else
    {
        std::memcpy(write_pointer, raw_data, segment_right);
        std::memcpy(buf, raw_data + segment_right, segment_left);
        write_pointer = buf + segment_left;
    }

    if (write_pointer > buf + size)
    {
        write_pointer -= size;
    }
    stack.push(write_pointer);
    return len;
}

// HAVE The caller pass in a buffer and write to it.
// Think about what to do if buffer passed in is two small
void *ring_buffer::read()
{
    lock.lock();
    // if there is nothing to read return -1:

    if (stack.empty())
    {
        lock.unlock();
        return NULL;
    }

    uint8_t *stop_pointer = stack.front();
    stack.pop();

    uint8_t *return_buffer;

    // The entire message is in order
    if (stop_pointer > read_pointer)
    {
        int buf_size = stop_pointer - read_pointer;
        return_buffer = (uint8_t *)malloc(buf_size);
        memcpy(return_buffer, read_pointer, stop_pointer - read_pointer);
        read_pointer = stop_pointer;

    }

    // The message wraps around
    else
    {
        // Start at the end of the buffer and count back to read pointer start
        int segment_right = buf + size - read_pointer;
        // Then count from the wrap point to stop pointer
        int segment_left = stop_pointer - buf;

        return_buffer = (uint8_t *)malloc(segment_right + segment_left);
        memcpy(return_buffer, read_pointer, segment_right);
        memcpy(return_buffer + segment_right, buf, segment_left);

        read_pointer = buf + segment_left;

    }

    lock.unlock();
    return return_buffer;
}