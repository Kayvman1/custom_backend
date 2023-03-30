#include <unistd.h>
#include <map>
#include "server/client.h"
#include "lru_cache.h"
#include <iostream>

lru_node::lru_node(int k, client *v)
{
    key = k;
    value = v;

    next = NULL;
    prev = NULL;
};

lru_node::lru_node()
{
    key = -1;
    value = NULL;

    next = NULL;
    prev = NULL;
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

client *lru_cache::get(int key)
{
    std::cout << "GET LOCK" << key << std::endl;

    lock.lock();
    if (data.count(key) == 0)
    {
        lock.unlock();
        return NULL;
    }
    lru_node *n = data.at(key);
    remove(n);
    append(n);

    lock.unlock();
    std::cout << "GET UNLOCK" << key << std::endl;

    return n->value;
}

client *lru_cache::put(int key, client *value)
{
    std::cout << "PUT LOCK " << key << std::endl;

    lock.lock();

    lru_node *evicted = new lru_node();
    // evicted->value = NULL
    if (data.count(key) != 0)
    {
        lru_node *n = data.at(key);
        n->value = value;
        remove(n);
        append(n);
        lock.unlock();
        return NULL;
    }

    if (num_elements == max_size)
    {
        evicted = evict();
        data.erase(evicted->key);
    }

    lru_node *n = new lru_node();

    n->key = key;
    n->value = value;
    append(n);
    data.insert(std::pair<int, lru_node *>(key, n));

    lock.unlock();
    std::cout << "PUT UNLOCK" << key << std::endl;

    return evicted->value;
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
