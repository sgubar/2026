#pragma once

#define MAX_LEN 100

// Вузол списку
typedef struct Node {
    char word[MAX_LEN];
    struct Node* next;
} Node;


int isValidWord(char *str);
int wordLength(char *str);
Node* append(Node* head, char *word);
void freeList(Node* head);
void printList(Node* head);
void sortByLength(Node* head);
void printMaxLengthWords(Node* head);