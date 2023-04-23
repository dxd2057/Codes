#ifndef NODE_H
#define NODE_H

/**
 * @brief Node class for Binary Search Tree
*/
class Node {
    protected:
        int data{0};
        Node* parent{nullptr}; // Parent of the node
        Node* left{nullptr}; // Left child of the node
        Node* right{nullptr}; // Right child of the node
    public:
        Node() = default;
        Node(int data) {
            this->data = data;
        }
        ~Node() = default;
        inline int getData() {
            return data;
        }
        inline Node* getParent() {
            return parent;
        }
        inline Node* getLeft() {
            return left;
        }
        inline Node* getRight() {
            return right;
        }
        inline void setParent(Node* parent) {
            this->parent = parent;
        }
        inline void setLeft(Node* left) {
            this->left = left;
        }
        inline void setRight(Node* right) {
            this->right = right;
        }
};

#endif