#ifndef TREE_H
#define TREE_H

typedef struct Node {
    double data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} BinaryTree;

BinaryTree* create_tree();
void insert_element(BinaryTree* tree, double value);
void delete_element(BinaryTree* tree, double value);
Node* search_element(BinaryTree* tree, double value);
void print_symmetric(Node* root);
void delete_tree(BinaryTree* tree);
void print_tree_2d(Node* root, int space);

#endif
