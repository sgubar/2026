#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


// --- Головна програма ---
int main() {
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);

    printf("Лабораторна робота №1. Варіант 3\n");
    printf("Формула: Q = A * (sqrt(B + C) / B) + sum(D=0..C) (A + D)!\n\n");

    // Введення даних
    int A = get_int("Введіть A (ціле число >= 0): ");
    int B = get_int("Введіть B (ціле число != 0): ");
    int C = get_int("Введіть C (ціле число >= 0): ");

    // Перевірка на недопустимі значення
    if (B == 0) {
        printf("\nПомилка: Ділення на нуль (B = 0)!\n");
        return 1;
    }
    if (B + C < 0) {
        printf("\nПомилка: Корінь з від'ємного числа (B + C < 0)!\n");
        return 1;
    }
    if (C < 0) {
        printf("\nПомилка: Верхня межа суми C не може бути від'ємною!\n");
        return 1;
    }
    if (A < 0) {
        printf("\nПомилка: Факторіал від'ємного числа (A < 0)!\n");
        return 1;
    }

    // Обчислення першої частини (дріб з коренем)
    double term1 = A * (sqrt(B + C) / (double)B);
    
    // Обчислення другої частини (сума)
    unsigned long long sum_factorials = calculate_sum(A, C);
    
    // Загальний результат
    double Q = term1 + sum_factorials;

    // Виведення результату
    printf("\nРезультати обчислень:\n");
    printf("Дріб з коренем: %lf\n", term1);
    printf("Сума факторіалів: %llu\n", sum_factorials);
    printf("Загальний результат Q: %lf\n", Q);

    return 0;
}