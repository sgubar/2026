#include <stdio.h>

typedef struct tagSingleListIntElement SingleListIntElement;

struct tagSingleListIntElement
{
    SingleListIntElement *next;
    int value;
};

SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void printSingleListIntElement(SingleListIntElement *element);

typedef struct tagIntSingleList
{
    SingleListIntElement *head;
} IntSingleList;

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);

void printIntSingleList(IntSingleList *list);
int addIntValueToIntSingleList(IntSingleList *list, int value);
void removeIdenticalItems(IntSingleList *list);