#ifndef TREE_H
#define TREE_H

// Структура вузла для роботи з типом float (Варіант 6)
typedef struct Node {
    float data;
    struct Node *left;
    struct Node *right;
} Node;

// Прототипи функцій для роботи з деревом
Node* createNode(float value);
Node* insert(Node* root, float value);
Node* deleteNode(Node* root, float value);
Node* search(Node* root, float value);
void printPostOrder(Node* root); // Зворотній обхід
void freeTree(Node* root);

#endif