#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "math.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    double A, C;
    int B;
    int input_status;

    printf("--- Laboratory Work: Variant 1 ---\n");
    printf("Formula: Q = (A * B) / (B + C^2) + Sum(D=0..B) D!\n\n");

    while (1) {
        printf("Enter real number A: ");
        input_status = scanf("%lf", &A);
        if (input_status == 1) {
            clear_buffer();
            break;
        } else {
            printf("-> Error! Invalid input. Try again.\n");
            clear_buffer();
        }
    }

    while (1) {
        printf("Enter non-negative integer B (0 to 20): ");
        input_status = scanf("%d", &B);
        if (input_status == 1) {
            if (B >= 0 && B <= 20) {
                clear_buffer();
                break;
            } else {
                printf("-> Error! B must be in range [0; 20] for correct factorial calculation.\n");
                clear_buffer();
            }
        } else {
            printf("-> Error! Integer required.\n");
            clear_buffer();
        }
    }

    while (1) {
        printf("Enter real number C: ");
        input_status = scanf("%lf", &C);
        if (input_status == 1) {
            if ((B + pow(C, 2)) == 0) {
                printf("-> Error! With these B and C, the denominator (B + C^2) is 0 (division by zero).\n");
                clear_buffer();
            } else {
                clear_buffer();
                break;
            }
        } else {
            printf("-> Error! Invalid input. Try again.\n");
            clear_buffer();
        }
    }

    double denominator = B + pow(C, 2);
    double fraction_part = (A * B) / denominator;
    double sum_part = calculate_sum(B);

    double Q = fraction_part + sum_part;

    printf("\n--- Results ---\n");
    printf("1. Fraction part (A * B) / (B + C^2) = %.6lf\n", fraction_part);
    printf("2. Sum of factorials = %.0lf\n", sum_part);
    printf("----------------------------------\n");
    printf("Final result Q = %.6lf\n", Q);

    return 0;
}
