//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Header file of the Hash map tree class. It includes
// declarations for declaring a hashmap, copy constructor,
// destructors, assignment operator, insert, remove operator, and 
// and search operator
//==============================================================

#ifndef HASH_MAP_TREE_HPP
#define HASH_MAP_TREE_HPP

#include <iostream>
#include "RBTree.hpp"
#include "HashFunction.hpp"
using namespace std;

template<typename K, typename V>
class HashMapTree {
private:
    int tableSize;
    int tableElements;
    RBTree<pair<K, V> >* table;
    HashFunction<K> hash;
public: 
                            HashMapTree();
                            HashMapTree(const HashMapTree<K, V>& other);
    HashMapTree<K, V>&      operator=(const HashMapTree<K, V>& other);
                            ~HashMapTree();
    void                    insert(const K &key, const V &value);
    void                    remove(const K& key);
    V&                      operator[](const K &key);
    pair<K,V>*              search(const K &key);
    void                    printMap(); // function to print out hash map
    int                     getSize() {
        return tableElements;
    }

};


#endif