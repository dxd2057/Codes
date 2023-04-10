#ifndef LINEAR_PROBING_HASH_TABLE_H
#define LINEAR_PROBING_HASH_TABLE_H

#include "HashTable.h"

#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Linear Probing Hash Table class: using a vector to store the data
 * @details The hash function is the same as the one in the Chaining Hash Table, except for the fact that it stores only one element per bucket
*/
class LinearProbingHashTable : public HashTable {
    private:
        std::vector<Node> hashTable;
    public:
        LinearProbingHashTable() { // Initialize the hash table with 11 buckets
            hashTable.resize(size);
        }
        ~LinearProbingHashTable() = default;
        void insertItem(Node student) override { // Insert a new student into the hash table
            int index{hashFunction(student.key)};
            int i{0};
            while (i < size) { // loop through all index in the table and check whether the bucket is empty or not
                if (hashTable[index].key == "" || hashTable[index].key == "DELETED") {
                    hashTable[index] = student;
                    return;
                }
                index = (index + 1) % size; // if the bucket is not empty, move to the next bucket until it iterates through all buckets
                ++i;
            }
            std::cout << "OVERFLOW\n\n"; // if the hash table is full, print "OVERFLOW"
        }
        void deleteItem(std::string key) override { // Delete a student from the hash table
            int index{hashFunction(key)};
            int i{0};
            while(i < size) { // loop through all index in the table and check whether the bucket is empty or not
                if (hashTable[index].key == key) { // if the bucket is not empty, check whether the key is the same as the key of the student to be deleted
                    hashTable[index].key = "DELETED"; // if the key is the same, delete the student and mark the key with special value "DELETED"
                    hashTable[index].studentName = "";
                    return;
                }
                index = (index + 1) % size; // if the bucket is not empty, move to the next bucket until it iterates through all buckets
                ++i;
            }
            std::cout << "Not found\n\n"; // if the student is not found, print "Not found"
        }
        std::string searchItem(std::string key) override { // Search for a student in the hash table
            int index{hashFunction(key)};
            int i{0};
            while (i < size) {
                if (hashTable[index].key == key) {
                    return "Found: " + hashTable[index].studentName; // if the key is the same, return the name of the student
                }
                index = (index + 1) % size; // if the bucket is not empty, move to the next bucket until it iterates through all buckets
                ++i;
            }
            return "Not found"; // if the student is not found, return "Not found"
        }
        void printHashTable() { // Print the hash table
            for (int i = 0; i < size; ++i) {
                std::cout << "--------------------\nIndex " << i << ": ";
                if (hashTable[i].key == "") { // if the bucket finds an empty value, the remaining table is empty
                    return;
                } else if (hashTable[i].key != "DELETED") { // if the bucket is not empty, print the key and the name of the student
                    std::cout << hashTable[i].key << ' ' << hashTable[i].studentName << '\n';
                } else { // if the bucket is marked with "DELETED", print "Empty"
                    std::cout << "Empty" << '\n';
                }
            }
            std::cout << '\n';
        }
};

#endif