#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"
#include <string.h>

// "Instance" Variables - global to all functions in the bTree.c file.
bNode *root=NULL; // bTree root node
int numNodes=0; // Number of nodes in tree
int recCount=0; // Count variable for use in recursions
char **indexArray; // index array for tree sort

void initTree() {
	root = NULL;
	numNodes = 0;
}

void addNode(char *data) {
	bNode *current;
	if (root == NULL) {
		root = makeNode(data);
//		printf("Root node created\n");
	}
	else {
		current = root;
		while(true) {
			if(strcasecmp(data,current->data)<0) {
				if(current->left == NULL) {
					current->left = makeNode(data);
//					printf("Left node created\n");
					break;
				}
				else current = current->left;
			}
			else {
				if(current->right == NULL) {
					current->right = makeNode(data);
//					printf("Right node created\n");
					break;
				}
				else {
					current = current->right;
				}
			}
		}
	}
}

bNode *makeNode(char *data) {
	bNode *node = (bNode *)malloc(sizeof(bNode));
	strcpy(node->data, data);
	node->left = NULL;
	node->right = NULL;
	numNodes++;
	return node;
}

//bTree traversal
void inOrder(bNode *root) {
	if (root->left != NULL){
		inOrder(root->left);
	}
	indexArray[recCount++] = root->data;
//	printf(root->data);
	if (root->right != NULL) {
		inOrder(root->right);
	}
}

//deletes all the nodes in the bTree
void postOrder(bNode *root) {
	if (root->left != NULL) {
		postOrder(root->left);
	}
	if (root->right != NULL) {
		postOrder(root->right);
	}
	free(root);
//	printf(root->data);
}

char **makeSortIndex() {
	indexArray = (char**)malloc(sizeof(char *)*numNodes); // Index array ~ instance variable
	recCount = 0;
	inOrder(root);
	return indexArray;
}

//getter method that returns the number of nodes in the bTree
int getNumNodes() {
	return numNodes;
}

void deleteTree() {
	postOrder(root);
}

//if (getNumNodes()==0) {
//	prinf("No data entered, program terminated.\n");
//	return 0;
//}
