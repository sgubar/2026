#include <stdio.h>
#include "dk_tool.h"

int get_int_input(const char* prompt) {
    int val = 0;
    printf("%s", prompt);
    while (scanf("%d", &val) != 1) {
        printf("Error! Enter number: ");
        while (getchar() != '\n');
    }
    return val;
}

void fill_matrix(int rows, int cols, int *matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", (matrix + i * cols + j));
        }
    }
}

void print_matrix(int rows, int cols, int *matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

void add_matrices(int rows, int cols, int *m1, int *m2, int *result) {
    for (int i = 0; i < rows * cols; i++) {
        result[i] = m1[i] + m2[i];
    }
}
