#ifndef DOUBLLY_LINKED_LIST_H
#define DOUBLLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"

class DoublyLinkedList {
    private:
        Node *head = NULL;
        Node *tail = NULL;
    public:
        DoublyLinkedList() = default;
        inline void insertNode(Node *new_node) {
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
            }
        }
        inline Node* searchNode(int a_key) {
            Node *current{head};

            std::cout << "\nSearching for node: " << a_key << '\n';
            while (current != NULL) {
                if (current->key == a_key) {
                    std::cout << "Found" << '\n';
                    return current;
                }
                current = current->next;
            }

            std::cout << "Not found" << '\n';
            return NULL;
        }
        inline void deleteNode(Node *node) {
            if (node == NULL) {
                std::cout << "Node is NULL\n";
                return;
            }
            if (node->prev == NULL) {
                head = node->next;
            } else {
                node->prev->next = node->next;
            }
            if (node->next == NULL) {
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