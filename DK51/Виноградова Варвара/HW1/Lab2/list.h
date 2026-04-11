#ifndef LIST_H
#define LIST_H

// Оголошення структури вузла
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Оголошення функцій
int getValidInt();
void insertEnd(Node** head, int data);
void printList(Node* head);
int getCount(Node* head);
void deleteEveryThird(Node** head);
void freeList(Node** head);

#endif