#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include "Node.h"
#include <iostream>

enum Color{BLACK, RED};

/**
 * @brief Red Black Tree class
 * @details Red Black Tree is a self-balancing binary search tree.
*/
class RedBlackTree {
    private:
        Node *root{nullptr}; // Root of the tree
        Node *nil{nullptr}; // Sentinel node

        /**
         * @brief Search for a node with a given value in the tree without recursion.
         * @param node Root of the subtree to search in.
         * @param key Value to search for.
         * @return Pointer to the node with the given value if found, else nullptr.
        */
        inline Node *iterativeTreeSearchHelper(Node *node, int key) {
            while (node != nil && node->getData() != key) {
                if (key < node->getData()) {
                    node = node->getLeft();
                } else {
                    node = node->getRight();
                }
            }
            return node;
        }

        /**
         * @brief Rotate a branch of the tree to the left.
         * @param x Root of the branch to be rotated.
         * @note Used by insertNode() function.
        */
        inline void leftRotate(Node* x) {
            Node *y = x->getRight();    // Set y
            x->setRight(y->getLeft());  // Turn y's left subtree into x's right subtree
            if (y->getLeft() != nil) {
                y->getLeft()->setParent(x);
            }
            y->setParent(x->getParent());   // Link x's parent to y
            if (x->getParent() == nil) {
                root = y;
            } else if (x == x->getParent()->getLeft()) {
                x->getParent()->setLeft(y);
            } else {
                x->getParent()->setRight(y);
            }
            y->setLeft(x);  // Put x on y's left
            x->setParent(y);
        }

        /**
         * @brief Rotate a branch of the tree to the right.
         * @param x Root of the branch to be rotated.
         * @note Used by insertNode() function.
        */
        inline void rightRotate(Node* x) {
            Node *y = x->getLeft(); // Set y
            x->setLeft(y->getRight());  // Turn y's right subtree into x's left subtree
            if (y->getRight() != nil) {
                y->getRight()->setParent(x);
            }
            y->setParent(x->getParent());   // Link x's parent to y
            if (x->getParent() == nil) {
                root = y;
            } else if (x == x->getParent()->getRight()) {
                x->getParent()->setRight(y);
            } else {
                x->getParent()->setLeft(y);
            }
            y->setRight(x); // Put x on y's right
            x->setParent(y);
        }

        /**
         * @brief Fix the tree after insertion.
         * @param z Node to be inserted.
         * @note Used by insertNode() function.
        */
        inline void insertFixup(Node* z) {
            while (z->getParent()->getColor() == RED) {
                if (z->getParent() == z->getParent()->getParent()->getLeft()) {
                    Node *y = z->getParent()->getParent()->getRight();
                    if (y->getColor() == RED) {                     // Case 1
                        z->getParent()->setColor(BLACK);            // Case 1
                        y->setColor(BLACK);                         // Case 1
                        z->getParent()->getParent()->setColor(RED); // Case 1
                        z = z->getParent()->getParent();            // Case 1
                    } else {
                        if (z == z->getParent()->getRight()) {      // Case 2
                            z = z->getParent();                     // Case 2
                            leftRotate(z);                          // Case 2
                        }
                        z->getParent()->setColor(BLACK);            // Case 3
                        z->getParent()->getParent()->setColor(RED); // Case 3
                        rightRotate(z->getParent()->getParent());   // Case 3
                    }
                } else {
                    Node *y = z->getParent()->getParent()->getLeft();
                    if (y->getColor() == RED) {
                        z->getParent()->setColor(BLACK);
                        y->setColor(BLACK);
                        z->getParent()->getParent()->setColor(RED);
                        z = z->getParent()->getParent();
                    } else {
                        if (z == z->getParent()->getLeft()) {
                            z = z->getParent();
                            rightRotate(z);
                        }
                        z->getParent()->setColor(BLACK);
                        z->getParent()->getParent()->setColor(RED);
                        leftRotate(z->getParent()->getParent());
                    }
                }
            }
            root->setColor(BLACK);
        }

        /**
         * @brief Transplant a branch of the tree.
         * @details Replace a branch of the tree with another branch.
         * @param u Root of the branch to be replaced.
         * @param v Root of the branch to be replaced with.
        */
        inline void transplant(Node* u, Node* v) {
            if (u->getParent() == nil) {
                root = v;
            } else if (u == u->getParent()->getLeft()) {
                u->getParent()->setLeft(v);
            } else {
                u->getParent()->setRight(v);
            }
            v->setParent(u->getParent());
        }

        /**
         * @brief Fix the tree after deletion.
         * @param x Node to be deleted.
         * @note Used by deleteNode() function.
        */
        inline void deleteFixup(Node* x) {
            while (x != root && x->getColor() == BLACK) {
                if (x == x->getParent()->getLeft()) {
                    Node *w = x->getParent()->getRight();
                    if (w->getColor() == RED) {                    // Case 1
                        w->setColor(BLACK);
                        x->getParent()->setColor(RED);
                        leftRotate(x->getParent());
                        w = x->getParent()->getRight();
                    }
                    if (w->getLeft()->getColor() == BLACK && w->getRight()->getColor() == BLACK) {  // Case 2
                        w->setColor(RED);
                        x = x->getParent();
                    } else {
                        if (w->getRight()->getColor() == BLACK) {   // Case 3
                            w->getLeft()->setColor(BLACK);
                            w->setColor(RED);
                            rightRotate(w);
                            w = x->getParent()->getRight();
                        }
                        w->setColor(x->getParent()->getColor());    // Case 4
                        x->getParent()->setColor(BLACK);
                        w->getRight()->setColor(BLACK);
                        leftRotate(x->getParent());
                        x = root;
                    }
                } else {
                    Node *w = x->getParent()->getLeft();
                    if (w->getColor() == RED) {
                        w->setColor(BLACK);
                        x->getParent()->setColor(RED);
                        rightRotate(x->getParent());
                        w = x->getParent()->getLeft();
                    }
                    if (w->getRight()->getColor() == BLACK && w->getLeft()->getColor() == BLACK) {
                        w->setColor(RED);
                        x = x->getParent();
                    } else {
                        if (w->getLeft()->getColor() == BLACK) {
                            w->getRight()->setColor(BLACK);
                            w->setColor(RED);
                            leftRotate(w);
                            w = x->getParent()->getLeft();
                        }
                        w->setColor(x->getParent()->getColor());
                        x->getParent()->setColor(BLACK);
                        w->getLeft()->setColor(BLACK);
                        rightRotate(x->getParent());
                        x = root;
                    }
                }
            }
            x->setColor(BLACK);
        }

