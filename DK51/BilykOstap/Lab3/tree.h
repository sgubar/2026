#ifndef TREE_H
#define TREE_H

// структура вузла бінарного дерева
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data);
TreeNode* insertNode(TreeNode* root, int data);
TreeNode* deleteNode(TreeNode* root, int data);
TreeNode* searchNode(TreeNode* root, int data);

void printTreeSymmetric(TreeNode* root);
void printTreeVisual(TreeNode* root, int space);

// очищення памяті
TreeNode* deleteTree(TreeNode* root);

#endif