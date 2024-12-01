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
};


#endif