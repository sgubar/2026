#include "math.h"

double custom_pow(double base, int exp) {
    if (exp == 0) return 1.0;
    double res = 1.0;
    int pos_exp = exp > 0 ? exp : -exp;
    for (int i = 0; i < pos_exp; ++i) {
        res *= base;
    }
    return exp > 0 ? res : 1.0 / res;
}

unsigned long long custom_factorial(int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    unsigned long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

double custom_abs(double x) {
    return x < 0.0 ? -x : x;
}