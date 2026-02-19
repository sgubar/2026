#include "math.h"
#include <stdio.h>

double factorial(int num)
{
    if (num < 0)
        return -1;

    double result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;

    return result;
}

double power(int base, int pow)
{
    if (pow == 0)
        return -1;

    double result = 1;
    for (int i = 0; i < pow; i++)
        result *= base;

    return result;
}
double q(int a, int b, int c)
{
    if (b + power(5, c) == 0)
        return -1;
    double result = (power(a, 2) + power(b, 2)) / (b + power(5, c)) + factorial(b);
    return result;
}