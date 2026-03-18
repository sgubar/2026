#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"

int main() {
    printf("=== Testing the 'Ellipse' module ===\n\n");

    Point pts_array[2] = {{0.0, 0.0}, {4.0, 3.0}};
    Ellipse* e1 = create_ellipse_from_points(pts_array);
    print_ellipse(e1);
    printf("\n");

    Point p1 = {2.0, 2.0};
    Point p2 = {7.0, 8.0};
    const Point* ptr_array[2] = {&p1, &p2};
    Ellipse* e2 = create_ellipse_from_point_ptrs(ptr_array);
    print_ellipse(e2);
    printf("\n");

    Ellipse* e3 = create_ellipse_from_coords(-1.0, -1.0, -3.0, -9.0);
    print_ellipse(e3);
    printf("\n");

    printf("--- Working with an array of figures ---\n");
    Ellipse* array_of_ellipses[3] = {e1, e2, e3};
    for(int i = 0; i < 3; i++) {
        printf("Figure %d area: %.2f\n", i+1, calculate_ellipse_area(array_of_ellipses[i]));
    }

    destroy_ellipse(e1);
    destroy_ellipse(e2);
    destroy_ellipse(e3);

    printf("\nAll figures successfully deleted from memory.\n");

    return 0;
}
