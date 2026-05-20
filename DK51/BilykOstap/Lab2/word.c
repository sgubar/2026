#include "word.h"
#include <stdio.h>
#include <stdlib.h>

void push(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення пам'яті\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printAndFreeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    
    while (current != NULL) {
        putchar(current->data);
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Помилка відкриття файлу");
        return;
    }

    Node* head = NULL;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\r') {
            continue;
        }
        
        if (ch == '\n') {
            printAndFreeList(&head);
            putchar('\n');
        } else {
            push(&head, (char)ch);
        }
    }
    
    if (head != NULL) {
        printAndFreeList(&head);
        putchar('\n');
    }

    fclose(file);
}