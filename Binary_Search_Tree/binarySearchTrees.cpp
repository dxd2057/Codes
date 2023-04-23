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
    BinarySearchTree* tree1 = new BinarySearchTree(); // Create a tree1
    BinarySearchTree* tree2 = new BinarySearchTree(); // Create a tree2

    int size{11}; // Size of the tree to generate

    int* array1 = new int[size]{13, 6, 15, 17, 20, 9, 4, 3, 7, 2, 18};
    int* array2 = new int[size]{15, 6, 18, 17, 20, 3, 7, 13, 9, 4, 2};

    for (int i = 0; i < size; ++i) { // Insert values into the tree
        tree1->treeInsert(array1[i]);
        tree2->treeInsert(array2[i]);
    }

    // Compare the trees
    std::boolalpha(std::cout);
    std::cout << "Binary Search Tree Command Line Interface\n";
    std::cout << "----------------------------------------\n\n";
    std::cout << "Tree 1: "; tree1->treeTraversalWalk();
    std::cout << "Tree 2: "; tree2->treeTraversalWalk();
    std::cout << "--------------\n";
    std::cout << "Are the trees equal? " << compareTrees(tree1, tree2) << '\n';
    std::cout << "--------------\n";
    std::cout << "Are the trees equal using inorder traversal walk? " << treeTraversalCompare(tree1, tree2) << '\n';
    std::cout << "----------------------------------------\n";
    
    // Command line interface for the tree
    int choice, treeChoice, value;
    bool exit = false;

    BinarySearchTree *tree;

    while(!exit) {
        std::cout << "\nChoose a tree to work with (1 or 2): ";
        std::cin >> treeChoice;

        switch (choice) {
            case 1:
                tree = tree1;
                break;
            case 2:
                tree = tree2;
                break;
            default:
                std::cout << "Invalid choice. Exiting program...\n";
                return 0;
        }

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

    delete[] array1; delete[] array2;
    delete tree1; delete tree2;
    
    return 0;
}