#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void push(Node** top_ref, char new_data);
char pop(Node** top_ref);
int isMatchingPair(char char1, char char2);
void freeList(Node** top_ref);

#endif
