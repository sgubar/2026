#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_area(const Triangle* t) {
    if (!t) return 0.0;
    return 0.5 * fabs(
        t->p[0].x * (t->p[1].y - t->p[2].y) +
        t->p[1].x * (t->p[2].y - t->p[0].y) +
        t->p[2].x * (t->p[0].y - t->p[1].y)
    );
}

int is_valid_triangle(Point p1, Point p2, Point p3) {
    double area = 0.5 * fabs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
    return area > 1e-9;
}

Triangle* create_from_points_array(const Point points[3]) {
    if (!points) return NULL;
    if (!is_valid_triangle(points[0], points[1], points[2])) {
        printf("Помилка: Точки лежать на одній прямій.\n");
        return NULL;
    }
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t) {
        t->p[0] = points[0];
        t->p[1] = points[1];
        t->p[2] = points[2];
    }
    return t;
}

Triangle* create_from_point_pointers(const Point* p1, const Point* p2, const Point* p3) {
    if (!p1 || !p2 || !p3) return NULL;
    if (!is_valid_triangle(*p1, *p2, *p3)) {
        printf("Помилка: Точки лежать на одній прямій.\n");
        return NULL;
    }
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t) {
        t->p[0] = *p1;
        t->p[1] = *p2;
        t->p[2] = *p3;
    }
    return t;
}

Triangle* create_from_coordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    Point p1 = {x1, y1};
    Point p2 = {x2, y2};
    Point p3 = {x3, y3};
    
    if (!is_valid_triangle(p1, p2, p3)) {
        printf("Помилка: Вказані координати не утворюють трикутник.\n");
        return NULL;
    }
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t) {
        t->p[0] = p1;
        t->p[1] = p2;
        t->p[2] = p3;
    }
    return t;
}

void destroy_triangle(Triangle* t) {
    if (t) {
        free(t);
    }
}

void print_triangle_info(const Triangle* t) {
    if (!t) {
        printf("Фігура не існує (NULL).\n");
        return;
    }
    printf("Трикутник з вершинами:\n");
    // Используем кириллические А, Б, В
    printf("  А(%.2f, %.2f)\n", t->p[0].x, t->p[0].y);
    printf("  Б(%.2f, %.2f)\n", t->p[1].x, t->p[1].y);
    printf("  В(%.2f, %.2f)\n", t->p[2].x, t->p[2].y);
    printf("Площа: %.2f\n\n", calculate_area(t));
}
