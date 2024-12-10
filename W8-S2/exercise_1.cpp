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

    // Printing the BST structure
    std::cout << "Tree structure:\n" << bst.printTree() << std::endl;

    // Level-order traversal
    std::cout << "Level-order traversal: " << bst.levelOrderTraverse() << std::endl;

    // Searching for a value
    int searchValue = 6;
    if (bst.search(bst.getroot(), searchValue)) {
        std::cout << "Value " << searchValue << " found in the BST." << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the BST." << std::endl;
    }

    // Deleting a value
    int deleteValue = 5;
    bst.deleteNode(deleteValue);
    std::cout << "After deleting " << deleteValue << ":\n" << bst.printTree() << std::endl;

    return 0;
}
