#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int** create_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++ ) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    
    }
    return matrix;

}

void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_matrix(int** matrix, int rows, int cols, char name) {
    printf("--- Заповнення матриці %c ---\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}


void print_matrix(int** matrix, int rows, int cols, const char* name) {
    printf("Матриця %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** subtract_matrices(int** mat1, int** mat2, int rows, int cols) {
    
    int** result = create_matrix(rows, cols);
    

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}