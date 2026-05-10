#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>

Triangle* create_triangle(Point* a, Point* b, Point* c) {
    if (a == NULL || b == NULL || c == NULL) return NULL;

    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t != NULL) {
        t->a = a;
        t->b = b;
        t->c = c;
    }
    return t;
}

void print_triangle(const Triangle* t) {
    if (t != NULL) {
        printf("Triangle[");
        print_point(t->a);
        printf(", ");
        print_point(t->b);
        printf(", ");
        print_point(t->c);
        printf("]");
    }
}

void destroy_triangle(Triangle* t) {
    if (t != NULL) {
        free(t);
    }
}