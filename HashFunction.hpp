#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP

#include <iostream>
#include <functional>
#include <cstdlib> // For rand()
using namespace std;

template <typename T>
class HashFunction {
private:
    int capacity;  // Number of slots (buckets)
    size_t p;      // A large prime number
    size_t a, b;   // Random coefficients for hashing

public:
    // Default constructor with random `a` and `b`, and default prime
    HashFunction() : capacity(10), p(1000000007) {
        a = rand() % (p - 1) + 1; // Random a in range [1, p-1]
        b = rand() % p;           // Random b in range [0, p-1]
    }

    // Constructor with specified capacity and prime
    HashFunction(int cap, size_t prime = 1000000007) : capacity(cap), p(prime) {
        a = rand() % (p - 1) + 1;
        b = rand() % p;
    }

    // Compute hash value
    int getHash(const T& key) const {
        size_t hash;

        // Optimize hashing for integers by avoiding std::hash overhead
        if constexpr (std::is_integral<T>::value) {
            hash = key; // Directly use the key if it's an integer
        } else {
            hash = std::hash<T>{}(key); // Use std::hash for non-integer types
        }

        // Apply linear transformation: (a * hash + b) % p
        hash = (a * hash + b) % p;

        // Reduce modulo the number of slots (capacity)
        return hash % capacity;
    }

    // Getter for capacity
    int getCapacity() const {
        return capacity;
    }
};

#endif
