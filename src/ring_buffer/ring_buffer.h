#include <iostream>
#include <queue>
#define RING_SIZE 3000;
class ring_buffer
{
public:
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
    int size_of_next_message();

   
};
