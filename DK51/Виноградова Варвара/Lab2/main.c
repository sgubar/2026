#include <stdio.h>
#include <windows.h>
#include "list.h"

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Node* head = NULL;
    int n, i, data;

    printf("Робота з кільцевим однозв'язним списком\n");
    printf("Введіть початкову кількість елементів списку (ціле число): ");
    n = getValidInt();

    if (n <= 0) {
        printf("Кількість елементів має бути додатньою.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Введіть значення елемента №%d: ", i + 1);
        data = getValidInt();
        insertEnd(&head, data);
    }

    printf("\nПoчaткoвий список:\n");
    printList(head);

    // Запуск алгоритму
    deleteEveryThird(&head);

    // Коректне звільнення пам'яті 
    freeList(&head);

    return 0;
}