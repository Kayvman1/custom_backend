#include <unistd.h>
#include <map>
#pragma once
class lru_node
{
public:
    lru_node *next;
    lru_node *prev;
    int value;
    int key;

    lru_node(int k, int v);
    lru_node();
};

class lru_cache
{
public:
    int num_elements;
    int max_size;
    lru_node *head;
    lru_node *tail;
    std::map<int, lru_node *> data;

    lru_cache(int capacity);
    int get(int key);
    void remove(lru_node *n);
    void append(lru_node *n);
    lru_node *evict();
    void put(int key, int value);
};