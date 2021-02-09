#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char listOfWords[50][50];
    char firstTwoLettersOrLabel[2];
    struct Node * left;
    struct Node * right;
    int numberOfWords;
} Node;

#endif
