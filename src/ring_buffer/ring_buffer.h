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
    std::mutex lock;
    uint8_t *buf;
    uint8_t *read_pointer;
    uint8_t *write_pointer;
    std::queue<uint8_t *> stack;
    
    int size = RING_SIZE;

    ring_buffer();
    ring_buffer(int l);

    uint16_t write(uint8_t *raw_data, uint16_t len);
    void *read();
};
//#endif
 