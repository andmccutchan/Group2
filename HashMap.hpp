#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>

template<typename K, typename V>
class HashMap {
private:
    K key;
    V value;
    int capacity;
    int size;

public: 
    void insert(const K &key, const V &value);
    void remove();
    V& operator[](const K &key);
    pair<K,V>* search(const K &key);
};


#endif