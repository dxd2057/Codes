#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    int key;
    Node *prev;
    Node *next;
    Node(int a_key): key(a_key),  prev(NULL), next(NULL) {}
};

#endif