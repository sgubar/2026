#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode(char data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (n) { n->data = data; n->left = n->right = NULL; }
    return n;
}

Node* insertNode(Node* root, char data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insertNode(root->left, data);
    else if (data > root->data) root->right = insertNode(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, char data) {
    if (!root) return NULL;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (!root->left) { Node* t = root->right; free(root); return t; }
        if (!root->right) { Node* t = root->left; free(root); return t; }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

Node* searchNode(Node* root, char data) {
    if (!root || root->data == data) return root;
    return (data < root->data) ? searchNode(root->left, data) : searchNode(root->right, data);
}

void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }
}

void printTreeVisual(Node* root, int space) {
    if (!root) return;
    space += 5;
    printTreeVisual(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%c\n", root->data);
    printTreeVisual(root->left, space);
}

Node* freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    return NULL;
}