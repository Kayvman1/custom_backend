#include <iostream>
#include <string>
#include <cstring>
#include "ring_buffer.h"
#include <mutex>
#include <unistd.h>
#include <errno.h>
#include "spdlog/spdlog.h"

ring_buffer::ring_buffer()
{
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

uint16_t ring_buffer::write_buf(uint8_t *raw_data, uint16_t len)
{
    // SEGMENT 1 AND 2
    //  first check to see if write fits
    int segment_right = buf + size - write_pointer;
    int segment_left = len - segment_right;

    int bytes_written = 0; // TODO should I use this and count when I write, or just return len?

    if (segment_right >= len)
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
    return len;
}

// HAVE The caller pass in a buffer and write to it.
// Think about what to do if buffer passed in is two small
void ring_buffer::read_buf(int read_len, uint8_t *return_buffer)
{

    uint8_t *stop_pointer = read_pointer + read_len;

    if (stop_pointer > buf + size)
    {
        stop_pointer -= size;
    }

    // The entire message is in order
    if (stop_pointer > read_pointer)
    {
        memcpy(return_buffer, read_pointer, read_len);
    }

    // The message wraps around
    else
    {
        // Start at the end of the buffer and count back to read pointer start
        int segment_right = buf + size - read_pointer;
        // Then read the rest of the message
        int segment_left = read_len - segment_right;

        memcpy(return_buffer, read_pointer, segment_right);
        memcpy(return_buffer + segment_right, buf, segment_left);
    }

    read_pointer = stop_pointer;
}

int helper(int read_bytes, int len);
int ring_buffer::write_from_socket(int sockfd, int len)
{
    // SEGMENT 1 AND 2
    //  first check to see if write fits
    int segment_right = buf + size - write_pointer;
    int segment_left = len - segment_right;
    int read_bytes;

    int bytes_written = 0; // TODO should I use this and count when I write, or just return len?

    if (segment_right >= len)
    {
        read_bytes = read(sockfd, write_pointer, len);
        write_pointer = write_pointer + read_bytes;

        if (helper(read_bytes, len) == -1)

            return -1;

        return read_bytes;
    }
    else
    {
        read_bytes = read(sockfd, write_pointer, segment_right);
        write_pointer += read_bytes;

        if (helper(read_bytes, segment_right) == -1)
            return -1;

        read_bytes += read(sockfd, buf, segment_left);
        if (helper(read_bytes, len) == -1)
            return -1;
    }

    // this is possible verify this TODO
    if (write_pointer > buf + size)
    {
        write_pointer -= size;
    }
    return 1;
}

int helper(int read_bytes, int len)
{

    // Real error on reading
    if (errno != EAGAIN && read_bytes == -1)
    {
        spdlog::debug("Errno {}: ", errno);
        return -1;
    }

    // Poll event was disconnect
    if (read_bytes == 0)
    {
        spdlog::debug("Connection closed");
        return -1;
    }

    // Expected a message length that is longer than actual payload
    if (read_bytes < len)
    {
        if (errno != EWOULDBLOCK)
        {
            spdlog::error("Expected {}, but read {}", len, read_bytes);
            return read_bytes;
        }
        else
        {
            return read_bytes;
        }
    }
}

int ring_buffer::contigious_bytes_remaining()
{
    return buf + size - write_pointer;
}

uint8_t *ring_buffer::expose_write_pointer()
{
    return write_pointer;
}