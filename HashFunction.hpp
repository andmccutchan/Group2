#ifndef HASH_FUNCTION_HPP
#define HASH_FUNCTION_HPP


#include <iostream>
using namespace std;
template <typename T>
class HashFunction {
    private:
        int tableSize;
    public:
        HashFunction() {
            tableSize = 10;
        }

        T getHash(const T& key) const {
            return key % tableSize;
        }
};

#endif