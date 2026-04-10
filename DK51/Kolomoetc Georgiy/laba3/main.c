#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int get_safe_int(const char* prompt) {
    int val;
    int status;
    while (1) {
        printf("%s", prompt);
        status = scanf("%d", &val);
        if (status == 1) {
            clear_input_buffer();
            return val;
        } else {
            printf("Error: Invalid input. Please enter an integer.\n");
            clear_input_buffer();
        }
    }
}

double get_safe_double(const char* prompt) {
    double val;
    int status;
    while (1) {
        printf("%s", prompt);
        status = scanf("%lf", &val);
        if (status == 1) {
            clear_input_buffer();
            return val;
        } else {
            printf("Error: Invalid input. Please enter a valid number (e.g., 10.5).\n");
            clear_input_buffer();
        }
    }
}

int main() {
    BinaryTree* my_tree = create_tree();
    int choice = -1;
    double val;
    Node* found;

    printf("--- Binary Tree Manager (Double / Symmetric Traversal) ---\n");

    while (choice != 0) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Print tree (Symmetric / In-order)\n");
        printf("5. Print tree (2D Structure)\n");
        printf("0. Exit\n");

        choice = get_safe_int("Enter your choice (0-5): ");

        switch (choice) {
            case 1:
                val = get_safe_double("Enter a double value to insert: ");
                insert_element(my_tree, val);
                break;
            case 2:
                val = get_safe_double("Enter a double value to delete: ");
                delete_element(my_tree, val);
                break;
            case 3:
                val = get_safe_double("Enter a double value to search: ");
                found = search_element(my_tree, val);
                if (found != NULL) {
                    printf("Element %.2f is present in the tree.\n", found->data);
                } else {
                    printf("Element %.2f is not present in the tree.\n", val);
                }
                break;
            case 4:
                printf("Symmetric (In-order) traversal: ");
                if (my_tree->root == NULL) {
                    printf("Tree is empty.");
                } else {
                    print_symmetric(my_tree->root);
                }
                printf("\n");
                break;
            case 5:
                if (my_tree->root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("--- Tree 2D Structure ---\n");
                    print_tree_2d(my_tree->root, 0);
                    printf("\n-------------------------\n");
                }
                break;
            case 0:
                printf("Deleting tree and exiting...\n");
                break;
            default:
                printf("Invalid choice. Please select a number from the menu.\n");
                break;
        }
    }

    delete_tree(my_tree);
    return 0;
}
