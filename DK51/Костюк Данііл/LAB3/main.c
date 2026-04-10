#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("--- Lab Work 5: Binary Trees (Variant 8) ---\n");
    printf("Type: double. Traversal: Pre-order (Root -> Left -> Right)\n\n");

    DoubleTree* tree = create_tree();
    int choice = -1;

    while (choice != 0) {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Print tree (Pre-order)\n");
        printf("0. Exit\n");
        
        choice = get_valid_int("Choose an action (0-4): ");

        if (choice == 1) {
            double val = get_valid_double("Enter double value to insert: ");
            insert_element(tree, val);
            printf("Inserted %.2f.\n", val);
        } 
        else if (choice == 2) {
            double val = get_valid_double("Enter double value to delete: ");
            delete_element(tree, val);
            printf("Deletion triggered for %.2f.\n", val);
        } 
        else if (choice == 3) {
            double val = get_valid_double("Enter double value to search: ");
            DoubleNode* found = search_element(tree, val);
            if (found) printf("Element %.2f is FOUND in the tree.\n", found->value);
            else printf("Element %.2f is NOT FOUND.\n", val);
        } 
        else if (choice == 4) {
            print_tree_preorder(tree);
        } 
        else if (choice != 0) {
            printf("Invalid choice. Try again.\n");
        }
    }

    delete_tree(tree);
    printf("Tree memory freed. Exiting...\n");
    return 0;
}
