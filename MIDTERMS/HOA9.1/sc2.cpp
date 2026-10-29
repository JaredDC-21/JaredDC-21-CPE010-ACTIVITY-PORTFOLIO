#include <iostream>
#include "BinarySearchTree.h"

int main() {

    BinarySearchTree<int>* root = nullptr;

    insertBST(root, 2);
    insertBST(root, 3);
    insertBST(root, 9);
    insertBST(root, 18);
    insertBST(root, 0);
    insertBST(root, 1);
    insertBST(root, 4);
    insertBST(root, 5);

    std::cout << "\nPre-order Traversal: ";
    preorder(root);

    std::cout << "\nIn-order Traversal: ";
    inorder(root);

    std::cout << "\nPost-order Traversal: ";    
    postorder(root);

    return 0;
}