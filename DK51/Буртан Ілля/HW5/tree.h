#include <stdio.h>
#include <stdlib.h>

// Визначаємо вузол дерева
typedef struct Node {
    double data;
    struct Node* left;
    struct Node* right;
} Node;

// Визначаємо саме дерево
typedef struct Tree {
    Node* root;
} Tree;

// Оголошення функцій
Tree* createTree();
Node* createNode(double value);
void insert(Tree* tree, double value);
Node* search(Tree* tree, double value);
void deleteElement(Tree* tree, double value);
void deleteTree(Tree* tree);
void printTree(Node* root, int level);
