#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "DoublyLinkedList.h"

#include <iostream>
#include <vector>
#include <string>

class HashTable {
    protected:
        const int size{11};
        inline int hashFunction(std::string key) {
            int hash{0};

            for (int i = 0; i < key.length(); ++i) {
                hash += static_cast<int>(key[i]);
            }
            return hash % size;
        }
    public:
        HashTable() = default;
        ~HashTable() = default;
        virtual void insertItem(Node student) = 0;
        virtual void deleteItem(std::string key) = 0;
        virtual std::string searchItem(std::string key) = 0;
};

#endif