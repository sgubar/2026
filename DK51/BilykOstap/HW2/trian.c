#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trian.h"

static Triangle* allocate_triangle() {
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t == NULL) {
        fprintf(stderr, "Не вдалося виділити пам'ять\n");
    }
    return t;
}

// створення з масиву
Triangle* create_triangle_from_array(const Point points[3]) {
    if (points == NULL) return NULL; // Перевірка вхідних параметрів

    Triangle* t = allocate_triangle();
    if (t != NULL) {
        t->p1 = points[0];
        t->p2 = points[1];
        t->p3 = points[2];
    }
    return t;
}

// створення з переліку вказівників
Triangle* create_triangle_from_pointers(const Point* p1, const Point* p2, const Point* p3) {
    if (p1 == NULL || p2 == NULL || p3 == NULL) return NULL; // Перевірка вказівників

    Point pts[3] = {*p1, *p2, *p3};
    return create_triangle_from_array(pts);
}

// створення з переліку координат
Triangle* create_triangle_from_coords(const double coords[6]) {
    if (coords == NULL) return NULL;

    Point pts[3] = {
        {coords[0], coords[1]},
        {coords[2], coords[3]},
        {coords[4], coords[5]}
    };
    return create_triangle_from_array(pts);
}

// обчислення площі за формулою
double calculate_triangle_area(const Triangle* t) {
    if (t == NULL) return 0.0;

    double area = 0.5 * fabs(t->p1.x * (t->p2.y - t->p3.y) +
                             t->p2.x * (t->p3.y - t->p1.y) +
                             t->p3.x * (t->p1.y - t->p2.y));
    return area;
}

// вивід параметрів
void print_triangle(const Triangle* t) {
    if (t == NULL) {
        printf("Трикутник не існує.\n");
        return;
    }

    printf("Вершини трикутника:\n");
    printf("  A(%.2f, %.2f)\n", t->p1.x, t->p1.y);
    printf("  B(%.2f, %.2f)\n", t->p2.x, t->p2.y);
    printf("  C(%.2f, %.2f)\n", t->p3.x, t->p3.y);

    double area = calculate_triangle_area(t);
    printf("  Площа: %.2f\n", area);

    if (area == 0.0) {
        printf("Точки лежать на одній прямій або збігаються\n");
    }
}

// знищення фігури
void destroy_triangle(Triangle* t) {
    if (t != NULL) {
        free(t);
    }
}