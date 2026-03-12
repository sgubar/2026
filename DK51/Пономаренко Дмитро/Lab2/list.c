#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *CreateNode(int value)
{
    Node *result = (Node *)malloc(sizeof(Node));

    if (result != NULL)
    {
        memset(result, 0, sizeof(Node));
        result->value = value;
    }
    return result;
}
void DeleteNode(Node *node)
{
    if (node != NULL)
        free(node);
}
void PrintNode(Node *node)
{
    if (node != NULL)
        printf("%d", node->value);
}

List *CreateList()
{
    List *result = malloc(sizeof(List));

    if (result != NULL)
        memset(result, 0, sizeof(List));

    return result;
}

void DeleteList(List *list)
{
    if (list == NULL)
        return;

    Node *node = list->head;

    while (node != NULL)
    {
        Node *tmp = node->next;
        DeleteNode(node);
        node = tmp;
    }

    free(list);
}

void PrintList(List *list)
{
    if (list == NULL)
        return;

    Node *node = NULL;
    printf("[");
    for (node = list->head; node != list->tail; node = node->next)
    {
        PrintNode(node);
        printf(",");
    }

    if (node != NULL)
        PrintNode(node);

    printf("]\n");
}

int AppendToList(List *list, int value)
{
    if (list == NULL || (list->head == NULL && list->head != list->tail))
        return 0;

    Node *node = CreateNode(value);
    if (node == NULL)
        return 0;

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = list->head;
        return 1;
    }

    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;

    return 1;
}

Node *FindMin(List *list)
{
    if (list == NULL || list->head == NULL)
        return NULL;

    Node *min = list->head;

    for (Node *node = list->head; node != NULL; node = node->next)
    {
        if (node->value < min->value)
            min = node;
    }

    return min;
}

Node *FindMax(List *list)
{
    if (list == NULL || list->head == NULL)
        return NULL;

    Node *max = list->head;

    for (Node *node = list->head; node != NULL; node = node->next)
    {
        if (node->value > max->value)
            max = node;
    }

    return max;
}

void Sort(List *list)
{
    if (list == NULL || list->head == NULL)
    {
        return;
    }

    Node *min = FindMin(list);
    Node *max = FindMax(list);

    Node *start = min;
    Node *end = max;

    Node *tmp = list->head;
    int found = 0;

    while (tmp != NULL)
    {
        if (tmp == min)
        {
            start = min;
            end = max;
            found = 1;
            break;
        }

        if (tmp == max)
        {
            start = max;
            end = min;
            found = 1;
            break;
        }

        tmp = tmp->next;
    }

    if (!found)
        return;

    for (Node *i = start; i != end; i = i->next)
    {
        for (Node *j = start; j != end; j = j->next)
        {
            if (j->next != NULL && j->value > j->next->value)
            {
                int temp = j->value;
                j->value = j->next->value;
                j->next->value = temp;
            }
        }
    }
}