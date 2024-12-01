#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP

#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class HashFunction {
private:
    int capacity;

public:
    // Default constructor
    HashFunction() : capacity(10) {}


    HashFunction(int cap) : capacity(cap) {}

    // Compute hash value
    int getHash(const T& key) const {
        return std::hash<T>{}(key) % capacity; // Use std::hash for general keys
    }

    // Getter for capacity
    int getCapacity() const {
        return capacity;
    }
};

#endif
