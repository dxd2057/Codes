#ifndef CHAINING_HASH_TABLE_H
#define CHAINING_HASH_TABLE_H

#include "HashTable.h"

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Chaining Hash Table class: using a vector of Doubly Linked Lists to store the data
 * @details The hash function is the same as the one in the Linear Probing Hash Table
 * @details The hash table is a vector of Doubly Linked Lists
*/
class ChainingHashTable : public HashTable {
    private:
        std::vector<DoublyLinkedList> hashTable;
    public:
        ChainingHashTable() {
            hashTable.resize(size); // Initialize the hash table with 11 buckets
        }
        ~ChainingHashTable() = default;
        void insertItem(Node student) override { // Insert a new student into the hash table
            int index{hashFunction(student.key)};
            hashTable[index].insertNode(student);
        }
        void deleteItem(std::string key) override { // Delete a student from the hash table
            int index{hashFunction(key)};
            hashTable[index].deleteNode(hashTable[index].searchNode(key));
        }
        std::string searchItem(std::string key) override { // Search for a student in the hash table
            int index{hashFunction(key)};
            Node *node{hashTable[index].searchNode(key)};
            if (node == NULL) {
                return "Not found";
            }
            return node->studentName;
        }
        void printHashTable() { // Print the hash table
            for (int i = 0; i < size; ++i) {
                std::cout << "--------------------\nIndex " << i << ":\n";
                hashTable[i].printList();
            }
        }
};

#endif