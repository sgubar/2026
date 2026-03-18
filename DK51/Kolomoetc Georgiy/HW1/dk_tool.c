#include <stdio.h>
#include "dk_tool.h"

int getValidInt(const char *prompt) {
    int value;
    int status;
    printf("%s", prompt);

    while ((status = scanf("%d", &value)) != 1) {
        if (status == EOF) break;
        while (getchar() != '\n');
        printf("Error! Not a number. Try again: ");
    }
    return value;
}

void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        char prompt[50];
        sprintf(prompt, "Enter element [%d]: ", i);
        arr[i] = getValidInt(prompt);
    }
}

void printArray(const int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void reverseArray(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
