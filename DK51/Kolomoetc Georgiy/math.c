#include "math.h"

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

double calculate_sum(int B) {
    double sum = 0.0;
    for (int D = 0; D <= B; D++) {
        sum += (double)factorial(D);
    }
    return sum;
}
