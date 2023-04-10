#ifndef CHAINING_HASH_TABLE_H
#define CHAINING_HASH_TABLE_H

#include "HashTable.h"

#include <iostream>
#include <vector>
#include <string>

class ChainingHashTable : public HashTable {
    private:
        std::vector<DoublyLinkedList> hashTable;
    public:
        ChainingHashTable() {
            hashTable.resize(size);
        }
        ~ChainingHashTable() = default;
        void insertItem(Node student) override {
            int index{hashFunction(student.key)};
            hashTable[index].insertNode(student);
        }
        void deleteItem(std::string key) override {
            int index{hashFunction(key)};
            hashTable[index].deleteNode(hashTable[index].searchNode(key));
        }
        std::string searchItem(std::string key) override {
            int index{hashFunction(key)};
            Node *node{hashTable[index].searchNode(key)};
            if (node == NULL) {
                return "Not found";
            }
            return node->studentName;
        }
        void printHashTable() {
            for (int i = 0; i < size; ++i) {
                std::cout << "--------------------\nIndex " << i << ":\n";
                hashTable[i].printList();
            }
        }
};

#endif