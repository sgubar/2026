#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

// 1. Створення дерева
CharTree* create_tree(void) {
    CharTree* tree = (CharTree*)malloc(sizeof(CharTree));
    if (tree) {
        tree->root = NULL;
    }
    return tree;
}

// Допоміжна функція для рекурсивного очищення пам'яті
void free_node(CharNode* node) {
    if (!node) return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

// 2. Видалення дерева (очищення пам'яті)
void delete_tree(CharTree* tree) {
    if (!tree) return;
    free_node(tree->root);
    free(tree);
}

// Допоміжна функція створення вузла
CharNode* create_node(char value) {
    CharNode* new_node = (CharNode*)malloc(sizeof(CharNode));
    if (new_node) {
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

// Допоміжна рекурсивна функція вставки
CharNode* insert_node(CharNode* root, char value) {
    if (root == NULL) return create_node(value);
    
    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else if (value > root->value) {
        root->right = insert_node(root->right, value);
    }
    // Якщо value == root->value, дублікати не додаємо
    return root;
}

// 3. Вставка елемента
void insert_element(CharTree* tree, char value) {
    if (!tree) return;
    tree->root = insert_node(tree->root, value);
}

// Допоміжна функція для пошуку мінімального вузла (потрібна для видалення)
CharNode* find_min(CharNode* node) {
    CharNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Допоміжна рекурсивна функція видалення
CharNode* delete_node(CharNode* root, char value) {
    if (root == NULL) return root;

    if (value < root->value) {
        root->left = delete_node(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node(root->right, value);
    } else {
        // Знайшли вузол для видалення
        
        // Випадок 1: немає нащадків або тільки один нащадок
        if (root->left == NULL) {
            CharNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            CharNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // Випадок 2: вузол має двох нащадків
        // Шукаємо найменшого в правому піддереві
        CharNode* temp = find_min(root->right);
        
        // Копіюємо його значення
        root->value = temp->value;
        
        // Видаляємо того найменшого з правого піддерева
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}

// 4. Видалення елемента
void delete_element(CharTree* tree, char value) {
    if (!tree) return;
    tree->root = delete_node(tree->root, value);
}

// Допоміжна рекурсивна функція пошуку
CharNode* search_node(CharNode* root, char value) {
    if (root == NULL || root->value == value) return root;
    
    if (value < root->value) return search_node(root->left, value);
    return search_node(root->right, value);
}

// 5. Пошук елемента
CharNode* search_element(CharTree* tree, char value) {
    if (!tree) return NULL;
    return search_node(tree->root, value);
}

// Допоміжна функція для красивого виводу дерева горизонтально
void print_node_2d(CharNode* root, int space) {
    if (root == NULL) return;
    
    space += 5; // Відстань між рівнями
    
    print_node_2d(root->right, space);
    
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->value);
    
    print_node_2d(root->left, space);
}

// 6. Вивід дерева на екран
void print_tree(CharTree* tree) {
    if (!tree || !tree->root) {
        printf("Tree is empty.\n");
        return;
    }
    printf("--- Tree Structure (Left to Right) ---\n");
    print_node_2d(tree->root, 0);
    printf("\n--------------------------------------\n");
}
