#include <stdio.h>
#include <windows.h> 
#include "dk_tool.h"

int main() {
    // Включаем поддержку UTF-8 в консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printf("--- Тест 1: Створення з масиву точок ---\n");
    Point pts[3] = {{0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}};
    Triangle* t1 = create_from_points_array(pts);
    print_triangle_info(t1);

    printf("--- Тест 2: Створення з вказівників на точки ---\n");
    Point p1 = {1.0, 1.0}, p2 = {5.0, 1.0}, p3 = {3.0, 5.0};
    Triangle* t2 = create_from_point_pointers(&p1, &p2, &p3);
    print_triangle_info(t2);

    printf("--- Тест 3: Створення з координат ---\n");
    Triangle* t3 = create_from_coordinates(-2.0, -2.0, 2.0, -2.0, 0.0, 4.0);
    print_triangle_info(t3);

    printf("--- Тест 4: Масив вказівників на фігури ---\n");
    Triangle* triangles_array[3];
    triangles_array[0] = t1;
    triangles_array[1] = t2;
    triangles_array[2] = t3;
    
    for (int i = 0; i < 3; i++) {
        printf("Фігура з масиву #%d:\n", i + 1);
        print_triangle_info(triangles_array[i]);
    }

    destroy_triangle(t1);
    destroy_triangle(t2);
    destroy_triangle(t3);

    return 0;
}
