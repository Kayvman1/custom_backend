#pragma once
#include <unistd.h>
#include <map>
#include "server/client.h"
#include <mutex>

class lru_node
{
public:
    lru_node *next;
    lru_node *prev;
    int key;
    client *value;

    lru_node(int k, client *v);
    lru_node();
};

class lru_cache
{
private:
    int num_elements;
    int max_size;
    lru_node *head;
    lru_node *tail;
    std::map<int, lru_node *> data;

    void remove(lru_node *n);
    void append(lru_node *n);
    lru_node *evict();

    std::mutex lock;

public:
    lru_cache(int capacity);
    client *get(int key);
    client *put(int key, client *value);
};