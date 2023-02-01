#include <unistd.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#include <string>
#include <cstring>
#include <iostream>
#include <thread>
#include <cstddef>
#include <iostream>

#include <map>
#include "lru_cache.h"

lru_node::lru_node(int k, int v)
{
    key = k;
    value = v;

    next = NULL;
    prev = NULL;
};

lru_node::lru_node()
{
    lru_node(-1, -1);
};



lru_cache::lru_cache(int capacity)
{
    max_size = capacity;
    num_elements = 0;

    head = new lru_node();
    tail = new lru_node();

    head->next = tail;
    tail->prev = head;
}

int lru_cache::get(int key)
{

    if (data.count(key) == 0)
        return -1;

    lru_node *n = data.at(key);
    remove(n);
    append(n);

    return n->value;
}

void lru_cache::remove(lru_node *n)
{
    lru_node *prev = n->prev;
    lru_node *next = n->next;

    prev->next = next;
    next->prev = prev;

    n->next = NULL;
    n->prev = NULL;

    num_elements--;
}

void lru_cache::append(lru_node *n)
{
    lru_node *prev = tail->prev;
    prev->next = n;

    n->next = tail;
    n->prev = prev;

    tail->prev = n;

    num_elements++;
}

lru_node *lru_cache::evict()
{
    lru_node *evicted = head->next;
    lru_node *new_first = evicted->next;

    head->next = new_first;
    new_first->prev = head;

    num_elements--;

    return evicted;
}

void lru_cache::put(int key, int value)
{
    if (data.count(key) != 0)
    {
        lru_node *n = data.at(key);
        n->value = value;
        remove(n);
        append(n);
        return;
    }

    if (num_elements == max_size)
    {
        data.erase(evict()->key);
    }

    lru_node *n = new lru_node();

    n->key = key;
    n->value = value;
    append(n);
    data.insert(std::pair<int, lru_node *>(key, n));
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */