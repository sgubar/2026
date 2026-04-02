#include <stdio.h>
#include <stdlib.h>
#include "geometry_.h"
#include "array.h"

int main() {
    printf("--- Creating an Array of Squares ---\n");
    
    // Створюємо масив на 3 елементи
    SquareArray* my_array = create_array(3);
    
    // Створюємо правильний квадрат автоматично
    printf("\n--- Square 1 (Auto Created) ---\n");
    double coords[8] = {0, 0, 2, 0, 0, 2, 2, 2}; // Навіть якщо точки врозкид, функція їх відсортує!
    Square* sq1 = create_square_from_coords(coords);
    add_element(my_array, sq1);
    printf("Auto Square successfully added!\n");

    // Введення користувачем
    printf("\n--- Square 2 (User Input) ---\n");
    printf("Note: If you enter points that do NOT make a square, the program will terminate immediately.\n");
    Point user_points[4];
    for (int i = 0; i < 4; i++) {
        printf("Vertex %d:\n", i + 1);
        user_points[i].x = get_double("  Enter X: ");
        user_points[i].y = get_double("  Enter Y: ");
    }
    
    // Якщо дані погані, програма зупиниться саме на цьому рядку
    Square* sq2 = create_square_from_array(user_points);
    add_element(my_array, sq2);

    printf("\nUser Square successfully added!\n");

    // Друк і очищення (виконається тільки якщо ввели правильний квадрат)
    print_array(my_array);
    
    printf("\nDestroying array and all its elements...\n");
    destroy_array(my_array);

    return 0;
}
