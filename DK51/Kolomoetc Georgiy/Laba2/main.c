#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int getIntInput(const char* prompt) {
    int value;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            } else {
                printf("Error: please enter a valid integer!\n");
            }
        }
    }
}

int main() {
    DoublyLinkedList list;
    initList(&list);

    printf("--- Laboratory Work No. 2. Variant 7 ---\n");
    printf("Topic: Linked Lists.\n\n");

    int n = -1;
    while (n < 0) {
        n = getIntInput("Enter the number of list elements (non-negative integer): ");
        if (n < 0) {
            printf("Error: the number of elements cannot be less than 0.\n");
        }
    }

    for (int i = 0; i < n; i++) {
        char prompt[50];
        snprintf(prompt, sizeof(prompt), "Enter element [%d]: ", i + 1);
        int val = getIntInput(prompt);
        append(&list, val);
    }

    printf("\nInitial list: ");
    printList(&list);

    if (n > 0) {
        int target = getIntInput("\nEnter the target element to reverse the list between its occurrences: ");
        reverseBetween(&list, target);

        printf("List after processing: ");
        printList(&list);
    } else {
        printf("\nThe list is empty, processing is impossible.\n");
    }

    freeList(&list);
    printf("\nMemory freed. Program execution finished.\n");
    return 0;
}
