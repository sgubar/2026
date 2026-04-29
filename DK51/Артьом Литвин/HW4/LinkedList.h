#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList();
void append(Node** head, int value);
bool removeByValue(Node** head, int value);
bool insertAtIndex(Node** head, int index, int value);
void deleteList(Node** head);
int getSize(Node* head);
void printList(Node* head);

#endif