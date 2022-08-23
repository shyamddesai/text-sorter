/*
* bTree.h
* Created on: Nov. 15, 2020
* Author: ferrie
*/

// Any program that uses the bTree class must include "bTree.h" to access the object template
// for bNode and the corresponding function (method) definitions.

#include <stdio.h>
#include <stdlib.h>
#ifndef BTREE_H_
#define BTREE_H_

// Parameters
#define MAXBUF 100 		// Max size of string
#define false 0
#define true !false

// Structure Templates
typedef struct bN {
	char data[MAXBUF]; 	// These are the instance variables of the
	struct bN *left; 	// bNode class in the Java implementation.
	struct bN *right;
} bNode;

// Prototypes
void initTree(); 				// Initialize the bTree
void addNode(char *data); 		// Create a new node that explicitly stores a character string (not just a reference to one).
bNode *makeNode(char *data); 	// Function that allocates a bNode
char **makeSortIndex(); 		// Returns an array of pointers in sort order
void inOrder(bNode *root); 		// The recursive function - inorder traversal
void deleteTree(); 				// Deletes the bTree (all allocated nodes)
void postOrder(bNode *root); 	// Post order traversal used to delete tree nodes
int getNumNodes(); 				// Getter returns the number of nodes in the tree.

#endif /* BTREE_H_ */
