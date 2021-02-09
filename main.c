#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"
#include "tree.h"

int main(int argc, char * argv[])
{
    FILE * input;
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
        char tmpString[2048];
        input = tmpfile();

        printf("Use Keyboard\n");
        fgets(tmpString, 2047, stdin);
        fprintf(input, "%s", tmpString);

        rewind(input);
        strcpy(outName,"output");
    }
    else
    {
        fprintf(stderr, "Incorrect Usage: Too many arguments\n");
        abort();//is this the best way to end?
    }




    Node * myNode = buildTree(input);

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



    return 0;
}