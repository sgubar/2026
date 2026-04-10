#ifndef DK_TOOL_H
#define DK_TOOL_H

typedef struct Node {
    double value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} DoubleLinkedList;

// Базові функції
DoubleLinkedList* create_list(void);
void delete_list(DoubleLinkedList* list);
void add_element(DoubleLinkedList* list, double value);
void print_list(const DoubleLinkedList* list);

// Функція за варіантом №8
int duplicate_element(DoubleLinkedList* list, double target);

// Захист від дурня
double get_valid_double(const char* prompt);
int get_valid_int(const char* prompt, int min_val);

#endif // DK_TOOL_H
