#include "HashMapTree.hpp"
#include "customexceptions.hpp"

// Constructors, Assignment Operator, Destructor
//================================================================================
template <class K, class V>
HashMapTree<K, V>::HashMapTree() {
    tableElements = 0;
    tableSize = 10;
    table = new RBTree<pair<K, V> >[tableSize];
}

template <class K, class V>
HashMapTree<K, V>::HashMapTree(const HashMapTree<K, V>& other) {
    tableElements = other.tableElements;
    tableSize = other.tableSize;
    table = new RBTree<pair<K, V> >[tableSize];

    for (int i = 0; i < tableSize; i++) {
        table[i] = other.table[i];
    }
}

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

template <class K, class V>
HashMapTree<K, V>::~HashMapTree() {
    delete[] table;
}
//================================================================================



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