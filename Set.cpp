//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Implementation file of the Set class. It includes
// implementations for declaring a hash table by implementing a set class,
// copy constructor, destructors, insert, remove, search, and print
// methods. 
//==============================================================
#include<iostream>
#include "Set.hpp"
// #include <random>

//==============================================================
// Default Constructor
// Initializes a new Set object with a default size set by
// the hash function.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
Set<T>::Set(){
    HSetSize = hash.getCapacity();
    HSet.resize(HSetSize);
}

template <typename T>
Set<T>::Set(int capacity) : hash(capacity) {
    this->HSetSize = capacity;
    HSetSize = hash.getCapacity();
    HSet.resize(HSetSize);
}

//==============================================================
// Copy Constructor
// Creates a deep copy of a Set object.
// PARAMETERS:
//    other - Set object to copy.
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
Set<T>::Set(const Set<T>& other){
    HSetSize = other.HSetSize;
    HSet = other.HSet;
    hash = other.hash;
}

//==============================================================
// Destructor
// Frees memory by first clearing all values then clearing space
// for the sets.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
Set<T>::~Set(){
    HSet.clear();
    HSet.shrink_to_fit();
}

//==============================================================
// print
// Prints the contents of the hash set in a neat visual representation.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
void Set<T>::print() const{
    // traverses the hash set using indexes.
    cout << "\n***Hash Set***" << endl;
    for (int i = 0; i < HSet.size(); i++){
        cout << "Index " << i << ": { "; //start of subset
        for (int j = 0; j < HSet[i].size(); j++){
            cout << HSet[i][j] << " ";
        }
        cout << "}" << endl; // end of subset
    }
}

//==============================================================
// insert
// Inserts value of type T into hash set. It prevents duplicate 
// values while also dealing with collisions through chaining.
// PARAMETERS:
//    value - element to be inserted into hash table of type T.
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
void Set<T>::insert(const T& value){
    int index = hash.getHash(value); // find key using Hashfunction
    auto& chain = HSet[index]; // single vector subset within the 2D structure

    if(chain.empty()){ // if key is empty.
        chain.push_back(value);
    }
    else{ //if collision occurs
        for (auto i = chain.begin(); i != chain.end(); i++){
            if(*i == value){ // value already exists as first element
                // cout << value << " is already in hash set" << endl;
                break;
            }
            else{ // not duplicate of first element, check the rest.
                i++;
                if(*i == value){ // checking the next element of subset (if it exists)
                    // cout << value << " is already in hash set" << endl;;
                    break;
                }
                else{ // empty slot, insert value
                    chain.push_back(value);
                    break;
                }
            }
        }
    }
}


//==============================================================
// remove
// Removes a value from the hash set. Throws key_exception if the
// value does not exist within the hash set.
// PARAMETERS:
//    value - element to be removed, type T
// RETURN VALUE:
//    None
//==============================================================
template <typename T>
void Set<T>::remove(const T& value){
    int index = hash.getHash(value);
    auto& chain = HSet[index];

    if (chain.empty()){ // empty hash set
         throw key_exception();
    }
    else{ // if there are elements present, iterate until value is found
        int j = 0; // index for aid because loop uses iterator
        for (auto i = chain.begin(); i != chain.end(); i++){
            if (*i == value){ // value is first element
                chain.erase(chain.begin()+j);
                break;
            }
            if (j == chain.size()){ // finished subset but could not find value
                throw key_exception();
            }
            j++;
        }
    }
}

//==============================================================
// search
// Boolean method that tells whether or not value is present within
// the hash set.
// PARAMETERS:
//    value - element to search for of type T.
// RETURN VALUE:
//    true or false.
//==============================================================
template <typename T>
bool Set<T>::search(const T& value){
    int index = hash.getHash(value);
    auto& chain = HSet[index];

    if (chain.empty()){ 
        return false;
    }
    else{
        for (auto i = chain.begin(); i != chain.end(); i++){
            if (*i == value){
                return true;
            }
        }
    }
    return false;
}

// For Analysis
template <class K>
vector<int> Set<K>::count_elements_per_slot() const {
    vector<int> slotCounts(HSetSize, 0);
    for (int i = 0; i < HSetSize; ++i) {
        slotCounts[i] = HSet[i].size(); // use chain
    }
    return slotCounts;
}

// main(){

//     Set<int> hset;
//     // hset.insert(1);
//     // hset.insert(3);
//     // hset.insert(5);
//     // hset.insert(13);
//     // hset.insert(11);
//     // hset.insert(1);
//     // hset.insert(53);
//     // hset.print();
//     // hset.remove(11);
//     // hset.print();
//     // hset.remove(33);
//     // hset.print();
//     // hset.remove(5);

//     random_device rd;  // Non-deterministic random number generator
//     mt19937 gen(rd()); // Mersenne Twister engine
//     uniform_int_distribution<int> dist(1, 10); // Distribution for numbers between 1 and 100 (adjust as needed)

//     int n = 100;
//     int m = 0;
//     vector<int> randomNumbers(n);
//     // vector<int> wrongNumbers(n);
//     for (int i = 0; i < n; ++i) {
//         randomNumbers[i] = dist(gen);
//         hset.insert(randomNumbers[i]);
//     }

//     hset.print();

//     for (int i = 0; i < n; i++){
//         //n = dist(gen);
//         //wrongNumbers[i] = randomNumbers[i]*-1;
//         m = randomNumbers[i];
//         // cout << "Searching for " << m << "... ";
//         if(hset.search(m)){
//             // cout << "FOUND" << endl;
//         }
//         else{
//             cout << "NOT_FOUND" << endl;
//         }
//     }

//     for (int i = 0; i < n; ++i) {;
//         hset.remove(randomNumbers[i]);
//     }

//     hset.print();

// // Testing non found values
//         for (int i = 0; i < n; i++){
//         //n = dist(gen);
//         m = randomNumbers[i];
//         // cout << "Searching for " << m << "... ";
//         if(hset.search(m)){
//             cout << "FOUND" << endl;
//         }
//         else{
//             // cout << "NOT_FOUND" << endl;
//         }
//     }

// }