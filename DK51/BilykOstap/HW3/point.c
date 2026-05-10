#include "point.h"
#include <stdio.h>
#include <stdlib.h>

Point* create_point(double x, double y) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

void print_point(const Point* p) {
    if (p != NULL) {
        printf("(%.2f, %.2f)", p->x, p->y);
    }
}

void destroy_point(Point* p) {
    if (p != NULL) {
        free(p);
    }
}