#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main() {
    int r = get_int_input("Rows: ");
    int c = get_int_input("Cols: ");

    int *A = (int *)malloc(r * c * sizeof(int));
    int *B = (int *)malloc(r * c * sizeof(int));
    int *S = (int *)malloc(r * c * sizeof(int));

    if (!A || !B || !S) return 1;

    printf("\nMatrix A:\n"); fill_matrix(r, c, A);
    printf("\nMatrix B:\n"); fill_matrix(r, c, B);

    add_matrices(r, c, A, B, S);

    printf("\nResult A + B:\n");
    print_matrix(r, c, S);

    free(A); free(B); free(S);
    
    return 0;
}
