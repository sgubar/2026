\#ifndef DK_TOOL_H
#define DK_TOOL_H

// Структура точки
typedef struct {
    double x;
    double y;
} Point;

// Структура трикутника
typedef struct {
    Point p[3];
} Triangle;

// Структура масиву
typedef struct {
    Triangle** elements; // Динамічний масив вказівників
    int capacity;        // Максимальна кількість елементів
} TriangleArray;

// Функції для трикутника
Triangle* create_from_coordinates(double x1, double y1, double x2, double y2, double x3, double y3);
void destroy_triangle(Triangle* t);
void print_triangle_info(const Triangle* t);

// Функції для масиву
TriangleArray* create_array(int capacity);
void free_array(TriangleArray* arr);
int add_element(TriangleArray* arr, Triangle* t);
int insert_element(TriangleArray* arr, Triangle* t, int index);
void print_array(const TriangleArray* arr);

#endif // DK_TOOL_H
