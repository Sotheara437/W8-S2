#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <queue>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }

    int calculateHeight() {
        return calculateHeight(root);
    }

    Node* getroot() {
        return root;
    }

    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

    // Search for a key in the tree
    bool search(Node* root, int key) {
        if (root == nullptr) {
            return false; // Key not found
        }
        if (root->data == key) {
            return true; // Key found
        }
        if (key < root->data) {
            return search(root->left, key); 
        } else {
            return search(root->right, key); 
        }
    }

    // Insert a new value into the tree
    void insert(int newValue) {
        insert(root, newValue); 
    }

    void insert(Node* root, int newValue) {
        if (newValue < root->data) {
            if (root->left == nullptr) {
                root->left = new Node(newValue); 
            } else {
                insert(root->left, newValue);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new Node(newValue); 
            } else {
                insert(root->right, newValue); 
            }
        }
    }

    // Delete a node from the tree
    void deleteNode(int value) {
        deleteNode(root, value); 
    }

    void deleteNode(Node*& root, int value) {
        if (root == nullptr) {
            return; 
        }

        if (value < root->data) {
            deleteNode(root->left, value); 
        } else if (value > root->data) {
            deleteNode(root->right, value); 
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                // No children
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                //  One child (right)
                Node* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                // One child (left)
                Node* temp = root;
                root = root->left;
                delete temp;
            } else {
                //Two children
                Node* minNode = findMin(root->right);
                root->data = minNode->data;
                deleteNode(root->right, minNode->data);
            }
        }
    }

    std::string levelOrderTraverse() {
        std::string result = "";

        if (root == nullptr) {
            return "Tree is empty.\n";
        }

        std::queue<Node*> q; 
        q.push(root);        

        while (!q.empty()) {
            Node* current = q.front(); 
            q.pop();                  
            result += std::to_string(current->data) + " "; 
            if (current->left != nullptr) {
                q.push(current->left);
            }

            // Add the right child to the queue if it exists
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        return result;
    }

private:
    void printTree(Node* node, int depth, std::string& result) { 
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};

#endif // BINARYSEARCHTREE_H
