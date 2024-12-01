//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Implementation file of the Hash map class. 
// It includes definition for declaring a hashmap, copy constructor,
// destructors, assignment operator, insert, remove operator, and 
// and search operator
//==============================================================
#include <iostream>
#include <utility>
#include "HashMap.hpp"
#include "HashFunction.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

//==============================================================
// default constructor
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
HashMap<K, V>::HashMap() { 
    capacity = hashFunction.getCapacity(); 
    size = 0;
    buckets = new DoublyLinkedList<pair<K, V>>[capacity]; // Create buckets using the capacity
}

//==============================================================
// Copy Constructor
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
HashMap<K, V>::HashMap(const HashMap<K, V>& other){
    capacity = other.capacity;
    size = other.size;
    buckets = new DoublyLinkedList<pair<K, V>>[capacity];
    for (int i = 0; i < capacity; i++) {
        buckets[i] = other.buckets[i];
    }
}


//==============================================================
// Assignment operator
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other) {
    if (this == &other) 
        return *this;

    delete[] buckets;

    capacity = other.capacity;
    size = other.size;
    buckets = new DoublyLinkedList<pair<K, V>>[capacity];
    for (int i = 0; i < capacity; ++i) {
        buckets[i] = other.buckets[i];
    }
    return *this;
}


//==============================================================
// Destructor
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
HashMap<K, V>::~HashMap() {
    delete[] buckets;
}


//==============================================================
// Insert operator
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
void HashMap<K, V>::insert(const K &key, const V &value) {
    int index = hashFunction.getHash(key);

    // Get the bucket corresponding to the hash index
    DoublyLinkedList<pair<K, V>>& bucket = buckets[index];

    // Check if the key already exists in the bucket
    for (int i = 0; i < bucket.length(); ++i) {
        if (bucket[i].first == key) {
            // If key exists, update its value
            bucket[i].second = value;
            return;
        }
    }

    // If key does not exist, add the new key-value pair
    bucket.append(make_pair(key, value));
    size++;
}

//==============================================================
// Remove Operator
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
void HashMap<K, V>::remove(pair<K, V>* elementToRemove) {
    if (!elementToRemove) {
        throw invalid_argument("Null pointer passed to remove");
    }

    // Find the bucket index using the key of the element
    int index = hashFunction.getHash(elementToRemove->first);
    DoublyLinkedList<pair<K, V>>& bucket = buckets[index];

    // Iterate through the bucket to locate and remove the element
    for (int i = 0; i < bucket.length(); ++i) {
        if (&bucket[i] == elementToRemove) { // Compare addresses to locate the element
            bucket.remove(i); // Remove the element from the bucket
            --size; // Decrease the size of the hash map
            return;
        }
    }

    throw runtime_error("Element not found in the bucket");
}


//==============================================================
// [] Operator
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
V& HashMap<K, V>::operator[](const K &key) {
    pair<K, V>* result = search(key);
    if (result) {
        return result->second;
    }

    // If key does not exist, insert it with a default value
    insert(key, V());
    return search(key)->second;
}


//==============================================================
// Search operator
// Huy Phan
// Set key and value to null ptr
// capacity and size to 0
// PARAMETERS:
// none
// RETURN VALUE:
// none. but create a new hashmap
//==============================================================
template <class K, class V>
pair<K,V>* HashMap<K, V>::search(const K &key) {
    int index = hashFunction.getHash(key);
    DoublyLinkedList<pair<K, V>>& bucket = buckets[index];

    for (int i = 0; i < bucket.length(); ++i) {
        if (bucket[i].first == key) {
            return &bucket[i];
        }
    }

    return nullptr; // Key not found
}

template <class K, class V>
void HashMap<K, V>::print() const {
    for (int i = 0; i < capacity; ++i) {
        cout << "Bucket " << i << ": ";
        if (buckets[i].length() == 0) {
            cout << "empty";
        } else {
            for (int j = 0; j < buckets[i].length(); ++j) {
                const auto& pair = buckets[i][j];
                cout << "[" << pair.first << ": " << pair.second << "] ";
            }
        }
        cout << endl;
    }
}








