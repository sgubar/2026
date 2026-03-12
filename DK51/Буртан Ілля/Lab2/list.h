#include <stdio.h>

// СТРУКТУРИ ДАНИХ

// Елемент списку
typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
    int value;               // Значення, яке зберігається
    IntListElement *prev;    // Вказівник на попередній елемент
    IntListElement *next;    // Вказівник на наступний елемент
};

// Контейнер для списку (зберігає початок і кінець)
typedef struct tagIntList {
    IntListElement *head;    // Вказівник на перший елемент
    IntListElement *tail;    // Вказівник на останній елемент
} IntList;

// ФУНКЦІЇ ДЛЯ РОБОТИ З ЕЛЕМЕНТАМИ

// Створює новий елемент зі значенням value
IntListElement *createIntListElement(int value);

// Пише навпаки
void printfbackward(IntList *list);

// Пише прямо
void printfforward(IntList *list);

// Видаляє елемент та звільняє пам'ять
void deleteIntListElement(IntListElement *element);

// Друкує значення одного елемента
void printIntListElement(IntListElement *element);

// ФУНКЦІЇ ДЛЯ РОБОТИ ЗІ СПИСКОМ

// Створює порожній список
IntList *createIntList(void);

// Видаляє весь список та всі його елементи (очищення пам'яті)
void deleteIntList(IntList *list);

// Друкує список: 2 рази в прямому порядку та 2 рази у зворотному
void printIntList(IntList *list);

// Додає нове значення в кінець списку (1 - успіх, 0 - помилка)
int addIntValueToIntList(IntList *list, int value);

