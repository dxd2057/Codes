#ifndef DOUBLLY_LINKED_LIST_H
#define DOUBLLY_LINKED_LIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Node class: each node contains a key, a student name, and pointers to the previous and next nodes
 * @details The key is a random 5-letter string
 * @details The student name is a string
*/
struct Node {
    std::string key;
    std::string studentName;
    Node *prev;
    Node *next;
    Node() = default;
    Node(std::string key, std::string name) : key(key), studentName(name), prev(NULL), next(NULL) {}
};

/**
 * @brief Doubly Linked List class: each node contains a key, a student name, and pointers to the previous and next nodes
 * @details The key is a random 5-letter string
 * @details The student name is a string
 * @details The head and tail pointers are used to keep track of the first and last nodes in the list
 * @details The head pointer points to the first node in the list
 * @details The tail pointer points to the last node in the list
 * @details The head and tail pointers are NULL if the list is empty
 * @details The head and tail pointers are the same if the list has only one node
*/
class DoublyLinkedList {
    private:
        Node *head = NULL;
        Node *tail = NULL;
    public:
        DoublyLinkedList() = default;
        inline void insertNode(const Node &new_node) { // Insert a new node at the beginning of the list
            Node *node = new Node(new_node.key, new_node.studentName);

            if (head == NULL) { // If the list is empty
                head = node;
                tail = node;
            } else {
                head->prev = node;
                node->next = head;
                head = node;
            }
        }
        inline Node* searchNode(std::string a_key) {
            Node *current{head};

            std::cout << "\nSearching for node: " << a_key << '\n'; // Print the key of the node we are searching for
            while (current != NULL) { // Loop through the list until we find the node or reach the end of the list
                if (current->key == a_key) {
                    std::cout << "Found" << '\n';
                    return current;
                }
                current = current->next;
            }
            return NULL; // Return NULL if the node is not found
        }
        inline void deleteNode(Node *node) { // Delete a node from the list
            if (node == NULL) { // If the node is NULL
                std::cout << "Node is NULL\n";
                return;
            }
            if (node->prev == NULL) { // If the node is the first node in the list
                head = node->next;
            } else {
                node->prev->next = node->next;
            }
            if (node->next == NULL) { // If the node is the last node in the list
                tail = node->prev;
            } else {
                node->next->prev = node->prev;
            }
            delete node;
        }
        inline void printList() { // Print the list
            Node *current{head};
            while (current != NULL) {
                std::cout << current->key << ' ' << current->studentName << '\n';
                if (current == tail) { // Exit loop if current == tail
                    break;
                }
                current = current->next;
            }
            std::cout << '\n';
        }
};

#endif