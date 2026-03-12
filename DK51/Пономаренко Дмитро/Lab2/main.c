#include "list.h"
#include <stdio.h>

void main()
{
    List *list = CreateList();

    AppendToList(list, 1);
    AppendToList(list, 4);
    AppendToList(list, 3);
    AppendToList(list, 2);
    AppendToList(list, 5);

    // printf("Max: %d\n", FindMax(list)->value);
    // printf("Min: %d\n", FindMin(list)->value);

    PrintList(list);
    Sort(list);
    PrintList(list);

    DeleteList(list);
}
