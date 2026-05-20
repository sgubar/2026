#ifndef WORD_H
#define WORD_H

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** head, char data);
void printAndFreeList(Node** head);
void processFile(const char* filename);

#endif