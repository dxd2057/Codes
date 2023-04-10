#include "Node.h"
#include "DoublyLinkedList.h"

#include <iostream>

int main() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(4);
    Node *node3 = new Node(16);
    Node *node4 = new Node(9);

    DoublyLinkedList *list = new DoublyLinkedList();
    list->insertNode(node1);
    list->insertNode(node2);
    list->insertNode(node3);
    list->insertNode(node4);

    std::cout << "New linked list:\n";
    list->printList();

    Node *node = new Node(25);
    std::cout << "\nInserting node: " << node->key << '\n';
    list->insertNode(node);
    list->printList();

    std::cout << "\nDeleting node: " << node2->key << '\n';
    list->deleteNode(node2);
    list->printList();

    list->searchNode(16);
    list->searchNode(3);

    return 0;
}