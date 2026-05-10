#ifndef POINT_H
#define POINT_H

typedef struct {
    double x;
    double y;
} Point;

Point* create_point(double x, double y);
void print_point(const Point* p);
void destroy_point(Point* p);

#endif