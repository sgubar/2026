#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tree.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = NULL;

    printf("=== Робота з бінарним деревом ===\n\n");

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Структура дерева:\n");
    printTreeVisual(root, 0);

    printf("\nЕлементи (In-Order): ");
    printTreeInOrder(root);
    printf("\n");

    int valToSearch = 40;
    if (search(root, valToSearch)) printf("\nЕлемент %d знайдено!", valToSearch);

    printf("\n\nВидаляємо 30...");
    root = deleteNode(root, 30);

    printf("\nДерево після видалення:\n");
    printTreeVisual(root, 0);

    freeTree(root);
    printf("\nПам'ять очищено.\n");

    return 0;
}
