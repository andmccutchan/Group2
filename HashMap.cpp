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
// Default Constructor
// Initializes a new HashMap object with a default capacity set by
// the hash function. Allocates memory for the bucket array and sets
// size to 0.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
HashMap<K, V>::HashMap() { 
    capacity = hashFunction.getCapacity(); 
    size = 0;
    buckets = new DoublyLinkedList<pair<K, V>>[capacity]; // Create buckets using the capacity
}

//==============================================================
// Copy Constructor
// Creates a new HashMap object as a deep copy of another HashMap.
// PARAMETERS:
//    other - The HashMap object to copy.
// RETURN VALUE:
//    None
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
// Assignment Operator
// Assigns the contents of one HashMap to another. Frees any existing
// memory and performs a deep copy.
// PARAMETERS:
//    other - The HashMap object to copy from.
// RETURN VALUE:
//    Reference to the updated HashMap object.
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
// Frees the memory allocated for the bucket array.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
HashMap<K, V>::~HashMap() {
    delete[] buckets;
}

//==============================================================
// Insert
// Inserts a key-value pair into the hash map. If the key already exists,
// its value is updated.
// PARAMETERS:
//    key   - The key to insert or update.
//    value - The value associated with the key.
// RETURN VALUE:
//    None
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
// Remove
// Removes a key-value pair from the hash map using a pointer to the pair.
// PARAMETERS:
//    elementToRemove - A pointer to the key-value pair to remove.
// RETURN VALUE:
//    None
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
// Operator []
// Accesses the value associated with a key. If the key does not exist,
// a default value is inserted.
// PARAMETERS:
//    key - The key to access or insert.
// RETURN VALUE:
//    A reference to the value associated with the key.
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
// Search
// Searches for a key in the hash map and returns a pointer to the
// associated key-value pair if found.
// PARAMETERS:
//    key - The key to search for.
// RETURN VALUE:
//    A pointer to the key-value pair, or nullptr if not found.
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

//==============================================================
// Print
// Prints the contents of the hash map, including all key-value pairs
// in each bucket.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
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

template <class K, class V>
HashMap<K, V>::HashMap(int capacity) : hashFunction(capacity) {
    this->capacity = capacity;
    size = 0;
    buckets = new DoublyLinkedList<pair<K, V>>[capacity];
}

template <class K, class V>
vector<int> HashMap<K, V>::count_elements_per_slot() const {
    vector<int> slotCounts(capacity, 0);
    for (int i = 0; i < capacity; ++i) {
        slotCounts[i] = buckets[i].length();
    }
    return slotCounts;
}

template class HashMap<int, int>;
