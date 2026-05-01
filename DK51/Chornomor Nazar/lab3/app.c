#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tree.h"

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int getSafeInt(int min, int max) {
    int val;
    while (scanf("%d", &val) != 1 || val < min || val > max) {
        printf("Помилка! Введіть число (%d-%d): ", min, max);
        clearBuffer();
    }
    clearBuffer();
    return val;
}

static char getSafeChar() {
    char ch;
    while (scanf(" %c", &ch) != 1) {
        printf("Помилка! Введіть символ: ");
        clearBuffer();
    }
    clearBuffer();
    return ch;
}

void startApplication() {
    
    Node* root = NULL;
    int choice;
    char val;

    do {
        printf("\n--- МЕНЮ ---\n1. Створити/Очистити\n2. Вставити\n3. Видалити\n4. Пошук\n5. Друк\n6. Зворотній обхід\n7. Вихід\nВибір: ");
        choice = getSafeInt(1, 7);

        switch (choice) {
            case 1: root = freeTree(root); printf("Дерево ініціалізовано.\n"); break;
            case 2: printf("Символ: "); root = insertNode(root, getSafeChar()); break;
            case 3: printf("Видалити: "); root = deleteNode(root, getSafeChar()); break;
            case 4: 
                printf("Шукати: "); 
                val = getSafeChar();
                printf(searchNode(root, val) ? "Знайдено!\n" : "Немає.\n"); 
                break;
            case 5: printTreeVisual(root, 0); break;
            case 6: postOrderTraversal(root); printf("\n"); break;
        }
    } while (choice != 7);
    freeTree(root);
}