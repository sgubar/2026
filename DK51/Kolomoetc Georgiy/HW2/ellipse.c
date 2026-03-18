#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ellipse.h"

#define PI 3.14159265358979323846

Ellipse* create_ellipse_from_points(const Point pts[2]) {
    if (pts == NULL) return NULL;

    Ellipse* e = (Ellipse*)malloc(sizeof(Ellipse));
    if (e != NULL) {
        e->center = pts[0];
        e->axes_point = pts[1];
    }
    return e;
}

Ellipse* create_ellipse_from_point_ptrs(const Point* ptrs[2]) {
    if (ptrs == NULL || ptrs[0] == NULL || ptrs[1] == NULL) return NULL;

    Ellipse* e = (Ellipse*)malloc(sizeof(Ellipse));
    if (e != NULL) {
        e->center = *(ptrs[0]);
        e->axes_point = *(ptrs[1]);
    }
    return e;
}

Ellipse* create_ellipse_from_coords(double cx, double cy, double px, double py) {
    Ellipse* e = (Ellipse*)malloc(sizeof(Ellipse));
    if (e != NULL) {
        e->center.x = cx;
        e->center.y = cy;
        e->axes_point.x = px;
        e->axes_point.y = py;
    }
    return e;
}

void destroy_ellipse(Ellipse* e) {
    if (e != NULL) {
        free(e);
    }
}

double calculate_ellipse_area(const Ellipse* e) {
    if (e == NULL) return 0.0;

    double a = fabs(e->axes_point.x - e->center.x);
    double b = fabs(e->axes_point.y - e->center.y);

    return PI * a * b;
}

void print_ellipse(const Ellipse* e) {
    if (e == NULL) {
        printf("Ellipse does not exist.\n");
        return;
    }

    double a = fabs(e->axes_point.x - e->center.x);
    double b = fabs(e->axes_point.y - e->center.y);

    printf("Ellipse [Center: (%.2f, %.2f)]\n", e->center.x, e->center.y);
    printf("  Semi-axis a (X): %.2f\n", a);
    printf("  Semi-axis b (Y): %.2f\n", b);
    printf("  Area: %.2f\n", calculate_ellipse_area(e));
}
