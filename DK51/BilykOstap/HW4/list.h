#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    size_t size;
} SinglyLinkedList;

SinglyLinkedList* create_list();
void add_element(SinglyLinkedList* list, ElementType value);
void remove_by_index(SinglyLinkedList* list, size_t index);
void insert_by_index(SinglyLinkedList* list, size_t index, ElementType value);
void delete_list(SinglyLinkedList* list);
size_t get_size(SinglyLinkedList* list);
void print_list(SinglyLinkedList* list);

#endif