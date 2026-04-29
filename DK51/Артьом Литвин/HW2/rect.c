#include <stdio.h>
#include <stdlib.h>
#include "rect.h"

Rectangle* create_from_coords(double x1, double y1, double x2, double y2) {
    if (x1 == x2 || y1 == y2) {
        return NULL;
    }

    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (rect == NULL) {
        return NULL;
    }

    rect->p1.x = (x1 < x2) ? x1 : x2;
    rect->p1.y = (y1 < y2) ? y1 : y2;
    rect->p2.x = (x1 > x2) ? x1 : x2;
    rect->p2.y = (y1 > y2) ? y1 : y2;

    return rect;
}

Rectangle* create_from_points_array(Point pts[]) {
    if (pts == NULL) {
        return NULL;
    }
    return create_from_coords(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
}

Rectangle* create_from_point_pointers(Point* p1, Point* p2) {
    if (p1 == NULL || p2 == NULL) {
        return NULL;
    }
    return create_from_coords(p1->x, p1->y, p2->x, p2->y);
}

double calc_area(Rectangle* rect) {
    if (rect == NULL) {
        return 0.0;
    }
    return (rect->p2.x - rect->p1.x) * (rect->p2.y - rect->p1.y);
}

void print_rect(Rectangle* rect) {
    if (rect == NULL) {
        printf("Error: rectangle is NULL\n");
        return;
    }
    printf("Rectangle: p1(%.1lf, %.1lf) p2(%.1lf, %.1lf), Area: %.1lf\n",
        rect->p1.x, rect->p1.y,
        rect->p2.x, rect->p2.y,
        calc_area(rect));
}

void destroy_rect(Rectangle* rect) {
    if (rect != NULL) {
        free(rect);
    }
}