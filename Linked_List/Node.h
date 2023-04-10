#ifndef NODE_H
#define NODE_H

#include <iostream>

/**
 * @brief Node class: a node in a linked list
 * @details A node is a data structure that contains a value and a pointer to the next node
 *         and the previous node in the linked list
*/
struct Node {
    int key;
    Node *prev;
    Node *next;
    Node(int a_key): key(a_key),  prev(NULL), next(NULL) {}
};

#endif