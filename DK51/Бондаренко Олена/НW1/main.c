#include <stdio.h>
#include "dk_tool.h"

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], Rez[MAX][MAX];

    printf("Matrix Multiplication Program\n");

    n = vvid_chisla("Enter matrix size", 1, MAX);

    zapolny_matr(n, A, 'A');
    zapolny_matr(n, B, 'B');

    mnozh_matr(n, A, B, Rez);

    vivod_matr(n, A, "Matrix A");
    vivod_matr(n, B, "Matrix B");
    vivod_matr(n, Rez, "Result (A * B)");

    return 0;
}
