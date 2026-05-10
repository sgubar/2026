#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// створення порожнього списку
SinglyLinkedList* create_list() {
    SinglyLinkedList* list = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (list) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

// додавання елементу в кінець списку
void add_element(SinglyLinkedList* list, ElementType value) {
    if (!list) return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
}

// вставка елементу за індексом
void insert_by_index(SinglyLinkedList* list, size_t index, ElementType value) {
    if (!list || index > list->size) return;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    new_node->data = value;

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node* current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->size++;
}

// вилучення елементу за індексом
void remove_by_index(SinglyLinkedList* list, size_t index) {
    if (!list || list->head == NULL || index >= list->size) return;

    Node* temp;
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node* current = list->head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }
    free(temp);
    list->size--;
}

size_t get_size(SinglyLinkedList* list) {
    return list ? list->size : 0;
}

// вивід списку на екран
void print_list(SinglyLinkedList* list) {
    if (!list) return;
    Node* current = list->head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

// видалення списку та звільнення п
void delete_list(SinglyLinkedList* list) {
    if (!list) return;
    Node* current = list->head;
    Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}