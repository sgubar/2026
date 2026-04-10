#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Створення нового вузла [cite: 6]
Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка пам'яті!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Вставка елемента [cite: 6]
Node* insert(Node* root, float value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Пошук мінімального (допоміжна для видалення)
Node* findMin(Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

// Видалення елемента [cite: 6]
Node* deleteNode(Node* root, float value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
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

// Пошук елемента [cite: 6]
Node* search(Node* root, float value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// Зворотній обхід (Left -> Right -> Root) [cite: 13]
void printPostOrder(Node* root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%.2f ", root->data);
    }
}

// Очищення пам'яті (видалення дерева) [cite: 6]
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}