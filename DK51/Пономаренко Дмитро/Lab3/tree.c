#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void PrintNode(Node *node)
{
    if (!node)
    {
        return;
    }

    printf("%c", node->value);
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

Node *CreateCharNode(char ch)
{
    Node *node = malloc(sizeof(Node));

    if (node)
    {
        node->left = NULL;
        node->right = NULL;
        node->value = ch;
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
    if (!tree)
    {
        return;
    }

    PrintNode(tree->root);
}

void InsertChar(Tree *tree, char ch)
{
    if (!tree)
    {
        return;
    }

    Node *node = CreateCharNode(ch);
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

            if (ch < current->value)
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

Node *FindNodeByChar(Tree *tree, char ch)
{
    if (!tree || !tree->root)
        return NULL;

    Node *current = tree->root;

    while (current && ch != current->value)
    {
        if (ch < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}