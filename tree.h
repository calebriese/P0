#include <stdio.h>
#include "node.h"

#ifndef TREE_H
#define TREE_H

Node *  insertNode(char word[6], Node * existingNode);
Node * createNode(char word[]);
Node * buildTree(FILE * myfile);
void printInorder(Node * root, int level, char outName[256]);
void printPreorder(Node * root, int level, char outName[256]);
void printPostorder(Node * root, int level, char outName[256]);
void printDisplay(Node * root, int level, char outName[256]);

#endif
