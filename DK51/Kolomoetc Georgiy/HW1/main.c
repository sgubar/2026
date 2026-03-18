#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main() {
    int size;

    printf("--- Array Reversal Program ---\n");

    do {
        size = getValidInt("Enter array size (greater than 0): ");
        if (size <= 0) {
            printf("Array size must be positive!\n");
        }
    } while (size <= 0);

    int *myArray = (int *)malloc(size * sizeof(int));
    if (myArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\n--- Filling the array ---\n");
    fillArray(myArray, size);

    printf("\nOriginal array: \n");
    printArray(myArray, size);

    reverseArray(myArray, size);

    printf("\nReversed array: \n");
    printArray(myArray, size);

    free(myArray);

    return 0;
}
