#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("--- Lab Work 1 (Variant 2) ---\n\n");

    int A = get_valid_int("Enter A (integer >= 0): ", 0);
    double B = get_valid_double("Enter B (any number): ");
    
    double C;
    while (1) {
        C = get_valid_double("Enter C (cannot be 0): ");
        if (C != 0.0) break;
        printf("Error: Division by zero!\n");
    }

    double Q = calculate_Q(A, B, C);
    
    printf("\n--- Result ---\n");
    printf("A = %d, B = %.2f, C = %.2f\n", A, B, C);
    printf("Q = %.4f\n", Q);
    printf("--------------\n");

    return 0;
}
