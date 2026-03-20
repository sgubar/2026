#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry.h"
#include <stdbool.h>

// g) Приклад використання
int main() {
    printf("--- Creating a square from user input ---\n");
    
    Point user_points[4];
    
    // Зчитуємо координати для 4 вершин
    for (int i = 0; i < 4; i++) {
        printf("Vertex %d:\n", i + 1);
        user_points[i].x = get_double("  Enter X: ");
        user_points[i].y = get_double("  Enter Y: ");
    }

    // Перевіряємо, чи введені точки дійсно утворюють квадрат 
    // (функція is_valid_square з вашого попереднього коду)
    if (!is_valid_square(user_points)) {
        printf("\nWarning: The entered points might not form a valid square or are in the wrong order!\n\n");
    }

    // Створення квадрата через масив точок
    Square* my_square = create_square_from_array(user_points);
    
    // Вивід інформації на екран
    print_square_info(my_square);
    
    // Звільнення пам'яті
    destroy_square(my_square);

    return 0;
}