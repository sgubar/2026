#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

//зчитування числа
int get_int_input(const char* message) {
    int value;
    int status;
    do {
        printf("%s", message);
        status = scanf("%d", &value);
        
        while(getchar() != '\n');

        if (status != 1) {
            printf("Помилка! Введіть нормальне ціле число\n");
        }
    } while (status != 1);
    
    return value;
}
//виділення пам'яті
int** create_matrix(int rows, int cols) {
    int** mat = (int**)malloc(rows * sizeof(int*));
    if (mat == NULL) {
        printf("Пам'ять не виділилась:(\n");
        exit(1);
    }
    
    for (int i = 0; i < rows; i++) {
        mat[i] = (int*)malloc(cols * sizeof(int));
        if (mat[i] == NULL) {
            printf("Помилка виділення пам'яті %d\n", i);
            exit(1);
        }
    }
    return mat;
}
//звільнення пам'яті
void free_matrix(int** matrix, int rows) {
    if (matrix == NULL) return;
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
//заповнення матриці
void fill_matrix(int** matrix, int rows, int cols) {
    printf("--- Заповнення матриці ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char buff[50];
            sprintf(buff, "Елемент [%d][%d]: ", i, j);
            matrix[i][j] = get_int_input(buff);
        }
    }
}
//виведення
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}
//множення
void mult_matrix_by_num(int** matrix, int rows, int cols, int num) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= num; 
        }
    }
}