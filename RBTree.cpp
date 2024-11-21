//========================================================
// RBTree.cpp
// DATE: October 26th
// AUTHORS: Andrew McCutchan, Liam Kaznelson, Esther Zhang
// DESCRIPTION: Provides function definitions for all of
// the methods contained within the RBTree class.
//========================================================

#include "RBTree.hpp"
#include "customexceptions.hpp"

//================================================
// DEFAULT CONSTRUCTOR
// PARAMETERS: None
// DESCRIPTION: Initializes a value of the RBTree
// class
// RETURN: None
//================================================
template <typename T>
RBTree<T>::RBTree(){
    root = nullptr;
    nodeCount = 0;
}

//================================================
// COPY CONSTRUCTOR
// PARAMETERS: None
// DESCRIPTION: Intializes a tree through deep
// copying on another red black tree
// RETURN: None
//================================================
template <typename T>
RBTree<T>::RBTree(const RBTree<T>& other) {
    if (other.root != nullptr){
        root = copySubTree(other.root);
        nodeCount = other.nodeCount;
    }
}

//================================================
// DESTRUCTOR
// PARAMETERS: None
// DESCRIPTION: Removes instance of a red black 
// tree
// RETURN: None
//================================================
template <typename T>
RBTree<T>::~RBTree() {
    deleteSubTree(root);
    root = nullptr;
    nodeCount = 0;
}

//================================================
// ASSIGNMENT OPERATOR
// PARAMETERS: const RBTree<T>* other
// DESCRIPTION: Set the current RBTree equal to the
// parameter RBTree value
// RETURN: None
//================================================
template <typename T>
RBTree<T>& RBTree<T>::operator=(const RBTree<T>& other){
    deleteSubTree(root);
    root = copySubTree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}

//================================================
// TRANSPLANT
// PARAMETERS: RBTreeNode<T> *oldNode, 
// RBTreeNode<T> *newNode
// DESCRIPTION: Transplants the oldNode parameter
// into the newNode parameter, accounting for
// any important cases.
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode){
    if (oldNode->parent == nullptr) {
        root = newNode;
    } 
    else if (oldNode == oldNode->parent->left) {
        oldNode->parent->left = newNode;
    } 
    else {
        oldNode->parent->right = newNode;
    }
    if (newNode != nullptr) {
        newNode->parent = oldNode->parent;
    }
}

//================================================
// ISEMPTY
// PARAMETERS: None
// DESCRIPTION: Checks whether the current RBTree
// is empty or not
// RETURN: True or False
//================================================
template <typename T>
bool RBTree<T>::isEmpty() const{
    return root == nullptr;
}

//================================================
// SIZE
// PARAMETERS: None
// DESCRIPTION: Returns the size of the current
// RBTree
// RETURN: nodeCount
//================================================
template <typename T>
long RBTree<T>::size() const{
    return nodeCount;
}

//================================================
// LEFTROTATE
// PARAMETERS: RBTreeNode<T> *moveNode
// DESCRIPTION: Rotate the RBTree to the left
// RETURN: None
//================================================
template <class T>
void RBTree<T>::leftRotate(RBTreeNode<T> *moveNode) {
    RBTreeNode<T>* current = moveNode->right;
    moveNode->right = current->left;
    if (current->left != nullptr){
        current->left->parent = moveNode;
    }
    current->parent = moveNode->parent;
    if (moveNode->parent == nullptr) {
        root = current;
    }
    
    else if(moveNode == moveNode->parent->left) {
        moveNode->parent->left = current;
    }
    else {
        moveNode->parent->right = current;
    }
    current->left = moveNode;
    moveNode->parent = current;
}

//================================================
// RIGHTROTATE
// PARAMETERS: RBTreeNode<T> *moveNode
// DESCRIPTION: Rotate the RBTree to the right
// RETURN: None
//================================================
template <class T>
void RBTree<T>::rightRotate(RBTreeNode<T> *moveNode) {
   RBTreeNode<T>* current = moveNode->left;
    moveNode->left = current->right;
    if (current->right != nullptr){
        current->right->parent = moveNode;
    }
    current->parent = moveNode->parent;
    if (moveNode->parent == nullptr) {
        root = current;
    }
    
    else if(moveNode == moveNode->parent->right) {
        moveNode->parent->right = current;
    }
    else {
        moveNode->parent->left = current;
    } 
    current->right = moveNode;
    moveNode->parent = current;
}

