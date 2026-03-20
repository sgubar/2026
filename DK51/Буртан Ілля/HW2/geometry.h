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

double pow(double base, int exp);

// Допоміжна функція для обчислення відстані між двома точками
double get_distance(Point p1, Point p2);

// Перевіряємо, чи рівні сторони та чи рівні діагоналі
bool is_valid_square(Point pts[4]);

// c) Функції створення фігури (3 варіанти)

// 1. Через масив точок
Square* create_square_from_array(Point pts[4]);

// 2. Через перелік вказівників на структуру точки
Square* create_square_from_ptrs(Point* p1, Point* p2, Point* p3, Point* p4);

// 3. Через перелік координат (масив double)
Square* create_square_from_coords(double coords[8]);

// f) Функція виводу параметрів на екран
void print_square_info(Square* s);

// d) Функція, що знищує створену фігуру
void destroy_square(Square* s);