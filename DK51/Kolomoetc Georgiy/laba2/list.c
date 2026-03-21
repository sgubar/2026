#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void append(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail) {
        list->tail->next = newNode;
    } else {
        list->head = newNode;
    }
    list->tail = newNode;
}

void printList(const DoublyLinkedList* list) {
    if (!list->head) {
        printf("The list is empty.\n");
        return;
    }
    Node* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverseBetween(DoublyLinkedList* list, int target) {
    if (!list->head) return;

    Node* first = NULL;
    Node* last = NULL;
    Node* current = list->head;

    while (current) {
        if (current->data == target) {
            first = current;
            break;
        }
        current = current->next;
    }

    current = list->tail;
    while (current) {
        if (current->data == target) {
            last = current;
            break;
        }
        current = current->prev;
    }

    if (first == NULL || first == last) {
        printf("Element %d occurs less than twice. No changes made.\n", target);
        return;
    }

    Node* left = first->next;
    Node* right = last->prev;

    if (left == last || left == NULL || right == NULL) {
       printf("There are no elements between the first and last occurrence to swap.\n");
       return;
    }

    while (left != right && left->prev != right) {
        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        if (left == right) break;
        right = right->prev;
    }
    printf("Elements between the first and last occurrence of %d were successfully reversed.\n", target);
}

void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}
