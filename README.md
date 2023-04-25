# C++ code illustrations for "Data Structure and Algorithms" module

**Pseudo-codes have been taken from Cormen et al., Introduction to Algorithms 2009**

To run the file, you need to download the whole folder, as header files are required to run the package.

## Doubly Linked List

The doubly linked list contains 2 pointers: backwards and forwards. My file does not implement a dummy object that marks as the beginning/end of this linked list but rather marking the head/tail pointers as null.

## Hash tables

### Hash table using chaining (doubly linked list) to resolve collision

Each position `index` in the hash table will be a doubly linked list. New `key` will be added to linked list of index `key`. However, this method can lead to non-uniform distribution.

### Hash table using linear probing to resolve collision

Only one key will be stored into one index of the table. However, if the number of key is greater than the number of index in the table, overflow will occur.

## Binary Search Tree

A node in a binary search tree consists of a `value`, its children `left` and `right` nodes, and its `parent` node. Each binary search tree contains exactly one node that acts as the root. Operations such as searching, insertion, deletion are performed on a tree.

## Red-black tree

A red-black tree is a binary tree that satisfies the following red-black properties (Cormen et al., Introduction to Algorithms 2009):

1. Every node is either red or black.
2. The root is black.
3. Every leaf (NIL) is black.
4. If a node is red, then both its children are black.
5. For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

Therefore, after insertion or deletion, it will make a apply a re-colouring process to ensure the red-black properties of the trees.
