#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList* create_list(void) {
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

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

void print_list(const DoubleLinkedList* list) {
    if (!list || list->size == 0) {
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

// ВАРИАНТ 8: Подвоение узлов
int duplicate_element(DoubleLinkedList* list, double target) {
    if (!list || !list->head) return 0;
    
    int count = 0;
    Node* current = list->head;
    
    while (current != NULL) {
        if (current->value == target) {
            // Создаем дубликат
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->value = target;
            new_node->prev = current;
            new_node->next = current->next;
            
            // Вставляем его после current
            if (current->next != NULL) {
                current->next->prev = new_node;
            } else {
                list->tail = new_node; // Если это был последний элемент, обновляем хвост
            }
            current->next = new_node;
            list->size++;
            count++;
            
            // ВАЖНО: перепрыгиваем через созданный дубликат, чтобы не уйти в бесконечный цикл
            current = new_node->next; 
        } else {
            current = current->next;
        }
    }
    return count;
}

double get_valid_double(const char* prompt) {
    double val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &val) == 1) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Invalid input. Please enter a valid number.\n");
    }
}

int get_valid_int(const char* prompt, int min_val) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1 && val >= min_val) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Please enter an integer >= %d.\n", min_val);
    }
}
