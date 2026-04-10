#include <stdio.h>
#include <stdlib.h>
#include "list.h"

DoublyLinkedList* create_list() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

void add_element(DoublyLinkedList* list, char value) {
    if (list == NULL) return;
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
    list->size++;
}

int remove_element(DoublyLinkedList* list, int index) {
    if (list == NULL || list->head == NULL || index < 0 || index >= list->size) return -1;

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    free(current);
    list->size--;
    return 0;
}

int insert_element_by_index(DoublyLinkedList* list, char value, int index) {
    if (list == NULL || index < 0 || index > list->size) return -1;

    if (index == list->size) {
        add_element(list, value);
        return 0;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return -1;
    new_node->data = value;

    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    new_node->next = current;
    new_node->prev = current->prev;

    if (current->prev != NULL) {
        current->prev->next = new_node;
    } else {
        list->head = new_node;
    }
    current->prev = new_node;

    list->size++;
    return 0;
}

void delete_list(DoublyLinkedList* list) {
    if (list == NULL) return;
    Node* current = list->head;
    Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

int get_list_size(DoublyLinkedList* list) {
    if (list == NULL) return 0;
    return list->size;
}

void print_list(DoublyLinkedList* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }
    printf("List Elements: ");
    Node* current = list->head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}
