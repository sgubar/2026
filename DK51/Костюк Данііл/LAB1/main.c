#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("--- Laboratory Work No. 1 ---\n");
    printf("Student: Kostyuk D.V., Group: DK-51\n"); // Дані з титульного аркушу [cite: 47, 48]
    printf("Formula: Q = (|A * C - B| / C^3) * Sum(2^D) for D=0 to A\n\n");

    int A = get_valid_int("Enter A (sum limit, A >= 0): ", 0);
    double B = get_valid_double("Enter B: ");
    
    double C;
    while (1) {
        C = get_valid_double("Enter C (C != 0): ");
        if (C != 0.0) break;
        printf("Error: Division by zero is not allowed!\n");
    }

    double Q = calculate_Q(A, B, C);
    
    printf("\n--- Results ---\n");
    printf("Result Q = %.4f\n", Q);
    printf("---------------\n");

    return 0;
}
