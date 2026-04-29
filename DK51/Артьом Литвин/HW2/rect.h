#ifndef RECT_H
#define RECT_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Rectangle;

Rectangle* create_from_coords(double x1, double y1, double x2, double y2);
Rectangle* create_from_points_array(Point pts[]);
Rectangle* create_from_point_pointers(Point* p1, Point* p2);
double calc_area(Rectangle* rect);
void print_rect(Rectangle* rect);
void destroy_rect(Rectangle* rect);

#endif