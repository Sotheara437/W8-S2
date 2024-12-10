#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree bst;

    // Constructing the BST from the given diagram
    bst.insert(7);
    bst.insert(5);
    bst.insert(9);
    bst.insert(1);
    bst.insert(6);
    bst.insert(8);
    bst.insert(11);

    // Print the tree structure
    std::cout << "Tree structure:\n" << bst.printTree() << std::endl;

    // Perform level order traversal
    std::cout << "Level-order traversal: " << bst.levelOrderTraverse() << std::endl;

    return 0;
}
