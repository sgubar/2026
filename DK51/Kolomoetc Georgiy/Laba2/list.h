#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} DoublyLinkedList;

void initList(DoublyLinkedList* list);
void append(DoublyLinkedList* list, int data);
void printList(const DoublyLinkedList* list);
void reverseBetween(DoublyLinkedList* list, int target);
void freeList(DoublyLinkedList* list);

#endif
