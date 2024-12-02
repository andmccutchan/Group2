//==============================================================
// Names: Huy Phan, Namu Kim, Andrew Mccutchan
// Class: CS 271
// Project: 3
// Date: Nov 2024
// About: This file is the Implementation file of the Hash map tree class. 
// It includes definition for declaring a hashmaptree, copy constructor,
// destructors, assignment operator, insert, remove operator, and 
// and search operator
//==============================================================



#include "HashMapTree.hpp"
#include "customexceptions.hpp"

// Constructors, Assignment Operator, Destructor
//================================================================================

//==============================================================
// Default Constructor
// Initializes a new HashMapTree object with a default capacity set by
// the hash function. Allocates memory for the bucket array and sets
// size to 0.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
HashMapTree<K, V>::HashMapTree() {
    tableElements = 0;
    tableSize = 10;
    table = new RBTree<pair<K, V> >[tableSize];
}


//==============================================================
// Copy Constructor
// Creates a new HashMapTree object as a deep copy of another HashMap.
// PARAMETERS:
//    other - The HashMap object to copy.
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V>& other) {
    tableElements = other.tableElements;
    tableSize = other.tableSize;
    table = new RBTree<pair<K, V> >[tableSize];

    for (int i = 0; i < tableSize; i++) {
        table[i] = other.table[i];
    }
}


//==============================================================
// Assignment Operator
// Assigns the contents of one HashMapTree to another. Frees any existing
// memory and performs a deep copy.
// PARAMETERS:
//    other - The HashMap object to copy from.
// RETURN VALUE:
//    Reference to the updated HashMap object.
//==============================================================
template <class K, class V>
HashMapTree<K, V>& HashMapTree<K, V>::operator=(const HashMapTree<K, V>& other) {
    delete[] table;

    tableElements = other.tableElements;
    tableSize = other.tableSize;
    table = new RBTree<pair<K, V> >[tableSize];

    for (int i = 0; i < tableSize; i++) {
        table[i] = other.table[i];
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
HashMapTree<K, V>::~HashMapTree() {
    delete[] table;
}
//================================================================================


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
void HashMapTree<K, V>::insert(const K &key, const V &value) {
    int index = hash.getHash(key);
    RBTree<pair<K, V> >& tree = table[index];

    RBTreeNode<pair<K, V> >* node = tree.search(make_pair(key, value));

    if (node) {
        node->data.second = value;
        // cout << "Updated node with existing key: " << "(" << node->data.first << ", " << node->data.second << ")" << endl;
    }
    else {
        tree.insert(make_pair(key, value));
        tableElements++;
        // cout << "Inserted new node: " << "(" << newNode.first << ", " << newNode.second << ")" << endl;
    }

}


//==============================================================
// Remove
// Removes a key-value pair from the hash map using a pointer to the pair.
// PARAMETERS:
//    A pointer to the key to remove.
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
void HashMapTree<K, V>::remove(const K &key) {
    int index = hash.getHash(key);
    RBTree<pair<K, V> >& tree = table[index];
    RBTreeNode<pair<K, V> >* node = tree.search(make_pair(key, V()));

    if(node != nullptr) {
        tree.remove(make_pair(key, V()));
        tableElements--;
    }
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
V& HashMapTree<K, V>::operator[](const K &key) {
    int index = hash.getHash(key);
    RBTree<pair<K, V> >& tree = table[index];
    RBTreeNode<pair<K, V> >* node = tree.search(make_pair(key, V()));
    
    if (node) {
        return node->data.second;
    }
    else {
        throw value_not_in_hashmap();
    }
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
pair<K,V>* HashMapTree<K, V>::search(const K &key) {
    int index = hash.getHash(key);
    RBTree<pair<K, V> >& tree = table[index];

    RBTreeNode<pair<K, V> >* node = tree.search(make_pair(key, V()));
    if (node != nullptr) {
        return &node->data;
    }

    return nullptr;
}


//==============================================================
// printMap
// Prints the contents of the hash map, including all key-value pairs
// in each bucket.
// PARAMETERS:
//    None
// RETURN VALUE:
//    None
//==============================================================
template <class K, class V>
void HashMapTree<K, V>::printMap() {
    for (int i = 0; i < tableSize; i++) {  
        if (table[i].isEmpty()) {
            cout << i << ": -> Null" << endl;
        }
        else {
            cout << i << ": ";
            table[i].printInOrderTraversal();
            cout << endl;
        }
    }
}

template class HashMapTree<int, int>;