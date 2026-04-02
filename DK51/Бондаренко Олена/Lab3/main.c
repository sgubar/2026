#include "tree.h"
#include <limits.h>


int get_safe_int(const char* prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);

        if (scanf("%d%c", &value, &term) != 2 || (term != '\n' && term != ' ')) {
            printf("Error: Invalid format! Please enter a whole number (int).\n");
            while (getchar() != '\n');
        } else {
            return value;
        }
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    printf("--- BINARY SEARCH TREE MANAGEMENT SYSTEM ---\n");


    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert element\n2. Delete element\n3. Search element\n4. Print tree (Pre-order)\n5. Exit\n");

        choice = get_safe_int("Select an option (1-5): ");

        switch (choice) {
            case 1:
                value = get_safe_int("Enter integer to INSERT: ");
                root = insert(root, value);
                printf("Operation completed.\n");
                break;
            case 2:
                value = get_safe_int("Enter integer to DELETE: ");
                root = deleteNode(root, value);
                printf("Operation completed.\n");
                break;
            case 3:
                value = get_safe_int("Enter integer to SEARCH: ");
                if (search(root, value)) printf("Result: Found!\n");
                else printf("Result: Not found.\n");
                break;
            case 4:
                printf("Tree traversal (Pre-order): ");
                if (root == NULL) printf("Tree is empty.");
                else printPreOrder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Memory cleared. Exiting program...\n");
                return 0;
            default:
                printf("Error: Invalid choice! Please select between 1 and 5.\n");
        }
    }
    return 0;
}
