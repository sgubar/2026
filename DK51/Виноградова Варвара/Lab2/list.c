#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Функція для безпечного введення цілого числа
int getValidInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Недопустиме значення. Введіть ціле число: ");
        while(getchar() != '\n'); 
    }
    return value;
}

// Додавання вузла в кінець кільцевого списку
void insertEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; 
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; 
    }
}

// Вивід списку на екран
void printList(Node* head) {
    if (head == NULL) {
        printf("Список порожній.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(початок: %d)\n", head->data); 
}

// Підрахунок кількості елементів
int getCount(Node* head) {
    if (head == NULL) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Головна функція: видалення кожного 3-го елемента
void deleteEveryThird(Node** head) {
    if (*head == NULL) return;

    int count = getCount(*head);
    if (count < 3) {
        printf("Y списку менше 3 елементів. Процес видалення не запускається.\n");
        return;
    }

    Node* curr = *head;
    Node* prev = NULL;

    while (count >= 3) {
        prev = curr->next;
        Node* target = prev->next; 

        printf("\nBидaляємo елемент: %d\n", target->data);

        prev->next = target->next;

        if (target == *head) {
            *head = target->next;
        }

        free(target);
        count--;
        curr = prev->next;

        printf("Поточний стан списку: ");
        printList(*head);
    }
    printf("\n3aлишилocь менше 3 елементів. Процес завершено.\n");
}

// Очищення пам'яті
void freeList(Node** head) {
    if (*head == NULL) return;
    Node* curr = *head;
    Node* nextNode;
    do {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    } while (curr != *head);
    *head = NULL;
}