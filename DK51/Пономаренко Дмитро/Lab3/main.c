#include <stdio.h>
#include "tree.h"

int main()
{
    Tree *tree = CreateTree();
    InsertChar(tree, 'h');
    InsertChar(tree, 'e');
    InsertChar(tree, 'l');
    InsertChar(tree, 'l');
    InsertChar(tree, 'o');

    PrintTree(tree);

    Node *o = (FindNodeByChar(tree, 'o'));
    printf("\n%c", o->value);
    Node *l = (FindNodeByChar(tree, 'l'));
    printf("\n%c", l->value);

    DestroyTree(tree);

    return 0;
}
