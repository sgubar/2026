#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void PrintNode(Node *node)
{
    if (!node)
    {
        return;
    }

    printf("%.1f ", node->value);
    PrintNode(node->left);
    PrintNode(node->right);
};

void DestroyNode(Node *node)

{
    if (!node)
    {
        return;
    }

    DestroyNode(node->left);
    DestroyNode(node->right);
    free(node);
};

Node *CreateDoubleNode(double num)
{
    Node *node = malloc(sizeof(Node));

    if (node)
    {
        node->left = NULL;
        node->right = NULL;
        node->value = num;
    }

    return node;
}

Tree *CreateTree()
{
    Tree *tree = malloc(sizeof(Tree));

    if (tree)
    {
        tree->count = 0;
        tree->root = NULL;
    }

    return tree;
};

void DestroyTree(Tree *tree)
{
    if (!tree)
    {
        return;
    }

    DestroyNode(tree->root);
    free(tree);
};

void PrintTree(Tree *tree)
{
    if (!tree || !tree->root)
    {
        printf("NULL");
        return;
    }

    PrintNode(tree->root);
}

void InsertDouble(Tree *tree, double num)
{
    if (!tree)
    {
        return;
    }

    Node *node = CreateDoubleNode(num);
    if (!node)
    {
        return;
    }

    if (tree->root == NULL)
    {
        tree->root = node;
        tree->count++;
    }
    else
    {
        Node *current = tree->root;
        Node *parent = NULL;

        while (1)
        {
            parent = current;

            if (num < current->value)
            {
                current = current->left;
                if (!current)
                {
                    parent->left = node;
                    break;
                }
            }
            else
            {
                current = current->right;
                if (!current)
                {
                    parent->right = node;
                    break;
                }
            }
        }
        tree->count++;
    }
};

void DeleteNodeByDouble(Tree *tree, double num)
{
    if (!tree || !tree->root)
    {
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (current && current->value != num)
    {
        parent = current;
        if (num < current->value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (!current)
    {
        return;
    }

    if (current->left && current->right)
    {
        Node *successorParent = current;
        Node *successor = current->right;

        while (successor->left)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->value = successor->value;

        current = successor;
        parent = successorParent;
    }

    Node *child = current->left ? current->left : current->right;

    if (!parent)
    {
        tree->root = child;
    }
    else if (parent->left == current)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    free(current);
    tree->count--;
}

Node *FindNodeByDouble(Tree *tree, double num)
{
    if (!tree || !tree->root)
        return NULL;

    Node *current = tree->root;

    while (current && num != current->value)
    {
        if (num < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}