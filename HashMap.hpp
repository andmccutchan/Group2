#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>
#include <vector>
#include "DoublyLinkedList.hpp"
#include "HashFunction.hpp"

using namespace std;

template <typename K, typename V>
class HashMap {
private:
    int capacity;
    int size;
    DoublyLinkedList<pair<K, V>>* buckets;

public:
    HashFunction<K> hashFunction;

    HashMap();
    HashMap(int capacity);
    HashMap(const HashMap<K, V>& other);
    HashMap<K, V>& operator=(const HashMap<K, V>& other);
    ~HashMap();

    void insert(const K& key, const V& value);
    void remove(pair<K, V>* elementToRemove);
    V& operator[](const K& key);
    pair<K, V>* search(const K& key);

    void print() const;
    vector<int> count_elements_per_slot() const;

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

#endif
