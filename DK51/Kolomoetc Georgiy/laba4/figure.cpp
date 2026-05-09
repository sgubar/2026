#include "figure.h"
#include <GL/glut.h> // Підключення OpenGL для малювання
#include <iostream>

// Ініціалізація порожнього списку
void initList(List* list) {
    list->head = nullptr;
    list->tail = nullptr;
}

// Додавання елемента в кінець двозв'язного списку
void pushBack(List* list, Figure f) {
    Node* newNode = new Node;
    newNode->data = f;
    newNode->next = nullptr;
    newNode->prev = list->tail;

    if (list->tail != nullptr) {
        list->tail->next = newNode;
    }
    else {
        list->head = newNode; // Якщо список був порожнім
    }
    list->tail = newNode;
    std::cout << "Фігуру додано до списку." << std::endl;
}

// Видалення елемента з початку двозв'язного списку
void popFront(List* list) {
    if (list->head == nullptr) {
        std::cout << "Список порожній, нічого видаляти." << std::endl;
        return;
    }

    Node* temp = list->head;
    list->head = list->head->next;

    if (list->head != nullptr) {
        list->head->prev = nullptr;
    }
    else {
        list->tail = nullptr; // Якщо видалили останній елемент
    }

    delete temp;
    std::cout << "Фігуру видалено з початку списку." << std::endl;
}

// Функція, яка об'єднує логіку двозв'язного списку та OpenGL: обхід списку та відмальовка
void drawList(List* list) {
    Node* current = list->head;
    // Проходимось по всіх елементах списку
    while (current != nullptr) {
        // Задаємо колір поточної фігури
        glColor3f(current->data.r, current->data.g, current->data.b);

        // Малюємо трикутник за координатами
        glBegin(GL_TRIANGLES);
        glVertex2f(current->data.p1.x, current->data.p1.y);
        glVertex2f(current->data.p2.x, current->data.p2.y);
        glVertex2f(current->data.p3.x, current->data.p3.y);
        glEnd();

        current = current->next;
    }
}