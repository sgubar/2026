#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double getSafeDouble() {
    double value;
    while (scanf("%lf", &value) != 1) {
        printf("Invalid format! Please enter a double precision number (e.g., 12.34): ");
        clearBuffer();
    }
    return value;
}

int getSafeInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Error! Please enter an integer (0-5): ");
        clearBuffer();
    }
    return value;
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        printf("\n--- Binary Tree Manager (Variant 9: Double, Post-Order) ---\n");
        printf("1. Add element\n2. Print tree (Post-order)\n3. Search\n4. Delete element\n5. Clear tree\n0. Exit\n");
        printf("Your choice: ");

        choice = getSafeInt();

        switch (choice) {
        case 1:
            printf("Enter a double value to insert: ");
            root = insert(root, getSafeDouble());
            break;
        case 2:
            printf("Tree elements (Post-order): ");
            if (!root) printf("Empty");
            else printPostOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter a double value to search: ");
            if (search(root, getSafeDouble())) printf("Status: Node found in tree.\n");
            else printf("Status: Node not found.\n");
            break;
        case 4:
            printf("Enter a double value to delete: ");
            root = deleteNode(root, getSafeDouble());
            printf("Operation completed.\n");
            break;
        case 5:
            clearTree(root);
            root = NULL;
            printf("Tree memory released.\n");
            break;
        case 0:
            clearTree(root);
            printf("Terminating program...\n");
            break;
        default:
            printf("Selection out of range!\n");
        }
    } while (choice != 0);

    return 0;
}