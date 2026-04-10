#include <stdio.h>
#include "geometry.h"
#include "array.h"

int main() {
    Point p_arr[3] = {{0.0, 0.0}, {5.0, 0.0}, {0.0, 3.0}};
    EllipseShape* el1 = create_ellipse_from_array(p_arr, 3);

    Point p1 = {2.0, 2.0}, p2 = {6.0, 2.0}, p3 = {2.0, 4.0};
    Point* ptr_arr[3] = {&p1, &p2, &p3};
    EllipseShape* el2 = create_ellipse_from_ptrs(ptr_arr, 3);

    double coords[6] = {-1.0, -1.0, 3.0, -1.0, -1.0, 1.0};
    EllipseShape* el3 = create_ellipse_from_coords(coords, 6);

    FigureArray* my_array = create_array(5);

    add_to_array(my_array, el1);
    add_to_array(my_array, el2);

    insert_into_array(my_array, el3, 4);

    print_array(my_array);

    destroy_array(my_array);

    return 0;
}
