#include <stdio.h>
#include <stdlib.h>
#include "word.h"

int isValidWord(char *str) {
    int i = 0;

    if (str[0] == '\0' || str[0] == '\n') return 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
        i++;
    }
    return 1;
}

int wordLength(char *str) {
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    return len;
}

Node* append(Node* head, char *word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }

    int i = 0;
    while (word[i] != '\0') {
        newNode->word[i] = word[i];
        i++;
    }
    newNode->word[i] = '\0';
    newNode->next = NULL;

    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;

    return head;
}

void freeList(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void printList(Node* head) {
    printf("\nСписок слів:\n");
    while (head) {
        printf("%s", head->word);
        head = head->next;
    }
}

void sortByLength(Node* head) {
    if (!head) return;

    int swapped;
    Node *ptr1;
    char temp[MAX_LEN];

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next) {
            if (wordLength(ptr1->word) > wordLength(ptr1->next->word)) {
                // swap words
                int i = 0;
                while (ptr1->word[i] != '\0') {
                    temp[i] = ptr1->word[i];
                    i++;
                }
                temp[i] = '\0';

                i = 0;
                while (ptr1->next->word[i] != '\0') {
                    ptr1->word[i] = ptr1->next->word[i];
                    i++;
                }
                ptr1->word[i] = '\0';

                i = 0;
                while (temp[i] != '\0') {
                    ptr1->next->word[i] = temp[i];
                    i++;
                }
                ptr1->next->word[i] = '\0';

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
    } while (swapped);
}

void printMaxLengthWords(Node* head) {
    if (!head) return;

    int maxLen = 0;
    Node* temp = head;

    // знайти максимум
    while (temp) {
        int len = wordLength(temp->word);
        if (len > maxLen) maxLen = len;
        temp = temp->next;
    }

    printf("\nСлова максимальної довжини (%d):\n", maxLen);

    temp = head;
    while (temp) {
        if (wordLength(temp->word) == maxLen) {
            printf("%s", temp->word);
        }
        temp = temp->next;
    }
}
