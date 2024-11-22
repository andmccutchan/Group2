#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP


#include <iostream>
using namespace std;
template <typename T>
class HashFunction {
    private:
        int capacity;
    public:
        HashFunction();
        T getHash(const T& key) const;
};

#endif