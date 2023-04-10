#ifndef LINEAR_PROBING_HASH_TABLE_H
#define LINEAR_PROBING_HASH_TABLE_H

#include "HashTable.h"

#include <iostream>
#include <vector>
#include <string>

class LinearProbingHashTable : public HashTable {
    private:
        std::vector<Node> hashTable;
    public:
        LinearProbingHashTable() {
            hashTable.resize(size);
        }
        ~LinearProbingHashTable() = default;
        void insertItem(Node student) override {
            int index{hashFunction(student.key)};
            int i{0};
            while (i < size) {
                if (hashTable[index].key == "" || hashTable[index].key == "DELETED") {
                    hashTable[index] = student;
                    return;
                }
                index = (index + 1) % size;
                ++i;
            }
            std::cout << "OVERFLOW\n\n";
        }
        void deleteItem(std::string key) override {
            int index{hashFunction(key)};
            int i{0};
            while(i < size) {
                if (hashTable[index].key == key) {
                    hashTable[index].key = "DELETED";
                    hashTable[index].studentName = "";
                    return;
                }
                index = (index + 1) % size;
                ++i;
            }
            std::cout << "Not found\n\n";
        }
        std::string searchItem(std::string key) override {
            int index{hashFunction(key)};
            int i{0};
            while (i < size) {
                if (hashTable[index].key == key) {
                    return "Found: " + hashTable[index].studentName;
                }
                index = (index + 1) % size;
                ++i;
            }
            return "Not found";
        }
        void printHashTable() {
            for (int i = 0; i < size; ++i) {
                std::cout << "--------------------\nIndex " << i << ": ";
                if (hashTable[i].key == "") {
                    return;
                } else if (hashTable[i].key != "DELETED") {
                    std::cout << hashTable[i].key << ' ' << hashTable[i].studentName << '\n';
                } else {
                    std::cout << "Empty" << '\n';
                }
            }
            std::cout << '\n';
        }
};

#endif