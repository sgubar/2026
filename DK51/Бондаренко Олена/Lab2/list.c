#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void push(Node** top_ref, char new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

char pop(Node** top_ref) {
    if (*top_ref == NULL) return '\0';
    Node* temp = *top_ref;
    char res = temp->data;
    *top_ref = temp->next;
    free(temp);
    return res;
}

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

void freeList(Node** top_ref) {
    while (*top_ref != NULL) {
        pop(top_ref);
    }
}
