//========================================================
// BSTNode.hpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides names of all members of the
// BSTNode class.
//========================================================


#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include "RBTreeNode.hpp"
using namespace std;

template <class T>
class RBTree {
private:
    RBTreeNode<T>* root;
    long nodeCount;

    void deleteSubTree(RBTreeNode<T>* node);                //helper function to delete nodes
    RBTreeNode<T>* copySubTree(const RBTreeNode<T>* node);  //helper function for copying nodes of a tree
    void deleteFixUp(RBTreeNode<T>* moveNode);
    void leftRotate(RBTreeNode<T>* moveNode);
    void rightRotate(RBTreeNode<T>* moveNode);
    void insertFixUp(RBTreeNode<T>* node);

public:
                    RBTree();
                    RBTree(const RBTree<T>& other);
                    ~RBTree();
    RBTree<T>&      operator=(const RBTree<T>& other);

    void            transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode);
    bool            isEmpty() const;
    long            size() const;
    RBTreeNode<T>*  insert(T value);
    void            remove(T value);
    RBTreeNode<T>*  search(T value) const;
    RBTreeNode<T>*  treeMin() const;
    RBTreeNode<T>*  treeMax() const;
    void            printPreOrderTraversal() const;
    void            printInOrderTraversal() const;
    void            printPostOrderTraversal() const;

};

#endif