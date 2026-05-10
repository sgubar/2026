#include <stdio.h>
#include "point.h"
#include "triangle.h"
#include "array.h"

int main() {
    system("chcp 65001 > nul");
    Point* p1 = create_point(0.0, 0.0);
    Point* p2 = create_point(0.0, 3.0);
    Point* p3 = create_point(4.0, 0.0);
    Point* p4 = create_point(1.0, 1.0);
    Point* p5 = create_point(1.0, 4.0);
    Point* p6 = create_point(5.0, 1.0);

    Triangle* t1 = create_triangle(p1, p2, p3);
    Triangle* t2 = create_triangle(p4, p5, p6);
    Triangle* t3 = create_triangle(p1, p4, p6);

    TriangleArray* my_array = create_array(5);

    printf("- Ініціалізація масиву -\n");
    print_array(my_array);

    printf("\n- Додавання елемента t1 -\n");
    int index1 = add_element(my_array, t1);
    printf("Результат: %d\n", index1);
    print_array(my_array);

    printf("\n= Вставка елементу t2 за індексом 3 =\n");
    int index2 = insert_element(my_array, t2, 3);
    printf("Індекс результату: %d\n", index2);
    print_array(my_array);

    printf("\n- Перезапис елемента за індексом 0 об'єктом t3 -\n");
    int index3 = insert_element(my_array, t3, 0);
    printf("Індекс результату: %d\n", index3);
    print_array(my_array);

    destroy_array(my_array);

    destroy_point(p1);
    destroy_point(p2);
    destroy_point(p3);
    destroy_point(p4);
    destroy_point(p5);
    destroy_point(p6);

    return 0;
}