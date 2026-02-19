#include <stdio.h>
#include "math.h"

void main()
{
    int a, b, c;
    printf("Enter number A: ");
    scanf("%d", &a);

    printf("Enter number B: ");
    scanf("%d", &b);

    printf("Enter number C: ");
    scanf("%d", &c);

    double result = q(a, b, c);
    printf("Result: %f", result);
}
