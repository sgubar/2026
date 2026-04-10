#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoublyLinkedList;

DoublyLinkedList* create_list();
void add_element(DoublyLinkedList* list, char value);
int remove_element(DoublyLinkedList* list, int index);
int insert_element_by_index(DoublyLinkedList* list, char value, int index);
void delete_list(DoublyLinkedList* list);
int get_list_size(DoublyLinkedList* list);
void print_list(DoublyLinkedList* list);

#endif
