#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>

template <typename T>
class BinarySearchTree {
public:
    T key;
    BinarySearchTree<T>* leftChild;
    BinarySearchTree<T>* rightChild;

    BinarySearchTree(const T& value): key(value), leftChild(nullptr), rightChild(nullptr) {}

    T getRootVal() const {
        return key;
    }
    BinarySearchTree<T>* getLeftChild() const {
        return leftChild;
    }
    BinarySearchTree<T>* getRightChild() const {
        return rightChild;
    }
};

template <typename T>
void insertBST(BinarySearchTree<T>*& tree, const T& value) {
    if (tree == nullptr) {
        tree = new BinarySearchTree<T>(value);
    } else if (value < tree->getRootVal()) {
        insertBST(tree->leftChild, value);
    } else if (value > tree->getRootVal()) {
        insertBST(tree->rightChild, value);
    }
}

template <typename T>
void preorder(BinarySearchTree<T>* root) {
    if (root != nullptr) {
        std::cout << root->getRootVal() << " ";
        preorder(root->getLeftChild());
        preorder(root->getRightChild());
    }
}

template <typename T>
void inorder(BinarySearchTree<T>* root) {
    if (root != nullptr) {
        inorder(root->getLeftChild());
        std::cout << root->getRootVal() << " ";
        inorder(root->getRightChild());
    }
}

template <typename T>
void postorder(BinarySearchTree<T>* root) {
    if (root != nullptr) {
        postorder(root->getLeftChild());
        postorder(root->getRightChild());
        std::cout << root->getRootVal() << " ";
    }
}

#endif