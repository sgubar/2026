#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"
#include <stdbool.h>

double pow(double base, int exp) {
    double result = 1.0; // Початкове значення для множення
    
    // Множимо базу саму на себе стільки разів, який у нас степінь
    for (int i = 0; i < exp; i++) {
        result *= base; // Це те саме, що й result = result * base;
    }
    
    return result;
};

double get_double(const char* prompt) {
    double value;
    char term;
    while (1) {
        printf("%s", prompt);
        // Перевіряємо, чи введено коректне число
        if (scanf("%lf%c", &value, &term) != 2 || term != '\n') {
            printf("Error! Please enter a valid number.\n");
            // Очищення буфера вводу
            while (getchar() != '\n');
        } else {
            return value;
        }
    }
};

double get_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
};

// e) Функція перевірки (чи утворюють точки квадрат)
// Перевіряємо, чи рівні сторони та чи рівні діагоналі
bool is_valid_square(Point pts[4]) {
    double d2 = pow(get_distance(pts[0], pts[1]), 2); // сторона квадрат
    double d3 = pow(get_distance(pts[0], pts[2]), 2); // діагональ
    double d4 = pow(get_distance(pts[0], pts[3]), 2); // сторона
    
    if (d2 == 0 || d3 == 0 || d4 == 0) return false;
    return (d2 == d4 && 2 * d2 == d3); 
};

// c) Функції створення фігури (3 варіанти)

// 1. Через масив точок
Square* create_square_from_array(Point pts[4]) {
    if (pts == NULL) return NULL;
    
    Square* s = (Square*)malloc(sizeof(Square));
    s->vertices = (Point*)malloc(4 * sizeof(Point));
    for (int i = 0; i < 4; i++) {
        s->vertices[i] = pts[i];
    }
    s->side = get_distance(pts[0], pts[1]);
    return s;
};

// 2. Через перелік вказівників на структуру точки
Square* create_square_from_ptrs(Point* p1, Point* p2, Point* p3, Point* p4) {
    if (!p1 || !p2 || !p3 || !p4) return NULL;
    
    Square* s = (Square*)malloc(sizeof(Square));
    s->vertices = (Point*)malloc(4 * sizeof(Point));
    s->vertices[0] = *p1;
    s->vertices[1] = *p2;
    s->vertices[2] = *p3;
    s->vertices[3] = *p4;
    s->side = get_distance(*p1, *p2);
    return s;
};

// 3. Через перелік координат (масив double)
Square* create_square_from_coords(double coords[8]) {
    if (coords == NULL) return NULL;
    Square* s = (Square*)malloc(sizeof(Square));
    s->vertices = (Point*)malloc(4 * sizeof(Point));
    for (int i = 0; i < 4; i++) {
        s->vertices[i].x = coords[i * 2];
        s->vertices[i].y = coords[i * 2 + 1];
    }
    s->side = get_distance(s->vertices[0], s->vertices[1]);
    return s;
};

// Функція для обчислення площі
double calculate_area(Square* s) {
    if (s == NULL) return 0.0;
    return s->side * s->side;
};

// f) Функція виводу параметрів на екран
void print_square_info(Square* s) {
    if (s == NULL) {
        printf("Error: The shape does not exist.\n");
        return;
    }
    printf("SHAPE: Square\n");
    printf("Side: %.2f\n", s->side);
    printf("Coordinates of vertices: ");
    for (int i = 0; i < 4; i++) {
        printf("(%.1f, %.1f) ", s->vertices[i].x, s->vertices[i].y);
    }
    printf("\nArea of the figure: %.2f\n", calculate_area(s));
    printf("---------------------------\n");
};

// d) Функція, що знищує створену фігуру
void destroy_square(Square* s) {
    if (s != NULL) {
        free(s->vertices); // Спочатку звільняємо внутрішній масив точок
        free(s);           // Потім саму структуру
        printf("Memory freed.\n");
    }
};