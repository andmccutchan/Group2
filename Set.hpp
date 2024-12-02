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
        vector<vector<T>> HSet;
        int HSetSize;
        HashFunction<T> hash;
    public:
        Set();
        Set(const Set<T>& other);
        ~Set();
        void insert(const T &value);
        void remove(const T &value);
        bool search(const T &value);
        int size() const;
        void print() const;
};

#endif