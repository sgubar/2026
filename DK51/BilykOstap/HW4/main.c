#include <stdio.h>
#include "list.h"

int main() {
    system("chcp 65001 > nul");
    printf("1. Створення списку\n");
    SinglyLinkedList* list = create_list();

    printf("2. Додавання елементів (10, 20, 30)\n");
    add_element(list, 10);
    add_element(list, 20);
    add_element(list, 30);
    print_list(list);
    printf("Розмір списку: %zu\n\n", get_size(list));

    printf("3. Вставка елементу 15 за індексом 1\n");
    insert_by_index(list, 1, 15);
    print_list(list);
    printf("Розмір списку: %zu\n\n", get_size(list));

    printf("4. Вилучення елементу за індексом 2 (має видалити 20)\n");
    remove_by_index(list, 2);
    print_list(list);
    printf("Розмір списку: %zu\n\n", get_size(list));

    printf("5. Видалення списку та звільнення пам'яті\n");
    delete_list(list);
    printf("Готово\n");

    return 0;
}