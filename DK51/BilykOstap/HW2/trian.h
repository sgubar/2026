#ifndef TRIAN_H
#define TRIAN_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
} Triangle;

Triangle* create_triangle_from_array(const Point points[3]);

Triangle* create_triangle_from_pointers(const Point* p1, const Point* p2, const Point* p3);

Triangle* create_triangle_from_coords(const double coords[6]);

void destroy_triangle(Triangle* t);

double calculate_triangle_area(const Triangle* t);

void print_triangle(const Triangle* t);

#endif