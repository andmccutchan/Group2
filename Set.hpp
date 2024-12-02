#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <functional>
#include "HashFunction.hpp"
#include "customexceptions.hpp"
using namespace std;

template <typename T>
class Set {
    private:
        int HSetSize;
        HashFunction<T> hash;
    public:
        vector<vector<T>> HSet;
        Set();
        Set(const Set<T>& other);
        ~Set();
        void insert(const T &value);
        void remove(const T &value);
        bool search(const T &value);
        void print() const;
};

#endif