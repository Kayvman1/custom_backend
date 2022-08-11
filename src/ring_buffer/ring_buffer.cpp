#include <iostream>
#include <string>
#include <cstring>
#include "ring_buffer.h"
#include <mutex>

ring_buffer::ring_buffer()
{
    size = RING_SIZE;
    buf = (uint8_t *)malloc(size);
    read_pointer = buf;
    write_pointer = buf;
    
    
}

ring_buffer::ring_buffer(int l)
{
    size = l;
    buf = (uint8_t *)malloc(size);
    read_pointer = buf;
    write_pointer = buf;
    
}

void ring_buffer::write(void *raw_data, uint16_t len)
{
    // SEGMENT 1 AND 2
    //  first check to see if write fits
    int segment_right = buf + size - write_pointer;
    int segment_left = len - segment_right;

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
    return;
}

// HAVE The caller pass in a buffer and write to it.
// Think about what to do if buffer passed in is two small
void *ring_buffer::read()
{
    // first check to see if write fits
    uint8_t *stop_pointer = stack.front();
    stack.pop();
    uint8_t *return_buffer;

    if (stop_pointer > read_pointer)
    {
        int buf_size = stop_pointer - read_pointer;
        return_buffer = (uint8_t *)malloc(buf_size);

        memcpy(return_buffer, read_pointer, stop_pointer - read_pointer);
        read_pointer = stop_pointer;
    }
    else
    {
        int segment_right = buf + size - read_pointer;
        int segment_left = stop_pointer - buf;

        return_buffer = (uint8_t *)malloc(segment_right + segment_left);
        memcpy(return_buffer, read_pointer, segment_right);
        memcpy(return_buffer + segment_right, buf, segment_left);

        read_pointer = buf + segment_left;
    }

    return return_buffer;
}

// suppot partial reads ? how ?

// look into poll and select

int ring_buffer::size_of_next_message()
{
    // first check to see if write fits
    uint8_t *stop_pointer = stack.front();
    int buffer_size;

    if (stop_pointer > read_pointer)
    {
        buffer_size = stop_pointer - read_pointer;
    }
    else
    {
        int segment_right = buf + size - read_pointer;
        int segment_left = stop_pointer - buf;
        buffer_size = segment_left + segment_right;
    }

    return buffer_size;
}

void ring_buffer::print()
{
    std::cout << "AA \n";
}

int ring_buffer::read_bytes(void *write_buf, int read_size)
{

    uint8_t *stop_pointer = stack.front();
    int bytes_left_message = stop_pointer - read_pointer;

    // Entire message is on left side of the stop pointer
    if (stop_pointer > read_pointer)
    {
        if (bytes_left_message > read_size)
        {
            memcpy(write_buf, read_pointer, read_size);
            read_pointer += read_size;
            return size;
        }

        if (bytes_left_message <= read_size)
        {
            memcpy(write_buf, read_pointer, bytes_left_message);
            read_pointer += bytes_left_message;
            stack.pop();

            return bytes_left_message;
        }
    }
    else
    {
        bytes_left_message += size;
        int segment_right = buf + size - read_pointer;
        int segment_left = read_size - segment_right;

        if (segment_left + segment_right > read_size)
        {
            memcpy(write_buf, read_pointer, segment_right);
            memcpy(write_buf + segment_right, buf, segment_left);
            read_pointer = buf + segment_left;
            return size;
        }
        if (segment_left+ segment_right <= read_size)
        {   
            memcpy(write_buf, read_pointer, segment_right);
            bytes_left_message -= segment_right;

            memcpy(write_buf + segment_right, buf, bytes_left_message);
            read_pointer = buf + bytes_left_message;
            stack.pop();
            return bytes_left_message + segment_right;
        }
    }

}
