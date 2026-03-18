#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Array *createArray(int size)
{
    Array *result = malloc(sizeof(Array));

    if (result != NULL)
    {
        result->memoryCount = (size > 0) ? size : 4;
        result->count = 0;
        result->storage = malloc(sizeof(RightTriangle *) * result->memoryCount);

        if (result->storage == NULL)
        {
            free(result);
            return NULL;
        }
        else
        {
            memset(result->storage, 0, sizeof(RightTriangle *) * result->memoryCount);
        }
    }
    return result;
};
void destroyArray(Array *array)
{
    if (array == NULL)
        return;

    // for (int i = 0; i < array->count; i++)
    // {
    //     free(array->storage[i]);
    // }

    free(array->storage);
    free(array);
};

int addTriangle(Array *array, RightTriangle *triangle)
{
    if (array == NULL || triangle == NULL)
        return -1;

    if (array->count == array->memoryCount)
    {
        if (extendArray(array) != 0)
            return -1;
    }

    array->storage[array->count] = triangle;
    array->count++;

    return array->count;
};
int addTriangleByIndex(Array *array, RightTriangle *triangle, int index)
{
    if (array == NULL || triangle == NULL)
        return -1;

    if (index > array->count)
        return -1;

    array->storage[index] = triangle;

    return index;
};
int extendArray(Array *array)
{
    if (array == NULL)
        return -1;

    array->memoryCount *= 2;
    RightTriangle **newStorage = malloc(sizeof(RightTriangle *) * array->memoryCount);

    if (newStorage == NULL)
        return -1;

    memcpy(newStorage, array->storage, sizeof(RightTriangle *) * array->count);
    free(array->storage);
    array->storage = newStorage;

    return 0;
};
void printArray(Array *array)
{
    if (array == NULL)
        return;

    printf("[ ");
    for (int i = 0; i < array->count; i++)
    {
        PrintRightTriangle(array->storage[i]);
    }
    printf("]");
};