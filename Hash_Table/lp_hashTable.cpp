#include "DoublyLinkedList.h"
#include "LinearProbingHashTable.h"
#include "KeyGenerator.h"

#include <iostream>
#include <string>
#include <cctype>

int main() {
    LinearProbingHashTable hashTable;

    Node students[30];

    srand(time(nullptr));
    for (int i = 0; i < 11; ++i) {
        std::string key = "";
        key += generateKey();
        std::string name = "Student " + std::to_string(i);
        students[i] = Node(key, name);
        hashTable.insertItem(students[i]);
    }
    hashTable.printHashTable();

    char choice;
    std::cout << "Which operations do you want to perform? Enter a character to perform the following actions:\n ";
    std::cout << "1. Insert(i) 2. Delete(d) 3. Search(s) 4. Exit(e)\n";
    std::cin >> choice;

    while (choice != 'e') {
        while (choice != 'i' && choice != 'd' && choice != 's') {
            std::cout << "Incorrect input. Please enter a valid character: ";
            std::cout << "Which operations do you want to perform? Enter a character to perform the following actions:\n ";
            std::cout << "1. Insert(i) 2. Delete(d) 3. Search(s) 4. Exit(e)\n";
            std::cin >> choice;
        }

        switch(tolower(choice)) {
            case 'i': {
                std::cout << "\nEnter the key of the student you want to insert: ";
                std::string key;
                std::getline(std::cin >> std::ws, key);
                std::cout << "Enter the name of the student you want to insert: ";
                std::string name;
                std::getline(std::cin >> std::ws, name);
                hashTable.insertItem(Node(key, name));
                hashTable.printHashTable();
                break;
            }
            case 'd': {
                std::cout << "\nEnter the key of the student you want to delete: ";
                std::string key;
                std::getline(std::cin >> std::ws, key);
                hashTable.deleteItem(key);
                hashTable.printHashTable();
                break;
            }
            case 's': {
                std::cout << "Enter the key of the student you want to search for: ";
                std::string key;
                std::getline(std::cin >> std::ws, key);
                std::cout << hashTable.searchItem(key) << "\n\n";
                break;
            }
            default:
                break;
        }

        if (choice == 'e') break;

        std::cout << "Which operations do you want to perform? Enter a character to perform the following actions:\n ";
        std::cout << "1. Insert(i) 2. Delete(d) 3. Search(s) 4. Exit(e)\n";
        std::cin >> choice;
    }

    std::cout << "Exiting program...\n";

    return 0;
}