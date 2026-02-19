#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main(int argc, char** argv) {
    int a, b;

    // input
    printf("Enter first integer: ");
    scanf("%i",&a);

    printf("Enter second integer: ");
    scanf("%i",&b);

    // program behavior

    double Q;
    int fact, abso;

    fact = factorial(a);
    abso = absolute(2 * a + b);

    if (abso <= 0) {printf("Division by zero!"); return 1;}
    Q = (double)fact / abso;

    // printing result
    printf("Result: %.2lf\n", Q);

    return 0;
}
