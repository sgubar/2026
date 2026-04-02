
// Структура вузла списку
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Структура-обгортка для списку, щоб зберігати вказівник на початок та розмір
typedef struct tagLinkedList {
    Node* head;
    int size;
} LinkedList;

// Функції модуля
LinkedList* createList();
void addElement(LinkedList* list, char value);
void removeElement(LinkedList* list, char value);
void insertAtIndex(LinkedList* list, int index, char value);
void deleteList(LinkedList* list);
int getListSize(LinkedList* list);
void printList(LinkedList* list);