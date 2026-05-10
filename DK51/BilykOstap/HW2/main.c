#include <stdio.h>
#include "trian.h"

int main() {
    system("chcp 65001 > nul");

    Point pts_array[3] = {{0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}};
    Triangle* t1 = create_triangle_from_array(pts_array);

    printf("- Трикутник 1 (з масиву точок) -\n");
    print_triangle(t1);
    printf("\n");

    Point pA = {1.0, 1.0};
    Point pB = {5.0, 1.0};
    Point pC = {3.0, 5.0};
    Triangle* t2 = create_triangle_from_pointers(&pA, &pB, &pC);

    printf("- Трикутник 2 (з вказівників на точки) -\n");
    print_triangle(t2);
    printf("\n");

    double coords[6] = {-2.0, -2.0, 2.0, -2.0, 0.0, 2.0};
    Triangle* t3 = create_triangle_from_coords(coords);

    printf("- Трикутник 3 (з масиву координат) -\n");
    print_triangle(t3);
    printf("\n");

    printf("- Масив фігур -\n");
    Triangle* triangles_array[3] = {t1, t2, t3};

    for (int i = 0; i < 3; i++) {
        printf("Площа фігури %d: %.2f\n", i + 1, calculate_triangle_area(triangles_array[i]));
    }
    printf("\n");

    double bad_coords[6] = {0.0, 0.0, 1.0, 1.0, 2.0, 2.0}; // Лежать на одній прямій
    Triangle* t_bad = create_triangle_from_coords(bad_coords);
    printf("- Трикутник 4 (вироджений) -\n");
    print_triangle(t_bad);
    printf("\n");

    destroy_triangle(t1);
    destroy_triangle(t2);
    destroy_triangle(t3);
    destroy_triangle(t_bad);

    printf("Усі фігури видалені з пам'яті\n");

    return 0;
}