//================================================
// INSERT
// PARAMETERS: T value
// DESCRIPTION: Inserts the value parameter into
// the current RBTree
// RETURN: newNode
//================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::insert(T value){
    RBTreeNode<T>* newNode = new RBTreeNode<T>(value);
    nodeCount++;
    RBTreeNode<T>* current = root;
    RBTreeNode<T>* valueParent = nullptr;
    while (current != nullptr) {
        valueParent = current;
        if (newNode->data < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    newNode->parent = valueParent;
    if (valueParent == nullptr) {
        root = newNode;
    }
    else if (newNode->data < valueParent->data) {
        valueParent->left = newNode;
    }
    else {
        valueParent->right = newNode;
    }
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = true;
    insertFixUp(newNode);
    return newNode;
}

//================================================
// INSERTFIXUP
// PARAMETERS: RBTreeNode<T>* node
// DESCRIPTION: Applies fixes to an RBTree node
// after insertion using established cases
// RETURN: None
//================================================
template <class T>
void RBTree<T>::insertFixUp(RBTreeNode<T>* node) {
    while (node != root && node->parent->color == true) {
        if (node->parent == node->parent->parent->left) {
            RBTreeNode<T>* uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rightRotate(node->parent->parent);
            }
        }
        else {
            RBTreeNode<T>* uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = false;
}

//================================================
// REMOVE
// PARAMETERS: T value
// DESCRIPTION: Removes the inputted value from
// the current RBTree
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::remove(T value){
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    RBTreeNode<T>* removeNode = search(value);
    if (removeNode == nullptr) {
        throw value_not_in_tree_exception();
    }

    RBTreeNode<T>* node = removeNode;
    RBTreeNode<T>* moveNode;
    bool node_color = node->color;
    
    if (removeNode->left == nullptr) {
        moveNode = removeNode->right;
        transplant(removeNode, removeNode->right);
    }
    else if (removeNode->right == nullptr) {
        moveNode = removeNode->left;
        transplant(removeNode, removeNode->left);
    }
    else {
        node = removeNode->right->treeMin();
        node_color = node->color;
        moveNode = node->right;

        if (node != removeNode->right) {
            transplant(node, node->right);
            node->right = removeNode->right;
            node->right->parent = node;
        }
        else {
            if (moveNode != nullptr) {
                moveNode->parent = node;
            }   
        }
        transplant(removeNode, node);
        node->left = removeNode->left;
        node->left->parent = node;
        node->color = removeNode->color;
    }
    delete removeNode;
    nodeCount--;
    if (node_color == false) {
        deleteFixUp(moveNode);
    }
}


//================================================
// DELETEFIXUP
// PARAMETERS: RBTreeNode<T>* moveNode
// DESCRIPTION: Applies fixes to an RBTree node
// after deletion using established cases
// RETURN: None
//================================================
template <class T>
void RBTree<T>::deleteFixUp(RBTreeNode<T>* moveNode) {
    if (moveNode == nullptr) {
        return;
    }
    while (moveNode != root && (moveNode == nullptr || (moveNode->color == false && moveNode->parent != nullptr))) {
        if (moveNode == moveNode->parent->left) {
            RBTreeNode<T>* sibling = moveNode->parent->right;
            if (sibling != nullptr && sibling->color == true) {
                sibling->color = false;
                moveNode->parent->color = true;
                leftRotate(moveNode->parent);
                sibling = moveNode->parent->right;
            }
            if ((sibling->left == nullptr || sibling->left->color == false) && 
                (sibling->right == nullptr || sibling->right->color == false)) {
                sibling->color = true;
                moveNode = moveNode->parent;
            }
            else {
                if (sibling->right == nullptr || sibling->right->color == false) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = false;
                    }
                    sibling->color = true;
                    rightRotate(sibling);
                    sibling = moveNode->parent->right;
                }
                sibling->color = moveNode->parent->color;
                moveNode->parent->color = false;
                if (sibling->right != nullptr){
                    sibling->right->color = false;
                }
                leftRotate(moveNode->parent);
                moveNode = root;
            }
        }
        else {
            RBTreeNode<T>* sibling = moveNode->parent->left;
            if (sibling != nullptr && sibling->color == true) {
                sibling->color = false;
                moveNode->parent->color = true;
                rightRotate(moveNode->parent);
                sibling = moveNode->parent->left;
            }
            if ((sibling->right == nullptr || sibling->right->color == false) &&
                (sibling->left == nullptr || sibling->left->color == false)) {
                sibling->color = true;
                moveNode = moveNode->parent;
            }
            else {
                if (sibling->left == nullptr || sibling->left->color == false) {
                    if (sibling->right != nullptr) {
                        sibling->left->color = false;
                    }
                    sibling->color = true;
                    leftRotate(sibling);
                    sibling = moveNode->parent->left;
                }
                sibling->color = moveNode->parent->color;
                moveNode->parent->color = false;
                sibling->left->color = false;
                rightRotate(moveNode->parent);
                moveNode = root;
            }
        }
    }
    if (moveNode != nullptr) {
        moveNode->color = false;
    }
}

