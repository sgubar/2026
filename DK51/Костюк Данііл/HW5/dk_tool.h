#ifndef DK_TOOL_H
#define DK_TOOL_H

// Вузол дерева
typedef struct CharNode {
    char value;               // Дані типу char
    struct CharNode* left;    // Лівий нащадок (менші значення)
    struct CharNode* right;   // Правий нащадок (більші значення)
} CharNode;

// Структура самого дерева
typedef struct {
    CharNode* root;           // Корінь дерева
} CharTree;

// Функції роботи з деревом
CharTree* create_tree(void);
void delete_tree(CharTree* tree);

void insert_element(CharTree* tree, char value);
void delete_element(CharTree* tree, char value);
CharNode* search_element(CharTree* tree, char value);

void print_tree(CharTree* tree);

#endif // DK_TOOL_H
