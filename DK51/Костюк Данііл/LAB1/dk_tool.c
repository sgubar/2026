#include "dk_tool.h"
#include <stdio.h>

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double calculate_sum(int A) {
    double sum = 0.0;
    for (int D = 0; D <= A; D++) {
        sum += power(2.0, D);
    }
    return sum;
}

double calculate_Q(int A, double B, double C) {
    double fraction = (A * C - B) / power(C, 3);
    double sum_part = calculate_sum(A);
    return fraction * sum_part;
}

int get_valid_int(const char* prompt, int min_val) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1 && val >= min_val) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Please enter an integer >= %d.\n", min_val);
    }
}

double get_valid_double(const char* prompt) {
    double val;
    while (1) {
        printf("%s", prompt);
        // ВАЖНО: здесь строго %lf для типа double
        if (scanf("%lf", &val) == 1) {
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Please enter a valid number.\n");
    }
}
