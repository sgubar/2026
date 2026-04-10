#include <stdio.h>
#include "list.h"

int main() {
    // 1. Створення списку
    LinkedList* myList = createList();
    printf("list created\n");

    // 2. Додавання елементів
    addElement(myList, 'H');
    addElement(myList, 'e');
    addElement(myList, 'l');
    addElement(myList, 'o');
    printList(myList);

    // 3. Вставка по індексу (вставляємо другу 'l')
    printf("\ninsert 'l' at index: 3\n");
    insertAtIndex(myList, 3, 'l');
    printList(myList);

    // 4. Вставка на початок
    printf("\nInsert '!' at the beginning (index 0):\n");
    insertAtIndex(myList, 0, '!');
    printList(myList);

    // 5. Вилучення елементу (видаляємо 'e')
    printf("\nWe delete the element 'e':\n");
    removeElement(myList, 'e');
    printList(myList);

    // 6. Розмір списку
    printf("\nCurrent list size: %d\n", getListSize(myList));

    // 7. Видалення списку
    deleteList(myList);
    printf("\nThe list has been successfully deleted from memory.\n");

    return 0;
}
