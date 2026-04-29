#include <stdio.h>
#include "rect.h"
#include "array.h"

int main() {
    Rectangle* r1 = create_from_coords(1.0, 1.0, 4.0, 5.0);

    Point arr_pts[2] = { {0.0, 0.0}, {5.0, 3.0} };
    Rectangle* r2 = create_from_points_array(arr_pts);

    Point pt1 = { -2.0, -2.0 };
    Point pt2 = { 2.0, 2.0 };
    Rectangle* r3 = create_from_point_pointers(&pt1, &pt2);

    Rectangle* invalid = create_from_coords(3.0, 1.0, 3.0, 5.0);

    Array* rectArray = createArray(4);

    printArray(rectArray);

    addElement(rectArray, r1);
    addElement(rectArray, r2);
    printArray(rectArray);

    insertElement(rectArray, r3, 3);
    printArray(rectArray);

    addElement(rectArray, invalid);
    insertElement(rectArray, r1, 10);

    destroyArray(rectArray);

    destroy_rect(r1);
    destroy_rect(r2);
    destroy_rect(r3);
    destroy_rect(invalid);

    return 0;
}
