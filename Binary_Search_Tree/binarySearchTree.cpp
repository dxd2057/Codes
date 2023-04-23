/**
 * @file binarySearchTree.cpp
 * @brief Implementation of the BinarySearchTree class.
*/
#include "Node.h"
#include "BinarySearchTree.h"
#include "TreeOperation.h"

#include <iostream>
#include <string>

/**
 * @brief Print out the menu of available commands.
*/
void printMenu() {
    std::cout << "\nAvailable commands:\n";
    std::cout << "-------------------\n";
    std::cout << "1. insert - Insert a node with a given value into the tree\n";
    std::cout << "2. delete - Delete a node with a given value from the tree\n";
    std::cout << "3. search - Search for a node with a given value in the tree\n";
    std::cout << "4. print - Print the values of the tree in traversal order\n";
    std::cout << "5. exit - Exit the program\n";
}

int main() {
    int size; // Size of the tree to generate
    std::cout << "Enter the size of the tree: ";
    std::cin >> size;
    BinarySearchTree* tree = generateRandomTree(size); // Generate a random tree

    tree->treeTraversalWalk(); // Print the tree

    // Command line interface for the tree
    std::cout << "\nBinary Search Tree Command Line Interface\n";
    std::cout << "----------------------------------------\n";

    int choice, value;
    bool exit = false;

    // Loop until the user exits the program
    while(!exit) {
        printMenu();
        std::cout << "\nEnter your choice of command: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Insert a value
                std::cout << "Enter the value to insert: ";
                std::cin >> value;
                tree->treeInsert(value);
                break;

            case 2: // Delete a value
                std::cout << "Enter the value to delete: ";
                std::cin >> value;
                if (tree->iterativeTreeSearch(value) != nullptr) {
                    tree->treeDelete(value);
                    std::cout << "Value deleted successfully.\n";
                    std::cout << "New tree: "; tree->treeTraversalWalk();
                } else {
                    std::cout << "Value not found in the tree.\n";
                }
                break;

            case 3: // Search for a value
                std::cout << "Enter the value to search for: ";
                std::cin >> value;
                if (tree->treeSearch(value) != nullptr) {
                    std::cout << "Value found.\n";
                } else {
                    std::cout << "Value not found.\n";
                }
                break;

            case 4: // Print inorder traversal
                std::cout << "Inorder traversal: ";
                tree->treeTraversalWalk();
                break;

            case 5: // Exit
                exit = true;
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}