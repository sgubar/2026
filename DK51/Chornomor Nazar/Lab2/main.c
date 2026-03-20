#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "word.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Node* head = NULL;
    int n = 0;
    char buffer[MAX_LEN] = "";

    while (1) {
        printf("Введіть кількість слів (1-100): ");
        if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
            printf("Помилка! Введіть ціле число від 1 до 100.\n");
            while (getchar() != '\n'); // очистка буфера
        } else {
            while (getchar() != '\n');
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Введіть слово #%d (тільки латинські букви, макс %d символів): ", i+1, MAX_LEN-1);

            if (!fgets(buffer, MAX_LEN, stdin)) {
                printf("Помилка вводу!\n");
                continue;
            }

            if (!isValidWord(buffer)) {
                printf("Некоректний ввід! Дозволені тільки літери.\n");
                continue;
            }

            head = append(head, buffer);
            break;
        }
    }

    printList(head);

    sortByLength(head);

    printf("\n\nВідсортований список за довжиною:\n");
    printList(head);


    printMaxLengthWords(head);


    freeList(head);

    return 0;
}