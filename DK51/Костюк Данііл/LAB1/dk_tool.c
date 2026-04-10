#include "dk_tool.h"
#include <stdio.h>
#include <math.h> // Потрібно для fabs()

// Функція піднесення до степеня
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Функція обчислення суми (від 0 до A)
double calculate_sum(int A) {
    double sum = 0.0;
    for (int D = 0; D <= A; D++) {
        sum += power(2.0, D);
    }
    return sum;
}

// Головна формула: Q = (|A * C - B| / C^3) * Sum
double calculate_Q(int A, double B, double C) {
    // fabs() обчислює модуль чисельника відповідно до завдання
    double fraction = fabs(A * C - B) / power(C, 3);
    double sum_part = calculate_sum(A);
    return fraction * sum_part;
}

// Зчитування цілого числа з перевіркою
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

// Зчитування дробового числа (виправлено формат на %lf)
double get_valid_double(const char* prompt) {
    double val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &val) == 1) { // %lf для коректного зчитування double
            while(getchar() != '\n'); 
            return val;
        }
        while(getchar() != '\n'); 
        printf("Error: Invalid input. Please enter a number.\n");
    }
}
