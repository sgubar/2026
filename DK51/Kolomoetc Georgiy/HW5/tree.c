#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

BinaryTree* create_tree() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    if (tree != NULL) {
        tree->root = NULL;
    }
    return tree;
}

Node* insert_recursive(Node* root, double value) {
    if (root == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) return NULL;
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (value < root->data) {
        root->left = insert_recursive(root->left, value);
    } else if (value > root->data) {
        root->right = insert_recursive(root->right, value);
    }
    return root;
}

void insert_element(BinaryTree* tree, double value) {
    if (tree != NULL) {
        tree->root = insert_recursive(tree->root, value);
    }
}

Node* search_recursive(Node* root, double value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search_recursive(root->left, value);
    }
    return search_recursive(root->right, value);
}

Node* search_element(BinaryTree* tree, double value) {
    if (tree == NULL) return NULL;
    return search_recursive(tree->root, value);
}

Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delete_recursive(Node* root, double value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = delete_recursive(root->left, value);
    } else if (value > root->data) {
        root->right = delete_recursive(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_recursive(root->right, temp->data);
    }
    return root;
}

void delete_element(BinaryTree* tree, double value) {
    if (tree != NULL) {
        tree->root = delete_recursive(tree->root, value);
    }
}

void free_recursive(Node* root) {
    if (root != NULL) {
        free_recursive(root->left);
        free_recursive(root->right);
        free(root);
    }
}

void delete_tree(BinaryTree* tree) {
    if (tree != NULL) {
        free_recursive(tree->root);
        free(tree);
    }
}

void print_2d(Node* root, int space) {
    if (root == NULL) return;
    space += 7;
    print_2d(root->right, space);
    printf("\n");
    for (int i = 7; i < space; i++) {
        printf(" ");
    }
    printf("%.2f\n", root->data);
    print_2d(root->left, space);
}

void print_tree(BinaryTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("--- Tree Structure ---\n");
    print_2d(tree->root, 0);
    printf("\n----------------------\n\n");
}
