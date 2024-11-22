//========================================================
// customexceptions.hpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides names and definitions for the
// exceptions in the customexceptions class.
//========================================================


#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <exception>
using namespace std;

class value_not_in_tree_exception : public exception { 
public:
    const char* what() const noexcept override { 
        return "Value not found in the tree.";
    }
};

class empty_tree_exception : public exception { 
public:
    const char* what() const noexcept override { 
        return "The tree is empty.";
    }
};

class value_not_in_hashmap : public exception { 
public:
    const char* what() const noexcept override { 
        return "Value not in hash map";
    }
};


#endif 
