#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#define RING_SIZE 3000;
class ring_buffer
{
public:
    std::recursive_mutex read_lock;
    std::recursive_mutex write_lock;
    uint8_t *buf;
    uint8_t *read_pointer;
    uint8_t *write_pointer;
    std::queue<uint8_t *> stack;
    int size;

    // MAYBE NO SIZE ARRAY OF END INDICES ?
    // Make a queue and pop off

    ring_buffer();
    ring_buffer(int l);

    void print();
    void write(void *raw_data, uint16_t len);
    void *read();
    int read_bytes(void *buf, int size);
    int size_of_next_message();

};
