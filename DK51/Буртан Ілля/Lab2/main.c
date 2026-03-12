#include <stdio.h>
#include "list.h"

int main() {
    IntList *list = createIntList();
    IntList *empty_list = createIntList();

    // Додаємо елементи для тесту
    addIntValueToIntList(list, 10);
    addIntValueToIntList(list, 20);
    addIntValueToIntList(list, 30);
    addIntValueToIntList(list, 40);

    // Виклик функції, що друкує 2 рази вперед і 2 рази назад
    printIntList(list);
    printIntList(empty_list);

    deleteIntList(list);
    return 0;
}
