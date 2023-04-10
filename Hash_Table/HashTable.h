#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "DoublyLinkedList.h"

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Hash Table class: template of hash table class using a vector of Doubly Linked Lists to store the data
*/
class HashTable {
    protected:
        const int size{11};
        /**
         * @brief Hash function: takes a key and returns the index of the bucket where the key should be stored
         * @param key: the key of the student
         * @return int: the index of the bucket where the key should be stored
        */
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