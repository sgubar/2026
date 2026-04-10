 #ifndef DK_TOOL_H
#define DK_TOOL_H

// Вузол бінарного дерева для типу double
typedef struct DoubleNode {
    double value;
    struct DoubleNode* left;
    struct DoubleNode* right;
} DoubleNode;

// Структура самого дерева
typedef struct {
    DoubleNode* root;
} DoubleTree;

// Базові функції дерева
DoubleTree* create_tree(void);
void delete_tree(DoubleTree* tree);

void insert_element(DoubleTree* tree, double value);
void delete_element(DoubleTree* tree, double value);
DoubleNode* search_element(DoubleTree* tree, double value);

// Друк дерева: Прямий обхід (Pre-order) - Варіант 8
void print_tree_preorder(DoubleTree* tree);

// Функції захисту від дурня
double get_valid_double(const char* prompt);
int get_valid_int(const char* prompt);

#endif // DK_TOOL_H
