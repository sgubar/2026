#include <stdio.h>
#include "tree.h"

int main()
{
    Tree *tree = CreateTree();
    InsertDouble(tree, 100);
    InsertDouble(tree, 50);
    InsertDouble(tree, 70);
    InsertDouble(tree, 110);
    InsertDouble(tree, 999);
    PrintTree(tree);

    printf("\n");

    DeleteNodeByDouble(tree, 110);
    PrintTree(tree);

    printf("\n");

    PrintNode(FindNodeByDouble(tree, 999));

    DestroyTree(tree);

    return 0;
}
