# C++ code illustrations for "Data Structure and Algorithms" module

To run the file, you need to download the whole folder, as header files are required to run the package.

## Doubly Linked List

The doubly linked list contains 2 pointers: backwards and forwards. My file does not implement a dummy object that marks as the beginning/end of this linked list but rather marking the head/tail pointers as null.

## Hash tables

### Hash table using chaining (doubly linked list) to resolve collision

Each position `index` in the hash table will be a doubly linked list. New `key` will be added to linked list of index `key`. However, this method can lead to non-uniform distribution.

### Hash table using linear probing to resolve collision

Only one key will be stored into one index of the table. However, if the number of key is greater than the number of index in the table, overflow will occur.
