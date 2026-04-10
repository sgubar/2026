#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("Step 1: Create array for 3 elements\n");
    TriangleArray* my_array = create_array(3);
    
    Triangle* t1 = create_from_coordinates(0,0, 4,0, 0,3);
    Triangle* t2 = create_from_coordinates(1,1, 5,1, 3,5);
    Triangle* t3 = create_from_coordinates(2,2, 6,2, 4,6);

    printf("Step 2: Add elements\n");
    add_element(my_array, t1);
    add_element(my_array, t2);
    print_array(my_array);

    printf("Step 3: Insert third element at index 2\n");
    insert_element(my_array, t3, 2);
    print_array(my_array);

    printf("Step 4: Replace element at index 1\n");
    Triangle* t_new = create_from_coordinates(-1,-1, -5,-1, -3,-5);
    insert_element(my_array, t_new, 1);
    print_array(my_array);

    printf("Step 5: Free memory\n");
    free_array(my_array);
    printf("Done.\n");

    return 0;
}
