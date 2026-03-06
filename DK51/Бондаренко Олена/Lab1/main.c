#include <stdio.h>
#include "function.h"


int main() {
    int A;
    double B, C;


    printf("--- Calculation of Q ---\n");


    printf("Enter A (integer, A >= 0): ");
    if (scanf("%d", &A) != 1) return 1;
   
    if (A < 0) {
        printf("Error: A cannot be negative!\n");
        return 1;
    }


    printf("Enter B: ");
    if (scanf("%lf", &B) != 1) return 1;


    printf("Enter C (not 0): ");
    if (scanf("%lf", &C) != 1) return 1;


    if (C == 0) {
        printf("Error: C cannot be 0!\n");
        return 1;
    }


    double result = q(A, B, C);
    printf("\nResult Q = %.4f\n", result);


    return 0;
}
