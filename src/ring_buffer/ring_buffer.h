#pragma once 
//#ifndef __RING_BUFFER__
//#define __RING_BUFFER__
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#define RING_SIZE 3000;
class ring_buffer
{
public:
    uint8_t *buf;
    uint8_t *read_pointer;
    uint8_t *write_pointer;
    
    int size = RING_SIZE;

    ring_buffer();
    ring_buffer(int l);

    uint16_t write_buf(uint8_t *raw_data, uint16_t len);
    void read_buf(int len, uint8_t * out_buf);
    
    int write_from_socket(int sockfd, int len);

    int contigious_bytes_remaining();
    uint8_t* expose_write_pointer();

    void inc_read_pointer(int bytes);
    void read_buf_from_pointer (int len, uint8_t * read_loc, uint8_t *return_buffer);
};
//#endif
 