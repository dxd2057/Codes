#ifndef DOUBLLY_LINKED_LIST_H
#define DOUBLLY_LINKED_LIST_H

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node {
    std::string key;
    std::string studentName;
    Node *prev;
    Node *next;
    Node() = default;
    Node(std::string name): studentName(name), prev(NULL), next(NULL) {
        const int length{5};
        for (int i = 0; i < length; ++i) {
            key += std::rand() % 26 + 65; // Generate a random uppercase letter
        }
    }
    Node(std::string key, std::string name) : key(key), studentName(name), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    private:
        Node *head = NULL;
        Node *tail = NULL;
    public:
        DoublyLinkedList() = default;
        inline void insertNode(const Node &new_node) {
            Node *node = new Node(new_node.key, new_node.studentName);

            if (head == NULL) {
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

            std::cout << "\nSearching for node: " << a_key << '\n';
            while (current != NULL) {
                if (current->key == a_key) {
                    std::cout << "Found" << '\n';
                    return current;
                }
                current = current->next;
            }
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