//================================================
// SEARCH
// PARAMETERS: T value
// DESCRIPTION: Searches for the value parameter
// in the current RBTree
// RETURN: Pointer of value parameter or nullptr
//================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::search(T value) const{
    RBTreeNode<T>* current = root;
    while (current != nullptr) {
        if (current->data == value) {
            return current;
        }
        else if (value < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return nullptr;
}

//================================================
// TREEMIN
// PARAMETERS: None
// DESCRIPTION: Returns the smallest value in the
// RBTree
// RETURN: current
//================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMin() const{
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    RBTreeNode<T>* track = root;
    while (track->left != nullptr){
        track = track->left;
    }
    return track;
}

//================================================
// TREEMAX
// PARAMETERS: None
// DESCRIPTION: Returns the biggest value in the
// RBTree
// RETURN: None
//================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::treeMax() const{
    if (root == nullptr) {
        throw empty_tree_exception();
    }
    RBTreeNode<T>* track = root;
    while (track->right != nullptr){
        track = track->right;
    }
    return track;
}

//================================================
// PRINTPREORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTree's items using
// preorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::printPreOrderTraversal() const{
    if (root != nullptr){
        root -> printPreOrderTraversal();
    }
}

//================================================
// PRINTINORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTree's items using
// inorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::printInOrderTraversal() const{
    if (root != nullptr){
        root -> printInOrderTraversal();
    }
}

//================================================
// PRINTPOSTORDERTRAVERSAL
// PARAMETERS: None
// DESCRIPTION: Print the RBTree's items using
// postorder traversal
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::printPostOrderTraversal() const{
    if (root != nullptr){
        root -> printPostOrderTraversal();
    }
}

//================================================
// COPY SUBTREE
// PARAMETERS: const BSTNode<T>* node
// DESCRIPTION: Copies the inputted subtree
// into the current RBTreeNode
// RETURN: nullptr or newNode
//================================================
template <typename T>
RBTreeNode<T>* RBTree<T>::copySubTree(const RBTreeNode<T>* node){
    if (node == nullptr){
        return nullptr;
    }

    RBTreeNode<T>* newNode = new RBTreeNode<T>(node->data);
    newNode -> left = copySubTree(node->left);
    newNode -> right = copySubTree(node->right);

    return newNode;
}

//================================================
// DELETE SUBTREE
// PARAMETERS: BSTNode<T>* node
// DESCRIPTION: Delete the inputted parameter
// from the current RBTree
// RETURN: None
//================================================
template <typename T>
void RBTree<T>::deleteSubTree(RBTreeNode<T>* node){
    if (node == nullptr){
        return;
    }
    deleteSubTree(node->left);
    deleteSubTree(node->right);

    delete node;
}