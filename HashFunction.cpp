#include "HashFunction.hpp"

template <class T>
HashFunction<T>::HashFunction() {
    capacity = 10;
}

template <class T>
T HashFunction<T>::getHash(const T& key) const {
    return key % capacity;
}

template class HashFunction<int>;

