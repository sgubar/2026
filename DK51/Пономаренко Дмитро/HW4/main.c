#include <stdio.h>
#include "list.h"

int main()
{
    List *list = CreateList();
    AppendToList(list, 'h');
    AppendToList(list, 'e');
    AppendToList(list, 'l');
    AppendToList(list, 'l');
    AppendToList(list, 'o');
    PrintList(list);

    RemoveElementById(list, 3);
    PrintList(list);

    InsertToListById(list, 2, 'L');
    PrintList(list);

    DeleteList(list);

    return 1;
}
