#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Створення нового порожнього списку
LinkedList* createList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

// Додавання нового елементу в кінець списку
void addElement(LinkedList* list, char value) {
    if (list == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return; // Перевірка виділення пам'яті
    
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// Вилучення першого знайденого елементу за значенням
void removeElement(LinkedList* list, char value) {
    if (list == NULL || list->head == NULL) return;

    Node* current = list->head;
    Node* prev = NULL;

    // Шукаємо елемент
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // Якщо елемент не знайдено
    if (current == NULL) return;

    // Якщо елемент перший (голова)
    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next; // Вилучаємо з ланцюжка
    }

    free(current);
    list->size--;
}

// Вставка елементу за певним індексом (від 0 до size)
void insertAtIndex(LinkedList* list, int index, char value) {
    if (list == NULL || index < 0 || index > list->size) {
        printf("Error: Invalid indexc (%d).\n", index);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = value;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// Видалення всього списку та звільнення пам'яті
void deleteList(LinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(list);
}

// Отримання розміру списку
int getListSize(LinkedList* list) {
    if (list == NULL) return 0;
    return list->size;
}

// Вивід списку на екран
void printList(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("list is empty.\n");
        return;
    }

    Node* current = list->head;
    printf("list: ");
    while (current != NULL) {
        printf("'%c' -> ", current->data);
        current = current->next;
    }
    printf("NULL (size: %d)\n", list->size);
}