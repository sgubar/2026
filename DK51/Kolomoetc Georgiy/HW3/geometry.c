#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"

#define PI 3.14159265358979323846

EllipseShape* create_ellipse_from_array(Point arr[], int size) {
    if (size < 3 || arr == NULL) return NULL;
    EllipseShape* el = (EllipseShape*)malloc(sizeof(EllipseShape));
    if (el == NULL) return NULL;
    el->num_points = 3;
    el->points = (Point*)malloc(3 * sizeof(Point));
    if (el->points == NULL) {
        free(el);
        return NULL;
    }
    for (int i = 0; i < 3; i++) {
        el->points[i] = arr[i];
    }
    return el;
}

EllipseShape* create_ellipse_from_ptrs(Point* ptrs[], int size) {
    if (size < 3 || ptrs == NULL) return NULL;
    EllipseShape* el = (EllipseShape*)malloc(sizeof(EllipseShape));
    if (el == NULL) return NULL;
    el->num_points = 3;
    el->points = (Point*)malloc(3 * sizeof(Point));
    if (el->points == NULL) {
        free(el);
        return NULL;
    }
    for (int i = 0; i < 3; i++) {
        if (ptrs[i] != NULL) {
            el->points[i] = *(ptrs[i]);
        } else {
            free(el->points);
            free(el);
            return NULL;
        }
    }
    return el;
}

EllipseShape* create_ellipse_from_coords(double coords[], int size) {
    if (size < 6 || coords == NULL) return NULL;
    EllipseShape* el = (EllipseShape*)malloc(sizeof(EllipseShape));
    if (el == NULL) return NULL;
    el->num_points = 3;
    el->points = (Point*)malloc(3 * sizeof(Point));
    if (el->points == NULL) {
        free(el);
        return NULL;
    }
    el->points[0].x = coords[0];
    el->points[0].y = coords[1];
    el->points[1].x = coords[2];
    el->points[1].y = coords[3];
    el->points[2].x = coords[4];
    el->points[2].y = coords[5];
    return el;
}

void destroy_ellipse(EllipseShape* el) {
    if (el != NULL) {
        if (el->points != NULL) {
            free(el->points);
        }
        free(el);
    }
}

double calculate_ellipse_area(EllipseShape* el) {
    if (el == NULL || el->num_points < 3) return 0.0;
    double a = sqrt(pow(el->points[1].x - el->points[0].x, 2) + pow(el->points[1].y - el->points[0].y, 2));
    double b = sqrt(pow(el->points[2].x - el->points[0].x, 2) + pow(el->points[2].y - el->points[0].y, 2));
    return PI * a * b;
}

void print_ellipse_parameters(EllipseShape* el) {
    if (el == NULL) {
        printf("Invalid Ellipse\n");
        return;
    }
    printf("Ellipse Parameters:\n");
    for (int i = 0; i < el->num_points; i++) {
        if (i == 0) printf("  Center: ");
        else if (i == 1) printf("  Semi-major axis point: ");
        else if (i == 2) printf("  Semi-minor axis point: ");
        printf("(%.2f, %.2f)\n", el->points[i].x, el->points[i].y);
    }
    printf("  Calculated Area: %.4f\n", calculate_ellipse_area(el));
}
