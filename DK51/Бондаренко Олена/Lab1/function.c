#include "function.h"

double absolute_value(double x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

double power(double base, int exponent) {
    if (exponent == 0) return 1.0;
   
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result = result * base;
    }
    return result;
}


double sum_2D(int A) {
    double total_sum = 0;
    for (int D = 0; D <= A; D++) {
        total_sum = total_sum + power(2.0, D);
    }
    return total_sum;
}


double q(int A, double B, double C) {
    double top = absolute_value(A * C - B);
    double bottom = power(C, 3);
    double sum_part = sum_2D(A);
   
    return (top / bottom) * sum_part;
}
