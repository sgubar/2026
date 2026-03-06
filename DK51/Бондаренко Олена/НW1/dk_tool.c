#include <stdio.h>
#include "dk_tool.h"

int vvid_chisla(const char *text, int min, int max) {
    int n;
    do {
        printf("%s (%d-%d): ", text, min, max);
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            printf("Error! Please enter a valid number.\n");
            continue;
        }
    } while (n < min || n > max);
    return n;
}

void zapolny_matr(int n, int m[MAX][MAX], char simvol) {
    printf("\nEnter elements for matrix %c:\n", simvol);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c[%d][%d] = ", simvol, i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void vivod_matr(int n, int m[MAX][MAX], const char *nazva) {
    printf("\n--- %s ---\n", nazva);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

void mnozh_matr(int n, int A[MAX][MAX], int B[MAX][MAX], int Rez[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Rez[i][j] = 0;
            for (int k = 0; k < n; k++) {
                Rez[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
