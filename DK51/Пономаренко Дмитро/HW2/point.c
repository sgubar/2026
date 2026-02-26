#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point *CreatePoint(int x, int y)
{
    Point *result = malloc(sizeof(Point));

    if (result != NULL)
    {
        result->x = x;
        result->y = y;
    }
    return result;
}
void DestroyPoint(Point *p)
{
    if (p != NULL)
        free(p);
}
void PrintPoint(Point *p)
{
    if (p == NULL)
    {
        printf("(null)\n");
        return;
    };

    printf("(%d, %d)\n", p->x, p->y);
}