#include <stdio.h>
#include "list.h"

void main()
{
    IntSingleList *list = createIntSingleList();
    addIntValueToIntSingleList(list, 1);
    addIntValueToIntSingleList(list, 1);
    addIntValueToIntSingleList(list, 1);
    addIntValueToIntSingleList(list, 2);
    addIntValueToIntSingleList(list, 2);
    addIntValueToIntSingleList(list, 6);
    addIntValueToIntSingleList(list, 6);
    addIntValueToIntSingleList(list, 6);
    addIntValueToIntSingleList(list, 5);

    printIntSingleList(list);
    removeIdenticalItems(list);
    printIntSingleList(list);
}