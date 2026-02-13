#define _CRT_SECURE_NO_WARNINGS

#include "dk_tools.h"
#include "math.h"
#include "stdio.h"

int main()
{
    char numbers[5];
    int result = 0;

    printf("Enter a 4-digit number (Maximum 4 digits): ");
    scanf("%4s", numbers);

    if (!Check(numbers))
        return 0;

    result = Convert(numbers);

    printf("%d\n", result);
}