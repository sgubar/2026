#ifndef TREE_H
#define TREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
Node* findMin(Node* root);
Node* deleteNode(Node* root, int value);
Node* search(Node* root, int value);
void printTreeInOrder(Node* root);
void printTreeVisual(Node* root, int space);
void freeTree(Node* root);

#endif