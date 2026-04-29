#ifndef TREE_H
#define TREE_H

typedef struct Node {
    double data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(double value);
Node* insert(Node* root, double value);
void printPostOrder(Node* root);
Node* search(Node* root, double key);
Node* deleteNode(Node* root, double key);
void clearTree(Node* root);

#endif
