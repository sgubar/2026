#ifndef DK_TOOL_H
#define DK_TOOL_H

// Опис структури точки
typedef struct {
    double x;
    double y;
} Point;

// Опис структури фігури (Трикутник)
typedef struct {
    Point p[3]; // Масив з 3-х точок (вершин)
} Triangle;

// Оголошення функцій
double calculate_area(const Triangle* t);
int is_valid_triangle(Point p1, Point p2, Point p3);

Triangle* create_from_points_array(const Point points[3]);
Triangle* create_from_point_pointers(const Point* p1, const Point* p2, const Point* p3);
Triangle* create_from_coordinates(double x1, double y1, double x2, double y2, double x3, double y3);

void destroy_triangle(Triangle* t);
void print_triangle_info(const Triangle* t);

#endif // DK_TOOL_H
