#include "rightTriangle.h"

typedef struct Array
{
    RightTriangle **storage;
    int memoryCount;
    int count;
} Array;

Array *createArray(int size);
void destroyArray(Array *array);

int addTriangle(Array *array, RightTriangle *triangle);
int addTriangleByIndex(Array *array, RightTriangle *triangle, int index);
int extendArray(Array *array);
void printArray(Array *array);