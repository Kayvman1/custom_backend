#include <iostream>
#define RING_SIZE 3000;
class ring_buffer
{
public:
    uint8_t *buf;
    uint8_t *read_pointer;
    uint8_t *write_pointer;
    ring_buffer ();

    void write(void* raw_data, int len);

    int size;
};