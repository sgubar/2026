#ifndef DK_TOOL_H
#define DK_TOOL_H

// Структура одного вузла списку
typedef struct Node {
    double value;
    struct Node* prev; // Вказівник на попередній елемент
    struct Node* next; // Вказівник на наступний елемент
} Node;

// Структура самого двозв'язного списку
typedef struct {
    Node* head; // Вказівник на початок
    Node* tail; // Вказівник на кінець (для швидкого додавання)
    int size;   // Кількість елементів
} DoubleLinkedList;

// Функції для роботи зі списком
DoubleLinkedList* create_list(void);
void delete_list(DoubleLinkedList* list);

void add_element(DoubleLinkedList* list, double value);
int insert_element(DoubleLinkedList* list, int index, double value);
int remove_element(DoubleLinkedList* list, int index);

int get_size(const DoubleLinkedList* list);
void print_list(const DoubleLinkedList* list);

#endif // DK_TOOL_H
