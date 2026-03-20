#include <stdio.h>
#include "list.h"

void main()
{
    IntSingleList *list = createIntSingleList();
    addIntValueToIntSingleList(list, 3);
    addIntValueToIntSingleList(list, 3);
    addIntValueToIntSingleList(list, 1);
    addIntValueToIntSingleList(list, 1);
    addIntValueToIntSingleList(list, 3);
    addIntValueToIntSingleList(list, 5);
    addIntValueToIntSingleList(list, 3);
    addIntValueToIntSingleList(list, 4);
    addIntValueToIntSingleList(list, 5);

    printIntSingleList(list);
    removeIdenticalItems(list);
    printIntSingleList(list);
}