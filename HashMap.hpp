#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>
using namespace std;

template<typename K, typename V>
class HashMap {
private:
    K key;
    V value;
    int capacity;
    int size;

public: 
                        HashMap();
                        HashMap(const HashMap<K, V>& other);
    HashMap<K, V>&      operator=(const HashMap<K, V>& other);
                        ~HashMap();
    void                insert(const K &key, const V &value);
    void                remove(/*USE DOUBLY LINKED LIST*/);
    V&                  operator[](const K &key);
    pair<K,V>*          search(const K &key);
};


#endif