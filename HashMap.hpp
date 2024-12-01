//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Header file of the Hash map class. It includes
// declarations for declaring a hashmap, copy constructor,
// destructors, assignment operator, insert, remove operator, and 
// and search operator
//==============================================================
#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <iostream>
#include "DoublyLinkedList.hpp"
#include "HashFunction.hpp"
using namespace std;

template<typename K, typename V>
class HashMap {
private:
    K key;
    V value;
    int capacity;
    int size;
    DoublyLinkedList<pair<K, V>>* buckets;
    HashFunction<K> hashFunction;

public: 
                        HashMap();
                        HashMap(const HashMap<K, V>& other);
    HashMap<K, V>&      operator=(const HashMap<K, V>& other);
                        ~HashMap();
    void                insert(const K &key, const V &value);
    void                remove(pair<K, V>* elementToRemove);
    void                print() const;
    V&                  operator[](const K &key);
    pair<K,V>*          search(const K &key);
    int                getSize(){
        return size;
    }
    int                getCapacity(){
        return capacity;
    }
};


#endif