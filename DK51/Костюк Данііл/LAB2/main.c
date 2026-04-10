#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("--- Lab Work 2 (Variant 8) ---\n");
    printf("Task: Double every occurrence of a given element in the list.\n\n");

    DoubleLinkedList* list = create_list();
    
    int n = get_valid_int("How many elements do you want to add? (>= 0): ", 0);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        double val = get_valid_double("");
        add_element(list, val);
    }

    printf("\n--- Original List ---\n");
    print_list(list);

    if (n > 0) {
        double target = get_valid_double("\nEnter the element you want to duplicate: ");
        int duplicated_count = duplicate_element(list, target);
        
        printf("\n--- Modified List ---\n");
        print_list(list);
        printf("Duplicated %d occurrence(s) of %.2f.\n", duplicated_count, target);
    }

    delete_list(list);
    return 0;
}
