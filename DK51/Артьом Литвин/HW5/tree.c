#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) return root;
    if (root->data < value) return search(root->right, value);
    return search(root->left, value);
}

void printTreeInOrder(Node* root) {
    if (root != NULL) {
        printTreeInOrder(root->left);
        printf("%d ", root->data);
        printTreeInOrder(root->right);
    }
}

void printTreeVisual(Node* root, int space) {
    if (root == NULL) return;
    int distance = 5;
    space += distance;
    printTreeVisual(root->right, space);
    printf("\n");
    for (int i = distance; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTreeVisual(root->left, space);
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}