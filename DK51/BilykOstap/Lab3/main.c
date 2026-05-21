#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

// перевірка
int get_valid_int(const char* prompt) {
    int value;
    int status;
    char c;
    
    while (true) {
        printf("%s", prompt);
        status = scanf("%d", &value);
        
        if (status == 1) {
            c = getchar();
            if (c == '\n' || c == EOF) {
                return value;
            } else {
                printf("Помилка. Виявлено зайві символи. Введіть лише ціле число\n");
                while ((c = getchar()) != '\n' && c != EOF); // очищення
            }
        } else {
            printf("Помилка. Введено некоректні дані. Введіть ціле число\n");
            while ((c = getchar()) != '\n' && c != EOF); // очищення
        }
    }
}

// функція виводу меню
void printMenu() {
    printf("\nМЕНЮ\n");
    printf("1. Додати елемент до дерева\n");
    printf("2. Видалити елемент з дерева\n");
    printf("3. Знайти елемент у дереві\n");
    printf("4. Вивести дерево (симетричний обхід | ліве-корінь-праве)\n");
    printf("5. Вивести дерево (візуально)\n");
    printf("6. Видалити все дерево\n");
    printf("0. Вийти з програми\n");
}

int main() {
    system("chcp 65001 > nul");
    TreeNode* root = NULL;
    int choice, value;
    TreeNode* searchResult = NULL;

    while (true) {
        printMenu();
        choice = get_valid_int("Оберіть дію (0-6): ");

        switch (choice) {
            case 1:
                printf("\nДодавання елемента\n");
                value = get_valid_int("Введіть ціле число для вставки: ");
                root = insertNode(root, value);
                printf("Елемент %d успішно додано\n", value);
                break;

            case 2:
                printf("\nВидалення елемента\n");
                if (root == NULL) {
                    printf("Дерево порожнє. Немає що видаляти\n");
                } else {
                    value = get_valid_int("Введіть елемент для видалення: ");
                    if (searchNode(root, value) != NULL) {
                        root = deleteNode(root, value);
                        printf("Елемент %d успішно видалено\n", value);
                    } else {
                        printf("Елемент %d не знайдено у дереві\n", value);
                    }
                }
                break;

            case 3:
                printf("\nПошук елемента\n");
                if (root == NULL) {
                    printf("Дерево порожнє\n");
                } else {
                    value = get_valid_int("Введіть елемент для пошуку: ");
                    searchResult = searchNode(root, value);
                    if (searchResult != NULL) {
                        printf("Елемент %d ЗНАЙДЕНО у дереві\n", value);
                    } else {
                        printf("Елемент %d НЕ ЗНАЙДЕНО у дереві\n", value);
                    }
                }
                break;

            case 4:
                printf("\nСиметричний обхід дерева\n");
                if (root == NULL) {
                    printf("Дерево порожнє\n");
                } else {
                    printf("Результат обходу (за зростанням): ");
                    printTreeSymmetric(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("\nВізуальне відображення дерева\n");
                if (root == NULL) {
                    printf("Дерево порожнє\n");
                } else {
                    printf("Дерево відображається горизонтально, корінь зліва\n");
                    printTreeVisual(root, 0);
                }
                break;

            case 6:
                printf("\nВидалення дерева\n");
                if (root == NULL) {
                    printf("Дерево і так порожнє\n");
                } else {
                    root = deleteTree(root);
                    printf("Дерево успішно очищено з пам'яті\n");
                }
                break;

            case 0:
                printf("\nЗавершення роботи програми. Очищення пам'яті...\n");
                root = deleteTree(root);
                return 0;

            default:
                printf("Помилка. Невідома команда. Будь ласка, введіть число від 0 до 6\n");
                break;
        }
    }
}