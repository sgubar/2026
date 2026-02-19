int absolute(int a) {
    if (a <= 0) {
        return -a;
    } else {
        return a;
    }
}

int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++)
        result *= i;
    return result;
}