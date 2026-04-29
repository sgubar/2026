#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node* createList() {
    return NULL;
}

void append(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

bool removeByValue(Node** head, int value) {
    if (*head == NULL) return false;

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return true;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        return true;
    }

    return false;
}

bool insertAtIndex(Node** head, int index, int value) {
    if (index < 0) return false;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return false;

    newNode->data = value;

    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return true;
    }

    Node* current = *head;
    int currentIndex = 0;

    while (current != NULL && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        free(newNode);
        return false;
    }

    newNode->next = current->next;
    current->next = newNode;
    return true;
}

void deleteList(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int getSize(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}