#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* points;
    int num_points;
} EllipseShape;

EllipseShape* create_ellipse_from_array(Point arr[], int size);
EllipseShape* create_ellipse_from_ptrs(Point* ptrs[], int size);
EllipseShape* create_ellipse_from_coords(double coords[], int size);
void destroy_ellipse(EllipseShape* el);
double calculate_ellipse_area(EllipseShape* el);
void print_ellipse_parameters(EllipseShape* el);

#endif
