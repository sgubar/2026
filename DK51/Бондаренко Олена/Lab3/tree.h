#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
Node* deleteNode(Node* root, int key);
Node* search(Node* root, int key);
void printPreOrder(Node* root);
void freeTree(Node* root);
Node* findMin(Node* root);

#endif
