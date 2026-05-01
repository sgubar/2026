#pragma once

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char data);
Node* insertNode(Node* root, char data);
Node* deleteNode(Node* root, char data);
Node* searchNode(Node* root, char data);
void postOrderTraversal(Node* root);
void printTreeVisual(Node* root, int space);
Node* freeTree(Node* root);
