#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Node.h"
#include <iostream>

/**
 * @brief Binary Search Tree class
 * @details This class implements a Binary Search Tree.
 * The tree is implemented using a Node class.
 * The Node class is defined in Node.h
*/
class BinarySearchTree {
    private:
        Node* root{nullptr}; // Root of the tree

        /**
         * @brief Helper function for treeInsert
         * @param node Node to start the search from
         * @param key Key to look for
        */
        inline Node* searchHelper(Node* node, int key) {
            if (node == nullptr || node->getData() == key) {
                return node;
            }
            if (key < node->getData()) {
                return searchHelper(node->getLeft(), key);
            }
            return searchHelper(node->getRight(), key);
        }

        /**
         * @brief Helper function for iterativeTreeSearch without recursion
         * @param node Node to start the search from
         * @param key Key to look for
        */
        inline Node *iterativeTreeSearchHelper(Node *node, int key) {
            while (node != nullptr && node->getData() != key) {
                if (key < node->getData()) {
                    node = node->getLeft();
                } else {
                    node = node->getRight();
                }
            }
            return node;
        }

        /**
         * @brief Transplant a subtree with another subtree
         * @param u Subtree to be replaced
         * @param v Subtree to replace u
         * @details This function replaces the subtree rooted at u with the subtree rooted at v.
        */
        inline void transplant(Node *u, Node *v) {
            if (u->getParent() == nullptr) {
                root = v;
            } else if (u == u->getParent()->getLeft()) {
                u->getParent()->setLeft(v);
            } else {
                u->getParent()->setRight(v);
            }
            if (v != nullptr) {
                v->setParent(u->getParent());
            }
        }

        /**
         * @brief deleteTree helper function
         * @param node Node to start the deletion from
         * @details This function deletes the tree recursively, starting from the node passed as argument.
        */
        inline void deleteTree(Node *node) {
            if (node != nullptr) {
                deleteTree(node->getLeft());
                deleteTree(node->getRight());
                delete node;
            }
        }
    public:
        BinarySearchTree() = default; // Default constructor

        /**
         * @brief Constructor with data
         * @param data Data to be stored in the root node
         * @details This constructor creates a tree with a root node containing the data passed as argument.
        */
        BinarySearchTree(int data) {
            root = new Node(data);
        }

        /**
         * @brief Constructor with root node
         * @param root Root node of the tree
         * @details This constructor creates a tree with the root node passed as argument.
        */
        BinarySearchTree(Node *root) {
            this->root = root;
        }

        /**
         * @brief Destructor
         * @details This destructor deletes the tree recursively.
        */
        ~BinarySearchTree() {
            deleteTree(root);
        }

        /**
         * @brief Get the root node of the tree
         * @return Root node of the tree
        */
        inline Node* getRoot() {
            return root;
        }

        /**
         * @brief search for a node in the tree, starting from the root
         * @param key Key to look for
         * @return Node with the key passed as argument, or nullptr if the key is not found
        */
        inline Node *treeSearch(int key) {
            return searchHelper(root, key);
        }

        /**
         * @brief search for a node in the tree, starting from the root, without recursion
         * @param key Key to look for
         * @return Node with the key passed as argument, or nullptr if the key is not found
        */
        inline Node *iterativeTreeSearch(int key) {
            return iterativeTreeSearchHelper(root, key);
        }

        /**
         * @brief Helper function for inorderTraversal
         * @param node Node to start the traversal from
         * @return String containing the inorder traversal of the tree
        */
        inline std::string inorderTraversal(Node* node) {
            if (node != nullptr) {
                return inorderTraversal(node->getLeft()) + std::to_string(node->getData()) + " " + inorderTraversal(node->getRight());
            }
            return "";
        }

        /**
         * @brief Print the inorder traversal of the tree
        */
        inline void treeTraversalWalk() {
            std::cout << inorderTraversal(root) << '\n';
        }

        /**
         * @brief Get the minimum node in the tree
         * @return Node with the minimum key in the tree
        */
        inline Node *treeMinimum() {
            Node *node = root;
            while (node->getLeft() != nullptr) {
                node = node->getLeft();
            }
            return node;
        }

        /**
         * @brief Get the maximum node in the tree
         * @return Node with the maximum key in the tree
        */
        inline Node *treeMaximum() {
            Node *node = root;
            while (node->getRight() != nullptr) {
                node = node->getRight();
            }
            return node;
        }

        /**
         * @brief Insert a node with the key passed as argument in the tree
         * @param key Key to be inserted in the tree
         * @details This function inserts a node with the key passed as argument in the tree.
         * The tree is not balanced after the insertion.
         * The time complexity of this function is O(h), where h is the height of the tree.
         * The worst case time complexity is O(n), where n is the number of nodes in the tree.
         * The best case time complexity is O(log n).
        */
        inline void treeInsert(int key) {
            Node *node = new Node(key);
            Node *parent = nullptr;
            Node *current = root;
            while (current != nullptr) {
                parent = current;
                if (key < current->getData()) {
                    current = current->getLeft();
                } else {
                    current = current->getRight();
                }
            }
            node->setParent(parent);
            if (parent == nullptr) {
                root = node;
            } else if (key < parent->getData()) {
                parent->setLeft(node);
            } else {
                parent->setRight(node);
            }
        }

        /**
         * @brief Delete a node with the key passed as argument from the tree
         * @param key Key to be deleted from the tree
         * @details This function deletes a node with the key passed as argument from the tree.
         * The tree is not balanced after the deletion.
         * The time complexity of this function is O(h), where h is the height of the tree.
         * The worst case time complexity is O(n), where n is the number of nodes in the tree.
         * The best case time complexity is O(log n).
         * @note This function does not check if the key passed as argument is present in the tree.
        */
        inline void treeDelete(int key) {
            Node *node = iterativeTreeSearch(key);
            if (node->getLeft() == nullptr) {
                transplant(node, node->getRight());
            } else if (node->getRight() == nullptr) {
                transplant(node, node->getLeft());
            } else {
                Node *y = node->getRight();
                while (y->getLeft() != nullptr) {
                    y = y->getLeft();
                }
                if (y->getParent() != node) {
                    transplant(y, y->getRight());
                    y->setRight(node->getRight());
                    y->getRight()->setParent(y);
                }
                transplant(node, y);
                y->setLeft(node->getLeft());
                y->getLeft()->setParent(y);
            }
            delete node;
        }
};

#endif