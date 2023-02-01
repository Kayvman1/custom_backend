#include <iostream>
#include <string>
#include <cstring>
#include "ring_buffer.h"
#include <mutex>

ring_buffer::ring_buffer()
{
    RING_SIZE;
    buf = (uint8_t *)malloc(3000);
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

void *ring_buffer::read(int num)
{

    printf("thread %d: has begun reading\n", num);
    void *ret = read();
    printf("thread %d: has finished reading\n", num);
    return ret;
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
        std::cout<< "buffer size allocated is: " << *read_pointer << std::endl;
        std::cout << "buf size is :" <<  buf_size << std::endl;
        memcpy(return_buffer, read_pointer, stop_pointer - read_pointer);
        read_pointer = stop_pointer;

        printf("HIT\n");  

       std::cout << return_buffer[1] <<std::endl;   
    }

    //The message wraps around
    else
    {
        // Start at the end of the buffer and count back to read pointer start
        int segment_right = buf + size - read_pointer;
        //Then count from the wrap point to stop pointer
        int segment_left = stop_pointer - buf;

        return_buffer = (uint8_t *)malloc(segment_right + segment_left);
        memcpy(return_buffer, read_pointer, segment_right);
        memcpy(return_buffer + segment_right, buf, segment_left);

        read_pointer = buf + segment_left;
        
        printf("HIT2\n");     
    }

    lock.unlock();
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

int ring_buffer::read_bytes(uint8_t *write_buf, int read_size)
{

    // if the stack is empty there is nothing to read return -1
    if (stack.empty())
    {
        return -1;
    }

    uint8_t *stop_pointer = stack.front();
    int bytes_left_message = stop_pointer - read_pointer;

    // Entire message is on left side of the stop pointer
    if (stop_pointer > read_pointer)
    {
        if (bytes_left_message > read_size)
        {
            memcpy(write_buf, read_pointer, read_size);
            read_pointer += read_size;
            return read_size;
        }

        if (bytes_left_message <= read_size)
        {
            memcpy(write_buf, read_pointer, bytes_left_message);
            read_pointer += bytes_left_message;
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
        if (segment_left + segment_right <= read_size)
        {
            memcpy(write_buf, read_pointer, segment_right);
            bytes_left_message -= segment_right;

            memcpy(write_buf + segment_right, buf, bytes_left_message);
            read_pointer = buf + bytes_left_message;
            return bytes_left_message + segment_right;
        }
    }
}
