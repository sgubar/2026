
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool.h"

int factorial(int base)
{
    int result = 1;

    while (base > 0)
    {
        result = result * base;
        base--;
    }

    return result;
}

double calculate_expression(double A, int B, double C)
{
    return ((pow(A, 2) + pow(B, 2)) / (B + pow(5, C)));
}

double get_double_input(const char *prompt)
{
    double value;

    printf("%s", prompt);

    while (scanf("%lf", &value) != 1)
    {
        printf("Error! Enter a number: ");
        while (getchar() != '\n');
    }

    return value;
}

int get_int_input(const char *prompt)
{
    int value;

    printf("%s", prompt);

    while (scanf("%d", &value) != 1)
    {
        printf("Error! Enter an integer: ");
        while (getchar() != '\n');
    }

    return value;
}