        /**
         * @brief Find the node with the minimum value in a branch of the tree.
         * @param x Root of the branch.
         * @return Node with the minimum value.
         * @note Used by deleteNode() function.
        */
        inline Node* treeMinimum(Node *x) {
            while (x->getLeft() != nil) {
                x = x->getLeft();
            }
            return x;
        }

        /**
         * @brief Find the node with the maximum value in a branch of the tree.
         * @param x Root of the branch.
         * @return Node with the maximum value.
        */
        inline Node* treeMaximum(Node *x) {
            while (x->getRight() != nil) {
                x = x->getRight();
            }
            return x;
        }

        /**
         * @brief Delete the whole tree recursively.
         * @param node Root of the branch to be deleted.
         * @note Used by destructor.
        */
        inline void deleteTree(Node* node) {
            if (node != nil) {
                deleteTree(node->getLeft());
                deleteTree(node->getRight());
                delete node;
            }
            return;
        }

        /**
         * @brief Display the tree recursively.
         * @param node Root of the branch to be displayed.
         * @param indent Indentation of the branch.
         * @return String containing the tree.
         * @note Used by display() function.
        */
        inline std::string displayHelper(Node* node, int indent = 0) {
            std::string result = "";
            if (node != nil) {
                result += displayHelper(node->getRight(), indent + 4);
                if (indent != 0) {
                    result += std::string(indent, ' ');
                }
                result += std::to_string(node->getData());
                if (node->getColor() == RED) {
                    result += "(R)\n";
                } else {
                    result += "(B)\n";
                }
                result += displayHelper(node->getLeft(), indent + 4);
            }
            return result;
        }
    public:
        /**
         * @brief Constructor.
         * @details Create a new RedBlackTree object.
         * @note The tree is empty at the beginning.
        */
        RedBlackTree() {
            nil = new Node(0);
            nil->setColor(BLACK);
            root = nil;
        }

        /**
         * @brief Destructor.
         * @details Delete the whole tree.
        */
        ~RedBlackTree() {
            deleteTree(root);
            delete nil;
        }

        inline Node *getRoot() { // get the root of the tree
            return root;
        }
        inline Node* getNil() { // get the nil of the tree
            return nil;
        }

        /**
         * @brief Search for the node with the given key.
         * @param key Key of the node to be searched.
         * @return Node with the given key.
        */
        inline Node* searchNode(int key) {
            return iterativeTreeSearchHelper(root, key);
        }

        /**
         * @brief Insert a new node in the tree.
         * @param key Key of the node to be inserted.
         * @note Complexity: O(log n)
        */
        inline void insertNode(int key) {
            Node* y = nil;
            Node* x = root;
            while (x != nil) {
                y = x;
                if (key < x->getData()) {
                    x = x->getLeft();
                } else {
                    x = x->getRight();
                }
            }
            Node* z = new Node(key);
            z->setParent(y);
            if (y == nil) {
                root = z;
            } else if (z->getData() < y->getData()) {
                y->setLeft(z);
            } else {
                y->setRight(z);
            }
            z->setLeft(nil);
            z->setRight(nil);
            z->setColor(RED);
            insertFixup(z);
        }

        /**
         * @brief Delete a node from the tree.
         * @param key Key of the node to be deleted.
         * @note If the node is not found, a message is displayed.
         * @note Complexity: O(log n)
        */
        inline void deleteNode(int key) {
            Node *z = searchNode(key); // Find the node to delete in the tree.
            if (z == nil) {
                std::cout << "Value not found in the tree.\n";
                return;
            }
            Node *y = z;
            int y_original_color = y->getColor();
            Node *x;
            if (z->getLeft() == nil) {
                x = z->getRight();
                transplant(z, z->getRight());
            } else if (z->getRight() == nil) {
                x = z->getLeft();
                transplant(z, z->getLeft());
            } else {
                y = treeMinimum(z->getRight());
                y_original_color = y->getColor();
                x = y->getRight();
                if (y->getParent() == z) {
                    x->setParent(y);
                } else {
                    transplant(y, y->getRight());
                    y->setRight(z->getRight());
                    y->getRight()->setParent(y);
                }
                transplant(z, y);
                y->setLeft(z->getLeft());
                y->getLeft()->setParent(y);
                y->setColor(z->getColor());
            }
            if (y_original_color == BLACK) {
                deleteFixup(x);
            }
            delete z;
            std::cout << "Value " << key << " sucessfully deleted from the tree.\n";
        }

        /**
         * @brief Display the tree.
         * @param indent Indentation of the tree.
        */
        inline void display(int indent = 0) {
            std::cout << "Red-black tree:\n";
            std::cout << displayHelper(root, indent);
        }
};

#endif