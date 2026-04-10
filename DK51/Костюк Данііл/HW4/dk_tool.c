#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

// 1. Створення списку
DoubleLinkedList* create_list(void) {
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

// 2. Видалення списку (очищення пам'яті)
void delete_list(DoubleLinkedList* list) {
    if (!list) return;
    
    Node* current = list->head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }
    free(list);
}

// 3. Розмір списку
int get_size(const DoubleLinkedList* list) {
    if (!list) return 0;
    return list->size;
}

// 4. Додавання нового елементу (в кінець)
void add_element(DoubleLinkedList* list, double value) {
    if (!list) return;
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return;
    
    new_node->value = value;
    new_node->next = NULL;
    
    if (list->size == 0) {
        new_node->prev = NULL;
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// 5. Вставка елементу по індексу
int insert_element(DoubleLinkedList* list, int index, double value) {
    if (!list || index < 0 || index > list->size) return 0;
    
    if (index == list->size) {
        add_element(list, value);
        return 1;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) return 0;
    new_node->value = value;
    
    if (index == 0) {
        new_node->prev = NULL;
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    } else {
        Node* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }
    list->size++;
    return 1;
}

// 6. Вилучення елементу зі списку
int remove_element(DoubleLinkedList* list, int index) {
    if (!list || index < 0 || index >= list->size) return 0;
    
    Node* target = list->head;
    
    if (index == 0) {
        list->head = target->next;
        if (list->head) {
            list->head->prev = NULL;
        } else {
            list->tail = NULL;
        }
    } else if (index == list->size - 1) {
        target = list->tail;
        list->tail = target->prev;
        list->tail->next = NULL;
    } else {
        for (int i = 0; i < index; i++) {
            target = target->next;
        }
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }
    
    free(target);
    list->size--;
    return 1;
}

// 7. Вивід списку на екран
void print_list(const DoubleLinkedList* list) {
    if (!list) {
        printf("List does not exist.\n");
        return;
    }
    if (list->size == 0) {
        printf("List is empty.\n");
        return;
    }
    
    printf("List (size %d): [ ", list->size);
    Node* current = list->head;
    while (current != NULL) {
        printf("%.2f ", current->value);
        current = current->next;
    }
    printf("]\n");
}
