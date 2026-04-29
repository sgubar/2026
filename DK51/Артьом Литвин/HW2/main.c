#include <stdio.h>
#include "rect.h"

int main() {
    Rectangle* r1 = create_from_coords(1.0, 1.0, 4.0, 5.0);
    print_rect(r1);

    Point arr[2] = { {0.0, 0.0}, {5.0, 3.0} };
    Rectangle* r2 = create_from_points_array(arr);
    print_rect(r2);

    Point pt1 = { -2.0, -2.0 };
    Point pt2 = { 2.0, 2.0 };
    Rectangle* r3 = create_from_point_pointers(&pt1, &pt2);
    print_rect(r3);

    Rectangle* invalid = create_from_coords(3.0, 1.0, 3.0, 5.0);
    print_rect(invalid);

    printf("\nArray of rectangles:\n");
    Rectangle* r_arr[3] = { r1, r2, r3 };
    for (int i = 0; i < 3; i++) {
        print_rect(r_arr[i]);
    }

    destroy_rect(r1);
    destroy_rect(r2);
    destroy_rect(r3);

    return 0;
}
