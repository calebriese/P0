#ifndef PROJECTZERO_TREE_H
#define PROJECTZERO_TREE_H

#include <stdio.h> // do i need this
#include "node.h"// do i need this too?
Node *  insertNode(char word[6], Node * existingNode);
Node * createNode(char word[]);
Node * buildTree(FILE * myfile);
void printInorder(Node * root, int level, char outName[256]);
void printPreorder(Node * root, int level, char outName[256]);
void printPostorder(Node * root, int level, char outName[256]);
void printDisplay(Node * root, int level, char outName[256]);
#endif
