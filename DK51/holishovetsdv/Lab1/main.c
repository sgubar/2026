
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    double A = get_double_input("Enter A: ");
    int B = get_int_input("Enter B: ");
    double C = get_double_input("Enter C: ");

    double Q = calculate_expression(A, B, C) + factorial(B);

    printf("Result = %lf\n", Q);

    return 0;
}
