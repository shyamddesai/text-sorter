/*
 ============================================================================
 Project Name: A5-Fall-2020-Dev.c
 Program Name" sortDemo
 Author      : Ferrie
 Version     :
 Copyright   : Your copyright notice
 Description : Treesort implementation in "C".  The code below is a test
             : program for your bTree "class".
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

/**
 * Sort demo program.  Reads in text line by line and outputs the text in
 * sort order.  Uses the bTree implementation to store the input strings.
 */

int main(void) {

	char **index, *line;
	int i;
	size_t bufsize=MAXBUF;

// Start off by creating a new bTree and allocating a buffer for the getline function

	initTree();

	line=(char *)malloc(bufsize+1);
	if (line==NULL) {
		printf("Unable to allocate a buffer for reading.\n");
		return -1;
	}

// Print greeting and instructions

	printf("sortDemo - tree sort demonstration in C.\n");
	printf("Enter a text block line by line.  Blank line to exit.\n");

	while(true) {
		printf("> ");
		getline(&line,&bufsize,stdin);

// Add new string to tree, break if blank line

		if (strlen(line)!=0) {
			addNode(line);		// Add string to tree
		}
		else{
			break;
		}
	}

// If there is no text entered, print a message and exit the program

	if (getNumNodes() == 0) {
		printf("No data entered, program terminated.\n");
		return 0;
	}

// Sort via inorder traversal

	index = makeSortIndex();		// Tree sort

// Print the sorted result

	printf("Input data in sort order:\n");
	for (i=0; i<getNumNodes(); i++) printf("%s\n",index[i]);

// Deallocate tree and exit

	printf("\nDeleting bTree...\n");
	  deleteTree();
	printf("Deallocating index array...\n");
	  free(index);
	printf("Program terminated.\n");


}
