#pragma once
#include "point.h"

// Структура фігури (наприклад, трикутник)
struct Figure {
    Point p1, p2, p3; // Вершини трикутника
    float r, g, b;    // Колір фігури у форматі RGB
};

// Вузол двозв'язного списку 
struct Node {
    Figure data;
    Node* prev; // Вказівник на попередній елемент
    Node* next; // Вказівник на наступний елемент
};

// Структура самого двозв'язного списку
struct List {
    Node* head;
    Node* tail;
};

// Оголошення функцій для роботи зі списком
void initList(List* list);
void pushBack(List* list, Figure f);
void popFront(List* list);
void drawList(List* list);