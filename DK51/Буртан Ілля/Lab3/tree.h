// Підключаємо стандартні бібліотеки:
#include <stdio.h>  // Дозволяє використовувати printf для виводу тексту на екран
#include <stdlib.h> // Дозволяє виділяти пам'ять для нових вузлів (функція malloc)

// Описуємо тип данних Node:
typedef struct Node {
    int data;               // 1. Наші дані (число)
    struct Node* left;      // 2. Лівий зв'язок
    struct Node* right;     // 3. Правий зв'язок
} Node;

// Створюємо тип даних Tree:
typedef struct Tree {
    Node* root;
    int count;
} Tree;

// Оголошення функції:
Tree* createTree();
Node* createNode(int value);
void postOrder(Node* node);
void insert(Tree* tree, int value);
Node* insertNode(Node* current, int value);
Node* search(Tree* tree, int value);
void freeNodes(Node* node);
void deleteTree(Tree* tree);
Node* findMinNode(Node* current);
Node* removeNode(Node* current, int value);
void removeElement(Tree* tree, int value);
void printTreePostOrder(Tree* tree);