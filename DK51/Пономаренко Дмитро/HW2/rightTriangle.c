#include "rightTriangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

RightTriangle *CreateRightTriangle(Point *A, Point *B, Point *C)
{
    RightTriangle *triangle = malloc(sizeof(RightTriangle));
    if (triangle != NULL)
    {
        triangle->A = A;
        triangle->B = B;
        triangle->C = C;
    }
    if (!Check(triangle))
        return NULL;

    printf("Right triangle created successfully.\n");
    return triangle;
}

RightTriangle *CreateRightTriangleArray(Point **points)
{
    RightTriangle *triangle = CreateRightTriangle(points[0], points[1], points[2]);
    return triangle;
}

RightTriangle *CreateRightTriangleCoordinates(int x1, int y1, int x2, int y2, int x3, int y3)
{
    Point *A = CreatePoint(x1, y1);
    Point *B = CreatePoint(x2, y2);
    Point *C = CreatePoint(x3, y3);

    RightTriangle *triangle = CreateRightTriangle(A, B, C);
    return triangle;
}

void PrintRightTriangle(RightTriangle *triangle)
{
    if (triangle != NULL)
    {
        printf("Right Triangle:\n");
        PrintPoint(triangle->A);
        PrintPoint(triangle->B);
        PrintPoint(triangle->C);
    }
    else
    {
        printf("Triangle is NULL.\n");
    }
}

void DestroyRightTriangle(RightTriangle *triangle)
{
    if (triangle != NULL)
    {
        DestroyPoint(triangle->A);
        DestroyPoint(triangle->B);
        DestroyPoint(triangle->C);
        free(triangle);
    }
}

int Check(RightTriangle *triangle)
{
    if (triangle == NULL || triangle->A == NULL || triangle->B == NULL || triangle->C == NULL)
    {
        printf("Invalid triangle: one or more points are NULL.\n");
        return 0;
    }

    int AB_squared = (triangle->B->x - triangle->A->x) * (triangle->B->x - triangle->A->x) +
                     (triangle->B->y - triangle->A->y) * (triangle->B->y - triangle->A->y);
    int AC_squared = (triangle->C->x - triangle->A->x) * (triangle->C->x - triangle->A->x) +
                     (triangle->C->y - triangle->A->y) * (triangle->C->y - triangle->A->y);
    int BC_squared = (triangle->C->x - triangle->B->x) * (triangle->C->x - triangle->B->x) +
                     (triangle->C->y - triangle->B->y) * (triangle->C->y - triangle->B->y);

    int result = (AB_squared + AC_squared == BC_squared) ||
                 (AB_squared + BC_squared == AC_squared) ||
                 (AC_squared + BC_squared == AB_squared);

    if (!result)
    {
        DestroyRightTriangle(triangle);
        printf("The points do not form a right triangle.\n");
    }

    return result;
}

int GetDistance(Point *p1, Point *p2)
{
    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;
    return dx * dx + dy * dy;
}

double GetArea(RightTriangle *triangle)
{
    int AB = GetDistance(triangle->A, triangle->B);
    int AC = GetDistance(triangle->A, triangle->C);
    int BC = GetDistance(triangle->B, triangle->C);

    if (AB + AC == BC)
        return 0.5 * sqrt(AB) * sqrt(AC);

    else if (AB + BC == AC)
        return 0.5 * sqrt(AB) * sqrt(BC);

    else if (AC + BC == AB)
        return 0.5 * sqrt(AC) * sqrt(BC);

    return 0;
}