#ifndef ELLIPSE_H
#define ELLIPSE_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    Point axes_point;
} Ellipse;

Ellipse* create_ellipse_from_points(const Point pts[2]);
Ellipse* create_ellipse_from_point_ptrs(const Point* ptrs[2]);
Ellipse* create_ellipse_from_coords(double cx, double cy, double px, double py);
void destroy_ellipse(Ellipse* e);
double calculate_ellipse_area(const Ellipse* e);
void print_ellipse(const Ellipse* e);

#endif
