#include "rightTriangle.h"

int main()
{
    RightTriangle *t1 = CreateRightTriangleCoordinates(0, 0, 3, 0, 0, 4);
    RightTriangle *t2 = CreateRightTriangleCoordinates(0, 0, 2, 0, 1, 2);

    Point *points[] = {CreatePoint(0, 0), CreatePoint(3, 0), CreatePoint(0, 4)};
    RightTriangle *t3 = CreateRightTriangleArray(points);

    RightTriangle *t4 = CreateRightTriangle(points[0], points[1], points[2]);

    PrintRightTriangle(t1);
    PrintRightTriangle(t2);
    PrintRightTriangle(t3);
    PrintRightTriangle(t4);

    DestroyRightTriangle(t1);
    DestroyRightTriangle(t2);
    DestroyRightTriangle(t3);
    DestroyRightTriangle(t4);

    return 0;
}
