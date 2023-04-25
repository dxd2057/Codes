#ifndef NODE_H
#define NODE_H

/**
 * @brief Node class for Red Black Tree
*/
class Node {
    private:
        int data{0};
        Node* parent{nullptr};  // Parent of the node
        Node* left{nullptr};    // Left child of the node
        Node* right{nullptr};   // Right child of the node
        int color{0};   // 0 for black, 1 for red

    public:
        Node() = default;   // Default constructor
        Node(int data) {    // Constructor with data
            this->data = data;
        }
        ~Node() = default;  // Default destructor
        inline int getData() {  // Getter for data
            return data;
        }
        inline Node* getParent() {  // Getter for parent
            return parent;
        }
        inline Node* getLeft() {    // Getter for left child
            return left;
        }
        inline Node* getRight() {   // Getter for right child
            return right;
        }
        inline int getColor() { // Getter for color
            return color;
        }
        inline void setParent(Node* parent) {   // Setter for parent
            this->parent = parent;
        }
        inline void setLeft(Node* left) {   // Setter for left child
            this->left = left;
        }
        inline void setRight(Node* right) { // Setter for right child
            this->right = right;
        }
        inline void setColor(int color) {   // Setter for color
            this->color = color;
        }
};

#endif