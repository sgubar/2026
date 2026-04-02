#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "geometry_.h"

// Константа похибки для порівняння чисел із плаваючою комою
#define EPSILON 1e-6

// Допоміжна функція: порівняння double
bool is_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

double get_double(const char* prompt) {
    double value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf%c", &value, &term) != 2 || term != '\n') {
            printf("Error! Please enter a valid number.\n");
            while (getchar() != '\n'); // Очищення буфера
        } else {
            return value;
        }
    }
}

double get_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функція для сортування точок проти годинникової стрілки
void sort_points_ccw(Point pts[4]) {
    double cx = 0, cy = 0;
    // Знаходимо центр квадрата
    for (int i = 0; i < 4; i++) {
        cx += pts[i].x;
        cy += pts[i].y;
    }
    cx /= 4.0;
    cy /= 4.0;

    // Сортування бульбашкою за кутом відносно центру
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            double angle1 = atan2(pts[j].y - cy, pts[j].x - cx);
            double angle2 = atan2(pts[j+1].y - cy, pts[j+1].x - cx);
            if (angle1 > angle2) {
                Point temp = pts[j];
                pts[j] = pts[j+1];
                pts[j+1] = temp;
            }
        }
    }
}

bool is_valid_square(Point pts[4]) {
    // Після сортування сторони це: 0-1, 1-2, 2-3, 3-0. Діагоналі: 0-2, 1-3.
    double s1 = get_distance(pts[0], pts[1]);
    double s2 = get_distance(pts[1], pts[2]);
    double s3 = get_distance(pts[2], pts[3]);
    double s4 = get_distance(pts[3], pts[0]);

    double d1 = get_distance(pts[0], pts[2]);
    double d2 = get_distance(pts[1], pts[3]);

    if (s1 < EPSILON) return false; // Захист від точок з однаковими координатами

    // У квадрата всі сторони рівні ТА обидві діагоналі рівні
    return is_equal(s1, s2) && is_equal(s2, s3) && is_equal(s3, s4) && is_equal(d1, d2);
}

Square* create_square_from_array(Point pts[4]) {
    if (pts == NULL) return NULL;

    // 1. Сортуємо точки, щоб вони йшли по порядку контуру
    sort_points_ccw(pts);

    // 2. Робимо жорстку перевірку
    if (!is_valid_square(pts)) {
        printf("\n[CRITICAL ERROR]: The entered coordinates do not form a true square!\n");
        exit(EXIT_FAILURE); // Миттєва зупинка програми
    }

    // 3. Якщо все добре, створюємо об'єкт у пам'яті
    Square* s = (Square*)malloc(sizeof(Square));
    s->vertices = (Point*)malloc(4 * sizeof(Point));
    for (int i = 0; i < 4; i++) {
        s->vertices[i] = pts[i];
    }
    s->side = get_distance(pts[0], pts[1]);
    return s;
}

Square* create_square_from_coords(double coords[8]) {
    if (coords == NULL) return NULL;
    Point pts[4];
    for (int i = 0; i < 4; i++) {
        pts[i].x = coords[i * 2];
        pts[i].y = coords[i * 2 + 1];
    }
    // Перевикористовуємо функцію, щоб до коду з координатами теж застосовувалися жорсткі правила
    return create_square_from_array(pts);
}

double calculate_area(Square* s) {
    if (s == NULL) return 0.0;
    return s->side * s->side;
}

void print_square_info(Square* s) {
    if (s == NULL) {
        printf("Error: The shape does not exist.\n");
        return;
    }
    printf("SHAPE: Square\n");
    printf("Side: %.2f\n", s->side);
    printf("Coordinates of vertices (sorted): ");
    for (int i = 0; i < 4; i++) {
        printf("(%.1f, %.1f) ", s->vertices[i].x, s->vertices[i].y);
    }
    printf("\nArea of the figure: %.2f\n", calculate_area(s));
    printf("---------------------------\n");
}

void destroy_square(Square* s) {
    if (s != NULL) {
        free(s->vertices); 
        free(s);           
        printf("Memory freed (Square).\n");
    }
}