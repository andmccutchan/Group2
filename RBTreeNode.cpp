//========================================================
// RBTreeNode.cpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides function definitions for all of
// the methods contained within the RBTreeNode class.
//========================================================


#include "RBTreeNode.hpp"

//================================================
// DEFAULT CONSTRUCTOR
// PARAMETERS: const T& value
// DESCRIPTION: Initializes a RBTreeNode value
// RETURN: None
//================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(const T& value) {
    data = value;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = true;
}

//================================================
// PARAMETER CONSTRUCTOR
// PARAMETERS: const T& value, RBTreeNode<T>* left,
// RBTreeNode<T>* right, RBTreeNide<T>* parent
// DESCRIPTION: Initializes a RBTreeNode value
// using the given parameters
// RETURN: None
//================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(const T& value, RBTreeNode<T>* left, RBTreeNode<T>* right, RBTreeNode<T>* parent) {
    data = value;
    left = left;
    right = right;
    parent = parent;
    color = true;
}

//================================================
// COPY CONSTRUCTOR
// PARAMETERS: const RBTreeNode<T>& other
// DESCRIPTION: Initializes a RBTreeNode value
// using the parametered RBTreeNode value
// RETURN: None
//================================================
template <typename T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T>& other) {
    data = other.data;
    left = other.left;
    right = other.right;
    parent = other.parent;
    color = other.color;
}

//================================================
// ASSIGNMENT OPERATOR
// PARAMETERS: const RBTreeNode<T>& other
// DESCRIPTION: Sets the current RBTreeNode value
// equal to the parametered RBTreeNode other
// RETURN: *this
//================================================
template <typename T>
RBTreeNode<T>& RBTreeNode<T>::operator=(const RBTreeNode<T>& other) {
    if (this != &other) {
        data = other.data;
        left = other.left;
        right = other.right;
        parent = other.parent;
        color = other.color;
    }
    return *this;
}

//================================================
// TREEMIN
// PARAMETERS: None
// DESCRIPTION: Returns the smallest value in the
// BSTNode
// RETURN: track
//================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMin() {
    RBTreeNode<T>* track = this;
    while (track && track->left != nullptr) {
        track = track -> left;
    }
    return track;
}

//================================================
// TREEMAX
// PARAMETERS: None
// DESCRIPTION: Returns the largest value in the
// RBTreeNode
// RETURN: track
//================================================
template <typename T>
RBTreeNode<T>* RBTreeNode<T>::treeMax() {
    RBTreeNode<T>* track = this;
    while (track && track->right != nullptr) {
        track = track -> right;
    }
    return track;
}

//================================================
// PRINTPREORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTreeNode's items using
// preorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTreeNode<T>::printPreOrderTraversal() const {
    cout << data << " ";
    if (left != nullptr) {
        left -> printPreOrderTraversal();
    }
    if (right != nullptr) {
        right -> printPreOrderTraversal();
    }
}

//================================================
// PRINTINORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTreeNode's items using
// inorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTreeNode<T>::printInOrderTraversal() const {
    if (left != nullptr){
       left -> printInOrderTraversal();
    }
    cout << data << " ";
    if (right != nullptr){
        right -> printInOrderTraversal();
    }
}

//================================================
// PRINTPOSTORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTreeNode's items using
// postorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTreeNode<T>::printPostOrderTraversal() const {
    if (left != nullptr){
        left -> printPostOrderTraversal();
    }
    if (right != nullptr){
        right -> printPostOrderTraversal();
    }
    cout << data << " ";
}