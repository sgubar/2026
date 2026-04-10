#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("--- Creating list ---\n");
    DoubleLinkedList* my_list = create_list();
    print_list(my_list);

    printf("\n--- Adding elements ---\n");
    add_element(my_list, 10.5);
    add_element(my_list, 20.0);
    add_element(my_list, 30.25);
    print_list(my_list);

    printf("\n--- Inserting elements by index ---\n");
    printf("Inserting 5.5 at index 0 (Start):\n");
    insert_element(my_list, 0, 5.5);
    print_list(my_list);
    
    printf("Inserting 15.0 at index 2 (Middle):\n");
    insert_element(my_list, 2, 15.0);
    print_list(my_list);

    printf("\nCurrent list size: %d\n", get_size(my_list));

    printf("\n--- Removing elements by index ---\n");
    printf("Removing element at index 4 (End):\n");
    remove_element(my_list, 4);
    print_list(my_list);

    printf("Removing element at index 1:\n");
    remove_element(my_list, 1);
    print_list(my_list);

    printf("\n--- Deleting list ---\n");
    delete_list(my_list);
    printf("List deleted successfully.\n");

    return 0;
}
