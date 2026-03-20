#include "math.h"
#include <stdio.h>

double factorial(int number)
{
    if (number < 0)
        return 0;

    double result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }

    return result;
}
double module(double number)
{
    if (number < 0)
        return number * -1;

    return number;
}
double Q(double A, double B)
{
    double denominator = module(2 * A + B);
    if (denominator == 0)
        return -1;

    double numerator = factorial(A);

    // printf("Numerator: %f, Denominator: %f\n", numerator, denominator);

    return numerator / denominator;
}