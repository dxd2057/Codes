#ifndef TREE_INITIALISATION_H
#define TREE_INITIALISATION_H

#include "BinarySearchTree.h"
#include <iostream>

/**
 * @brief Generate a random array of integers
 * @param size Size of the array
 * @return Pointer to the array
*/
inline int* generateRandomArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}


/**
 * @brief Generate a random Binary Search Tree
 * @param size Size of the tree
 * @return Pointer to the tree
*/
inline BinarySearchTree* generateRandomTree(int size) {
    int* array = generateRandomArray(size);
    BinarySearchTree* tree = new BinarySearchTree(array[0]);
    for (int i = 1; i < size; i++) {
        tree->treeInsert(array[i]);
    }
    delete array;
    return tree;
}

/**
 * @brief Compare the inorder traversal of two trees
*/
bool treeTraversalCompare(BinarySearchTree* tree1, BinarySearchTree* tree2) {
    return tree1->inorderTraversal(tree1->getRoot()) == tree2->inorderTraversal(tree2->getRoot());
}


/**
 * @brief Compare two trees, whether they have the same hierachy and values
*/
bool compareTrees(BinarySearchTree* tree1, BinarySearchTree* tree2) {
    if ((tree1->getRoot() == nullptr && tree2->getRoot() != nullptr) ||
        (tree1->getRoot() != nullptr && tree2->getRoot() == nullptr) ||
        (tree1->getRoot() != nullptr && tree2->getRoot() != nullptr && tree1->getRoot()->getData() != tree2->getRoot()->getData())) {
        return false;
    }
    if (tree1->getRoot() != nullptr && tree2->getRoot() != nullptr) {
        return compareTrees(new BinarySearchTree(tree1->getRoot()->getLeft()), new BinarySearchTree(tree2->getRoot()->getLeft())) &&
            compareTrees(new BinarySearchTree(tree1->getRoot()->getRight()), new BinarySearchTree(tree2->getRoot()->getRight()));
    }
    return true;
}
#endif