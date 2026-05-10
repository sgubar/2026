#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "math.h"

double get_double(const char* prompt) {
    double val;
    char buffer[256];
    char extra;
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf %c", &val, &extra) == 1) {
                return val;
            }
        }
        printf("Некоректно формат. Введіть дійсне число\n");
    }
}

// функція для зчитування чисел
int get_int_with_limits(const char* prompt, int min_val, int max_val) {
    int val;
    char buffer[256];
    char extra;
    while (true) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d %c", &val, &extra) == 1) {
                if (val < min_val || val > max_val) {
                    printf("Число повинно бути в межах від %d до %d\n", min_val, max_val);
                    continue;
                }
                return val;
            }
        }
        printf("Некоректно. Введіть ціле число\n");
    }
}

int main() {
    system("chcp 65001 > nul");

    double A, C;
    int B;

    // цикл перевірки математичних обмежень
    while (true) {

        printf("- Введення даних -\n");
        A = get_double("Введіть число A (будь-яке дійсне): ");
        B = get_int_with_limits("Введіть число B (ціле, від 0 до 20): ", 0, 20);
        C = get_double("Введіть число C (будь-яке дійсне): ");

        double denominator = B + custom_pow(C, 2);
        
        // перевірка діленя на нуль
        if (custom_abs(denominator) < 1e-9) {
            printf("\nНекоректно. Знаменник (B + C^2) дорівнює нулю\n");
            printf("Це ділення на нуль. Введіть інші значення\n\n");
        } else {
            break;
        }
    }

    // обчислення суми факторіалів
    unsigned long long sum_factorial = 0;
    for (int D = 0; D <= B; ++D) {
        sum_factorial += custom_factorial(D);
    }

    // загальне обчислення
    double denominator = B + custom_pow(C, 2);
    double Q = (A * B) / denominator + (double)sum_factorial;

    printf("\n= Результат =\n");
    printf("A = %.2lf, B = %d, C = %.2lf\n", A, B, C);
    printf("Сума факторіалів: %llu\n", sum_factorial);
    printf("Q = %lf\n", Q);

    return 0;
}