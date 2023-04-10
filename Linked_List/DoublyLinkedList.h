#ifndef DOUBLLY_LINKED_LIST_H
#define DOUBLLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"

/**
 * @brief DoublyLinkedList class: a doubly linked list
 * @details A doubly linked list is a linked list where each node has two pointers
 *         (one to the next node and one to the previous node)
 */
class DoublyLinkedList {
    private:
        Node *head = NULL;
        Node *tail = NULL;
    public:
        DoublyLinkedList() = default;
        /**
         * @brief Insert a node at the beginning of the list
         * @param new_node The node to be inserted
        */
        inline void insertNode(Node *new_node) {
            if (head == NULL) { // if the list is empty, set the new node as the head and the tail
                head = new_node;
                tail = new_node;
            } else { // if the list is not empty, set the new node as the head and link it to the previous head
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
            }
        }
        /**
         * @brief Search for a node in the list
         * @param a_key The key of the node to be searched for
         * @return The address of the node if it is found, NULL otherwise
        */
        inline Node* searchNode(int a_key) {
            Node *current{head};

            std::cout << "\nSearching for node: " << a_key << '\n';
            while (current != NULL) { // Loop through the list until we find the node or reach the end of the list
                if (current->key == a_key) {
                    std::cout << "Found" << '\n';
                    return current;
                }
                current = current->next;
            }

            std::cout << "Not found" << '\n';
            return NULL;
        }
        /**
         * @brief Delete a node from the list
         * @param node The address of the node to be deleted
        */
        inline void deleteNode(Node *node) {
            if (node == NULL) { // If the node is NULL, print an error message and return
                std::cout << "Node is NULL\n";
                return;
            }
            if (node->prev == NULL) { // If the node is the head, set the head to the next node
                head = node->next;
            } else {
                node->prev->next = node->next;
            }
            if (node->next == NULL) { // If the node is the tail, set the tail to the previous node
                tail = node->prev;
            } else {
                node->next->prev = node->prev;
            }
            delete node;
        }
        inline void printList() {
            Node *current{head};
            while (current != NULL) {
                std::cout << current->key << ' ';
                current = current->next;
            }
            std::cout << '\n';
        }
};

#endif