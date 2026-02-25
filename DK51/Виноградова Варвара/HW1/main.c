#include <stdio.h>
#include "dk_tool.h"
#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int rows, cols;

    printf("Введіть кількість рядків матриць: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців матриць: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("?\n");
        return 0;
    }
        
    
    int** matA = create_matrix(rows, cols);
    int** matB = create_matrix(rows, cols);

    
    fill_matrix(matA, rows, cols, 'A');
    fill_matrix(matB, rows, cols, 'B');

    
    int** matC = subtract_matrices(matA, matB, rows, cols);

    
    print_matrix(matA, rows, cols, "A");
    print_matrix(matB, rows, cols, "B");
    print_matrix(matC, rows, cols, "C (Результат A - B)");

    
    free_matrix(matA, rows);
    free_matrix(matB, rows);
    free_matrix(matC, rows);

    return 0;
}