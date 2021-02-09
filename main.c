#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "tree.h"

int main(int argc, char * argv[])
{
    // /users/caleb/input.txt
    FILE * input;
    char myString[256]; //what size to use?
    char outName[256];

    if (argc == 2)//FILE PROVIDED
    {
        input = fopen(argv[1], "r");
        if (!input)
        {
            fprintf(stderr, "Could not open the file.\n");
            abort(); //maybe EXIT() instead
        }
        else
        {
            //remove extension
            char * lastIndex = argv[1] + strlen(argv[1]);
            while (lastIndex > argv[1] && * lastIndex != '.')
            {
                --lastIndex;
            }

            if (lastIndex > argv[1])
            {
                *lastIndex = '\0';
            }
            strcpy(outName,argv[1]);
        }
    }
    else if (argc == 1)//READ KEYBOARD
    {
        input = stdin;
        strcpy(outName,"output");
    }
    else
    {
        fprintf(stderr, "Incorrect Usage: Too many arguments\n");
        abort();//is this the best way to end
    }




    //printf("%s", myString);
    Node * myNode = buildTree(input);
//    printf("%s\n", myNode->firstTwoLettersOrLabel);
//    printf("%s\n", myNode->listOfWords);
//    printf("%s\n", myNode->right->firstTwoLettersOrLabel);
    //printInorder(myNode);
    char pre[256];
    char post[256];
    char in[256];

    strcpy(pre,outName);
    strcpy(post,outName);
    strcpy(in,outName);

    strcat(pre,".preorder");
    strcat(post,".postorder");
    strcat(in,".inorder");


    printPreorder(myNode,0, pre);
    printPostorder(myNode,0, post);
    printInorder(myNode,0, in);

    fclose(input);
    fclose(input);
    fclose(input);
    fclose(input);

//    node_t *root = buildTree(file);
//    printPreorder(root);
//    printInorder(root);
//    printPostorder(root);
    return 0;
}