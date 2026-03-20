#include "list.h"
#include <stdlib.h>

SingleListIntElement *createSingleListIntElement(int value)
{
    SingleListIntElement *result = (SingleListIntElement *)malloc(sizeof(SingleListIntElement));

    if (NULL != result)
    {
        result->value = value;
        result->next = NULL;
    }

    return result;
}

void deleteSingleListIntElement(SingleListIntElement *element)
{
    if (NULL != element)
    {
        free(element);
    }
}

void printSingleListIntElement(SingleListIntElement *element)
{
    if (NULL != element)
    {
        printf("%d", element->value);
    }
}

IntSingleList *createIntSingleList(void)
{
    IntSingleList *result = (IntSingleList *)malloc(sizeof(IntSingleList));

    if (NULL != result)
    {
        result->head = NULL;
    }

    return result;
}

void deleteIntSingleList(IntSingleList *list)
{
    if (NULL == list)
    {
        return;
    }

    SingleListIntElement *element = list->head;

    while (NULL != element)
    {
        SingleListIntElement *tmp = element->next;
        deleteSingleListIntElement(element);
        element = tmp;
    }

    free(list);
}

void printIntSingleList(IntSingleList *list)
{

    if (NULL == list)
    {
        printf("Invalid a pointer to the list\n");
        return;
    }

    printf("[");
    for (SingleListIntElement *element = list->head; element != NULL; element = element->next)
    {
        printSingleListIntElement(element);
        if (element->next != NULL)
        {
            printf(",");
        }
    }

    printf("]\n");
}

int addIntValueToIntSingleList(IntSingleList *list, int value)
{
    if (NULL == list)
    {
        return 0;
    }

    SingleListIntElement *element = createSingleListIntElement(value);
    if (NULL == element)
    {
        return 0;
    }

    if (NULL == list->head)
    {
        list->head = element;
        return 1;
    }

    SingleListIntElement *tail = list->head;

    while (NULL != tail->next)
    {
        tail = tail->next;
    }

    tail->next = element;
    return 1;
}

void removeIdenticalItems(IntSingleList *list)
{
    if (list == NULL || list->head == NULL)
        return;

    SingleListIntElement *current = list->head;

    while (current != NULL)
    {
        SingleListIntElement *prev = current;
        SingleListIntElement *runner = current->next;

        while (runner != NULL)
        {
            if (runner->value == current->value)
            {
                prev->next = runner->next;
                free(runner);
                runner = prev->next;
            }
            else
            {
                prev = runner;
                runner = runner->next;
            }
        }

        current = current->next;
    }
}