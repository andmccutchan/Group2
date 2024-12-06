//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Header file of the Set class. Set is
// implemented by utilzing 2D vectors. It includes declarations
// for declaring a hash table by implementing a set class,
// copy constructor, destructors, insert, remove, search, and print
// methods. 
//==============================================================
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
        Set(int capacity);
        Set(const Set<T>& other);
        ~Set();
        void insert(const T &value);
        void remove(const T &value);
        bool search(const T &value);
        void print() const;

        vector<int> count_elements_per_slot() const;
};

#endif