#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "node.h"

Node * buildTree(FILE * myfile)
{
    Node * root = NULL;

    char word[1024];
    while (fscanf(myfile, " %1023s", word) == 1)
    {
        root = insertNode(word, root);
    }
    fclose(myfile);

    return root;
}

Node * createNode(char word[])
{

    Node * p = (Node *)malloc(sizeof(Node));
    p->firstTwoLettersOrLabel[0] = word[0];
    p->firstTwoLettersOrLabel[1] = word[1];
    strcpy(p->listOfWords[0],word);
    p->numberOfWords = 1;
    p->left = NULL;
    p->right = NULL;

    return p;
}

Node * insertNode(char word[6], Node * existingNode)
{
    char firstTwo[3];
    firstTwo[0] = word[0];
    firstTwo[1] = word[1];

    if (existingNode == NULL)
    {
        return createNode(word);
    }
    else if (strcmp(existingNode->firstTwoLettersOrLabel,firstTwo) > 0) //go to the left of existing
    {
        existingNode->left = insertNode(word, existingNode->left);
    }
    else if (strcmp(existingNode->firstTwoLettersOrLabel,firstTwo) < 0) //go to the right of existing
    {
        existingNode->right = insertNode(word, existingNode->right);
    }
    else if (strcmp(existingNode->firstTwoLettersOrLabel,firstTwo) == 0) //equal
    {
        strcat(existingNode->listOfWords[existingNode->numberOfWords], word); //ADD CHECK FOR ALREADY EXISTING LATER, idk if correct cast
        existingNode->numberOfWords += 1;
    }
    return existingNode;
}

void printInorder(Node * root, int level, char outName[256])
{
    if(root!=NULL)
    {
        printInorder(root->left, level+1,outName);
        printDisplay(root,level,outName);
        printInorder(root->right, level+1,outName);
    }
}

void printPreorder(Node * root, int level, char outName[256])
{
    if(root!=NULL)
    {
        printDisplay(root,level,outName);
        printPreorder(root->left, level+1,outName);
        printPreorder(root->right, level+1,outName);
    }
}

void printPostorder(Node * root, int level, char outName[256])
{
    if(root!=NULL)
    {
        printInorder(root->left, level+1,outName);
        printInorder(root->right, level+1,outName);
        printDisplay(root,level,outName);
    }
}

void printDisplay(Node * root, int level, char outName[256])
{
    FILE * outfile = fopen(outName, "a");
    fprintf(outfile, "Depth:%d, ", level * 2);
    fprintf(outfile, "Level:%d, ", level);
    fprintf(outfile, "NodeLetters:%s\n", root->firstTwoLettersOrLabel);
    for (int i = 0; i < root->numberOfWords; i++)
    {
        fprintf(outfile, " %s \n", root->listOfWords[i]);
    }
    fclose(outfile);

    printf("Depth:%d, ", level * 2);
    printf("Level:%d, ", level);
    printf("NodeLetters:%s\n", root->firstTwoLettersOrLabel);
    for (int i = 0; i < root->numberOfWords; i++)
    {
        printf(" %s \n", root->listOfWords[i]);
    }
}