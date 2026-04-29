#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, double value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%.2f ", root->data);
    }
}

Node* search(Node* root, double key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

static Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

Node* deleteNode(Node* root, double key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
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

void clearTree(Node* root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}