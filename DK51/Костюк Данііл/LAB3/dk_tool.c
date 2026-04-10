#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

DoubleTree* create_tree(void) {
    DoubleTree* tree = (DoubleTree*)malloc(sizeof(DoubleTree));
    if (tree) {
        tree->root = NULL;
    }
    return tree;
}

void free_node(DoubleNode* node) {
    if (!node) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

void delete_tree(DoubleTree* tree) {
    if (!tree) return;
    free_node(tree->root);
    free(tree);
}

// РЕКУРСИВНА ВСТАВКА
DoubleNode* insert_node(DoubleNode* root, double value) {
    if (root == NULL) {
        DoubleNode* new_node = (DoubleNode*)malloc(sizeof(DoubleNode));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else if (value > root->value) {
        root->right = insert_node(root->right, value);
    }
    return root;
}

void insert_element(DoubleTree* tree, double value) {
    if (!tree) return;
    tree->root = insert_node(tree->root, value);
}

// ДОПОМІЖНА ФУНКЦІЯ: ПОШУК МІНІМУМУ (ДЛЯ ВИДАЛЕННЯ)
DoubleNode* find_min(DoubleNode* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// РЕКУРСИВНЕ ВИДАЛЕННЯ
DoubleNode* delete_node_recursive(DoubleNode* root, double value) {
    if (root == NULL) return root;

    if (value < root->value) {
        root->left = delete_node_recursive(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node_recursive(root->right, value);
    } else {
        // Знайшли елемент
        if (root->left == NULL) {
            DoubleNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            DoubleNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Вузол має 2 нащадки
        DoubleNode* temp = find_min(root->right);
        root->value = temp->value;
        root->right = delete_node_recursive(root->right, temp->value);
    }
    return root;
}

void delete_element(DoubleTree* tree, double value) {
    if (!tree) return;
    tree->root = delete_node_recursive(tree->root, value);
}

// РЕКУРСИВНИЙ ПОШУК
DoubleNode* search_node(DoubleNode* root, double value) {
    if (root == NULL || root->value == value) return root;
    if (value < root->value) return search_node(root->left, value);
    return search_node(root->right, value);
}

DoubleNode* search_element(DoubleTree* tree, double value) {
    if (!tree) return NULL;
    return search_node(tree->root, value);
}

// ВАРІАНТ 8: ПРЯМИЙ ОБХІД (Pre-order: Корінь -> Лівий -> Правий)
void preorder_recursive(DoubleNode* node) {
    if (node == NULL) return;
    printf("%.2f ", node->value); // 1. Вузол
    preorder_recursive(node->left); // 2. Лівий
    preorder_recursive(node->right); // 3. Правий
}

void print_tree_preorder(DoubleTree* tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty.\n");
        return;
    }
    printf("Pre-order Traversal: [ ");
    preorder_recursive(tree->root);
    printf("]\n");
}

// ЗАХИСТ ВІД ДУРНЯ
double get_valid_double(const char* prompt) {
    double val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &val) == 1) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Please enter a valid number.\n");
    }
}

int get_valid_int(const char* prompt) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Please enter a valid integer.\n");
    }
}
