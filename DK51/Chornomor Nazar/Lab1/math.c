#include "math.h"

int absolute(int a) {
    return a < 0 ? -a : a;
}

int factorial(int a) {
    if (a < 0) return -1;
    
    int result = 1;

    for (int i = 1; i <= a; i++)
        result *= i;
    return result;
}