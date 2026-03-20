#include <stdio.h>
#include <string.h>
#include "list.h"

int checkBrackets() {
    Node* stack = NULL;
    char ch;
    int isBalanced = 1;

    printf("Paste your code (type '~' and press Enter to finish):\n> ");

    while ((ch = getchar()) != '~') {
        if (ch == '{' || ch == '(' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == '}' || ch == ')' || ch == ']') {
            if (stack == NULL || !isMatchingPair(pop(&stack), ch)) {
                isBalanced = 0;
            }
        }
    }

    while (getchar() != '\n');

    int finalResult = (isBalanced && stack == NULL);
    freeList(&stack);
    return finalResult;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Lab 2: Bracket Checker ---\n");
        printf("1. Check code snippet\n2. Exit\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar();

        if (choice == 2) break;
        if (choice == 1) {
            if (checkBrackets()) {
                printf("\nRESULT: SUCCESS (Balanced)\n");
            } else {
                printf("\nRESULT: FAILURE (Not Balanced)\n");
            }
        }
    }
    return 0;
}
