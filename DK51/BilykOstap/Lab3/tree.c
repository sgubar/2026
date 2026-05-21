#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

// створення нового вузла
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// вставка елемента у дерево
TreeNode* insertNode(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        printf("Елемент %d вже існує в дереві!\n", data);
    }
    
    return root;
}

// Допоміжна функція для знаходження вузла з мінімальним значенням
static TreeNode* getMinValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// видалення елемента з дерева
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {

        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = getMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// пошук елемента
TreeNode* searchNode(TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// симетричний обхід
void printTreeSymmetric(TreeNode* root) {
    if (root != NULL) {
        printTreeSymmetric(root->left);
        printf("%d ", root->data);
        printTreeSymmetric(root->right);
    }
}

// функція для візуального виводу дерева
void printTreeVisual(TreeNode* root, int space) {
    int COUNT = 5;
    if (root == NULL) return;

    space += COUNT;
    printTreeVisual(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTreeVisual(root->left, space);
}

// видалення дерева
TreeNode* deleteTree(TreeNode* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
    return NULL;
}