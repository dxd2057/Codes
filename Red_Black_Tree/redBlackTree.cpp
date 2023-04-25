/**
 * @file redBlackTree.cpp
 * @brief Implementation of the RedBlackTree class.
*/
#include "Node.h"
#include "RedBlackTree.h"
#include <iostream>

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

/**
 * @brief Generate a sample tree.
 * @return Pointer to the generated tree.
*/
RedBlackTree* generateSampleTree() {
    RedBlackTree* tree = new RedBlackTree();
    int size{8};
    int* array = new int[size]{11, 14, 2, 1, 7, 5, 8, 15};
    for (int i = 0; i < size; i++) {
        tree->insertNode(array[i]);
    }
    delete [] array;
    return tree;
}

int main() {
    RedBlackTree *tree = generateSampleTree(); // Generate a sample tree
    tree->display(); // Print the tree

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
                tree->insertNode(value);
                tree->display();
                break;

            case 2: // Delete a value
                std::cout << "Enter the value to delete: ";
                std::cin >> value;
                if (tree->searchNode(value) != tree->getNil()) {
                    tree->deleteNode(value);
                    std::cout << "Value deleted successfully.\n";
                    std::cout << "New tree: "; tree->display();
                } else {
                    tree->deleteNode(value);
                }
                break;

            case 3: // Search for a value
                std::cout << "Enter the value to search for: ";
                std::cin >> value;
                if (tree->searchNode(value) != tree->getNil()) {
                    std::cout << "Value found.\n";
                    std::cout << tree->searchNode(value)->getData() << '\n';
                } else {
                    std::cout << "Value not found.\n";
                }
                break;

            case 4: // Print inorder traversal
                tree->display();
                break;

            case 5: // Exit
                exit = true;
                break;

            default: // Invalid choice
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    delete tree;
    return 0;
}