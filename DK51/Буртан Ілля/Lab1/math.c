// Функція для безпечного введення ("Захист від дурня")
int get_int(const char* prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            printf("Помилка! Будь ласка, введіть ціле число.\n");
            while (getchar() != '\n'); // Очищення буфера
        } else {
            return value;
        }
    }
}

// Функція для обчислення факторіалу
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Функція для обчислення суми факторіалів (знак Сигми)
unsigned long long calculate_sum(int A, int C) {
    unsigned long long sum = 0;
    for (int D = 0; D <= C; D++) {
        sum += factorial(A + D);
    }
    return sum;
}