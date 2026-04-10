#include <stdio.h>
#include "list.h"

int main() {
    DoublyLinkedList* my_list = create_list();

    add_element(my_list, 'A');
    add_element(my_list, 'B');
    add_element(my_list, 'C');

    printf("Initial ");
    print_list(my_list);
    printf("Size: %d\n\n", get_list_size(my_list));

    insert_element_by_index(my_list, 'X', 1);
    printf("After insertion ");
    print_list(my_list);
    printf("Size: %d\n\n", get_list_size(my_list));

    remove_element(my_list, 2);
    printf("After removal ");
    print_list(my_list);
    printf("Size: %d\n\n", get_list_size(my_list));

    delete_list(my_list);

    return 0;
}
