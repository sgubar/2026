#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Функція безпечного введення числа [cite: 22]
float getFloatInput() {
    float val;
    char term;
    while (scanf("%f%c", &val, &term) != 2 || term != '\n') {
        printf("Помилка! Введіть число (float): ");
        while (getchar() != '\n'); 
    }
    return val;
}

int main() {
    Node* root = NULL;
    int choice;
    float val;

    printf("Лабораторна робота №3: Бінарні дерева (Варіант 6)\n");

    while (1) {
        printf("\n--- Меню ---\n");
        printf("1. Додати елемент\n");
        printf("2. Видалити елемент\n");
        printf("3. Пошук елемента\n");
        printf("4. Вивести дерево (зворотній обхід)\n");
        printf("5. Вихід\n");
        printf("Вибір: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Невірний формат вибору.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Значення для вставки: ");
                val = getFloatInput();
                root = insert(root, val);
                break;
            case 2:
                printf("Значення для видалення: ");
                val = getFloatInput();
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Значення для пошуку: ");
                val = getFloatInput();
                if (search(root, val)) printf("Елемент знайдено.\n");
                else printf("Елемент відсутній.\n");
                break;
            case 4:
                printf("Зворотній обхід: ");
                printPostOrder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                return 0;
            default:
                printf("Невірний пункт.\n");
        }
    }
}