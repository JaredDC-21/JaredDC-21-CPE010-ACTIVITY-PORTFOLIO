#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree<char>* root = new BinaryTree<char>('A');

    root->insertLeft('B');

    BinaryTree<char>* B = root->getLeftChild();

    B->insertRight('C');
    B->getRightChild()->insertRight('D');
    B->getRightChild()->getRightChild()->insertRight('E');
    B->getRightChild()->getRightChild()->getRightChild()->insertRight('F');
    B->getRightChild()->getRightChild()->getRightChild()->getRightChild()->insertRight('G');

    BinaryTree<char>* C = B->getRightChild();
    BinaryTree<char>* D = C->getRightChild();
    BinaryTree<char>* E = D->getRightChild();
    BinaryTree<char>* F = E->getRightChild();
    BinaryTree<char>* G = F->getRightChild();

    D->insertLeft('H');

    E->insertLeft('I');
    BinaryTree<char>* I = E->getLeftChild();
    I->insertRight('J');
    BinaryTree<char>* J = I->getRightChild();

    F->insertLeft('K');
    BinaryTree<char>* K = F->getLeftChild();
    K->insertRight('L');
    BinaryTree<char>* L = K->getRightChild();
    L->insertRight('M');

    G->insertLeft('N');

    J->insertLeft('P');
    BinaryTree<char>* P = J->getLeftChild();
    P->insertRight('Q');

    std::cout << "General Tree:" << std::endl;
    displayTree(root);

    std::cout << "\nPre-order Traversal: ";
    preorder(root);

    std::cout << "\nIn-order Traversal: ";
    inorder(root);

    std::cout << "\nPost-order Traversal: ";    
    postorder(root);
    
    std::cout << "\nfindData using Pre-order traversal: ";
    if (findData(root, 1, 'H')) {
        std::cout << "H is found";
    }
    else {
        std::cout << "H is missing";
    }

    std::cout << "\nfindData using In-order traversal: ";
    if (findData(root, 2, 'P')) {
        std::cout << "P is found";
    }
    else {
        std::cout << "P is missing";
    }

    std::cout << "\nfindData using Post-order traversal: ";
    if (findData(root, 3, 'Z')) {
        std::cout << "Z is found";
    }
    else {
        std::cout << "Z is missing";
    }

    G->insertLeft('O');

    std::cout << "\n\nfindData using Pre-order traversal: ";
    if (findData(root, 1, 'O')) {
        std::cout << "O is found";
    }
    else {
        std::cout << "O is missing";
    }

    std::cout << "\nfindData using In-order traversal: ";
    if (findData(root, 2, 'O')) {
        std::cout << "O is found";
    }
    else {
        std::cout << "O is missing";
    }

    std::cout << "\nfindData using Post-order traversal: ";
    if (findData(root, 3, 'O')) {
        std::cout << "O is found";
    }
    else {
        std::cout << "O is missing";
    }
    return 0;
}
