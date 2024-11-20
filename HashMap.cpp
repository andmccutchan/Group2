#include "HashMap.hpp"
#include "HashFunction.hpp"

// CONSTRUCTORS, DESTRUCTOR, ASSIGNMENT OPERATOR
//================================================================================
template <class K, class V>
HashMap<K, V>::HashMap() {
    key = nullptr;
    value = nullptr;
    capacity = 0;
    size = 0;
}

template <class K, class V>
HashMap<K, V>::HashMap(const HashMap<K, V>& other) {

}

template <class K, class V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other) {

}

template <class K, class V>
HashMap<K, V>::~HashMap() {
    
}
//================================================================================

template <class K, class V>
void HashMap<K, V>::insert(const K &key, const V &value) {

}

template <class K, class V>
void HashMap<K, V>::remove() {

}

template <class K, class V>
V& HashMap<K, V>::operator[](const K &key) {

}

template <class K, class V>
pair<K,V>* HashMap<K, V>::search(const K &key) {

}