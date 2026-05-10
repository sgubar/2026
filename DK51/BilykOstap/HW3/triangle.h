#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

typedef struct {
    Point* a;
    Point* b;
    Point* c;
} Triangle;

Triangle* create_triangle(Point* a, Point* b, Point* c);
void print_triangle(const Triangle* t);
void destroy_triangle(Triangle* t);

#endif