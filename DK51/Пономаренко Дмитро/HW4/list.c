#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *CreateNode(char value)
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
        printf("%c", node->value);
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
    for (node = list->head; node != NULL; node = node->next)
    {
        PrintNode(node);
        if (node->next != NULL)
            printf(",");
    }

    printf("]\n");
}

int RemoveElementById(List *list, int id)
{
    if (list == NULL || list->head == NULL || id < 0)
        return -1;

    Node *node = list->head;

    if (id == 0)
    {
        list->head = node->next;
        DeleteNode(node);
        return 1;
    }

    Node *prev = NULL;
    int i = 0;

    while (node != NULL && i < id)
    {
        prev = node;
        node = node->next;
        i++;
    }

    if (node == NULL)
        return -1;

    prev->next = node->next;
    DeleteNode(node);

    return 1;
};

int InsertToListById(List *list, int id, char value)
{
    if (list == NULL || id < 0)
        return 0;

    if (id == 0)
    {
        Node *node = CreateNode(value);
        if (node == NULL)
            return 0;

        node->next = list->head;
        list->head = node;
        return 1;
    }

    Node *current = list->head;
    int i = 0;

    while (current != NULL && i < id - 1)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
        return 0;

    Node *node = CreateNode(value);
    if (node == NULL)
        return 0;

    node->next = current->next;
    current->next = node;

    return 1;
};

int AppendToList(List *list, char value)
{
    if (list == NULL)
        return 0;

    Node *node = CreateNode(value);
    if (node == NULL)
        return 0;

    if (list->head == NULL)
    {
        list->head = node;
        return 1;
    }

    Node *lastElement = list->head;

    while (lastElement->next != NULL)
        lastElement = lastElement->next;

    lastElement->next = node;
    return 1;
}