#ifndef NODE_H
#define NODE_H

typedef struct Node {
    char listOfWords[100][100]; //fixLater
    char firstTwoLettersOrLabel[2];
    struct Node * left;
    struct Node * right;
    int numberOfWords;
} Node;

#endif
