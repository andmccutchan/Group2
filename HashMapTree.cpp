#include "HashMapTree.hpp"

// Constructors, Assignment Operator, Destructor
//================================================================================
template <class K, class V>
HashMapTree<K, V>::HashMapTree() {
    capacity = 10;
    size = 0;
}

template <class K, class V>
HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V>& other) {

}

template <class K, class V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V>& other) {

}

template <class K, class V>
HashMapTree<K, V>::~HashMapTree() {

}
//================================================================================



template <class K, class V>
void HashMapTree<K, V>::insert(const K &key, const V &value) {
    hash.getHash(key);
    
}

template <class K, class V>
void HashMapTree<K, V>::remove() {
    
}

template <class K, class V>
V& HashMapTree<K, V>::operator[](const K &key) {

}

template <class K, class V>
pair<K,V>* HashMapTree<K, V>::search(const K &key) {

}