//
//  ParallelBTree.hpp
//  ParallelBTree
//
//  Created by Vinicius Henrique Moraes on 09/12/2019.
//  Copyright © 2019 Vinicius Henrique Moraes. All rights reserved.
//

#ifndef ParallelBTree_hpp
#define ParallelBTree_hpp

#include <iostream>

#endif

// A BTree node
class ParallelBTreeNode
{
    int *keys; // An array of keys
    int t;     // Minimum degree (defines the range for number of keys)
    ParallelBTreeNode **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    ParallelBTreeNode(int _t, bool _leaf); // Constructor
    
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    
    // A utility function to split the child y of this node. i is index of y in
    // child array C[]. The Child y must be full when this function is called
    void splitChild(int i, ParallelBTreeNode *y);
    
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
    
    // A function to search a key in the subtree rooted with this node.
    ParallelBTreeNode *search(int k); // returns NULL if k is not present.
    
    // Make BTree friend of this so that we can access private members of this
    // class in BTree functions
    friend class ParallelBTree;
};


// A BTree
class ParallelBTree
{
    ParallelBTreeNode *root; // Pointer to root node
    int t; // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    ParallelBTree(int _t)
    { root = NULL; t = _t; }
    
    // function to traverse the tree
    void traverse()
    { if (root != NULL) root->traverse(); }
    
    // function to search a key in this tree
    ParallelBTreeNode* search(int k);
    
    // The main function that inserts a new key in this B-Tree
    void insert(int k);
    
    void threadSearch(ParallelBTreeNode* node, int k);
};
