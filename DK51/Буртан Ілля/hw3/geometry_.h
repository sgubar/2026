#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// b) Структура точки
typedef struct tagPoint {
    double x;
    double y;
} Point;

// a) Структура фігури (Квадрат)
typedef struct tagSquare {
    Point* vertices; // Динамічний масив із 4-х точок
    double side;     // Довжина сторони
} Square;

double get_double(const char* prompt);

// Допоміжна функція для обчислення відстані між двома точками
double get_distance(Point p1, Point p2);

// Перевіряємо, чи рівні сторони та чи рівні діагоналі
bool is_valid_square(Point pts[4]);

// c) Функції створення фігури (3 варіанти)
Square* create_square_from_array(Point pts[4]);
Square* create_square_from_ptrs(Point* p1, Point* p2, Point* p3, Point* p4);
Square* create_square_from_coords(double coords[8]);

// Функція для обчислення площі
double calculate_area(Square* s);

// f) Функція виводу параметрів на екран
void print_square_info(Square* s);

// d) Функція, що знищує створену фігуру
void destroy_square(Square* s);

#endif // GEOMETRY_H