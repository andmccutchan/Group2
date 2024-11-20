#ifndef HASH_FUNCTION_HPP
#define HASH_FUCNTION_HPP


#include <iostream>
using namespace std;
template <typename T>
class HashFunction {
    private:
        T key;
        int size;
    public:
        T hash;
        T getHash(T key) return key % size;
};

#endif