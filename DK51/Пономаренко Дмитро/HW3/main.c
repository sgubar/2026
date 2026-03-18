#include <stdio.h>
#include "array.h"

int main()
{
    RightTriangle *triangle1 = CreateRightTriangleCoordinates(0, 0, 0, 5, 5, 0);
    RightTriangle *triangle2 = CreateRightTriangleCoordinates(0, 0, 0, 5, 5, 0);
    RightTriangle *triangle3 = CreateRightTriangleCoordinates(0, 0, 0, 5, 5, 0);
    RightTriangle *triangle4 = CreateRightTriangleCoordinates(0, 0, 0, 5, 5, 0);
    RightTriangle *triangle5 = CreateRightTriangleCoordinates(0, 0, 0, 5, 5, 0);

    Array *arr = createArray(2);

    addTriangle(arr, triangle1);
    addTriangle(arr, triangle2);
    printArray(arr);

    printf("\n");

    addTriangle(arr, triangle3);
    addTriangle(arr, triangle4);
    printArray(arr);

    printf("\n");

    addTriangle(arr, triangle5);
    printArray(arr);

    destroyArray(arr);

    DestroyRightTriangle(triangle1);
    DestroyRightTriangle(triangle2);
    DestroyRightTriangle(triangle3);
    DestroyRightTriangle(triangle4);
    DestroyRightTriangle(triangle5);

    return 1;
}
