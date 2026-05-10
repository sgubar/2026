#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main() {
    system("chcp 65001 > nul");

    //введення та валідація
    int rows = get_int_input("Введіть кількість рядків матриці (> 0): ");
    while (rows <= 0) {
        printf("Розмір має бути більше нуля!\n");
        rows = get_int_input("Введіть кількість рядків: ");
    }

    int cols = get_int_input("Введіть кількість стовпців матриці (> 0): ");
    while (cols <= 0) {
        printf("Розмір має бути більше нуля\n");
        cols = get_int_input("Введіть кількість стовпців: ");
    }
    int multiplier = get_int_input("\nВведіть число, на яке будемо множити матрицю: ");

    // створення матриці
    int** matrix = create_matrix(rows, cols);

    fill_matrix(matrix, rows, cols);

    printf("\nМатриця:\n");
    print_matrix(matrix, rows, cols);

    mult_matrix_by_num(matrix, rows, cols, multiplier);

    printf("\nМатриця після множення на %d:\n", multiplier);
    print_matrix(matrix, rows, cols);

    free_matrix(matrix, rows);

    printf("\nГотово\n");


    return 0;
}