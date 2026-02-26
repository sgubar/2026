#include "point.h"

typedef struct tagRightTriangle
{
    Point *A;
    Point *B;
    Point *C;
} RightTriangle, *PRightTriangle;

RightTriangle *CreateRightTriangle(Point *A, Point *B, Point *C);
RightTriangle *CreateRightTriangleArray(Point **points);
RightTriangle *CreateRightTriangleCoordinates(int x1, int y1, int x2, int y2, int x3, int y3);

void PrintRightTriangle(RightTriangle *triangle);
void DestroyRightTriangle(RightTriangle *triangle);
int Check(RightTriangle *triangle);