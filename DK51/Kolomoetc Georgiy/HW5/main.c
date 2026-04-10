#include <stdio.h>
#include "tree.h"

int main() {
    BinaryTree* my_tree = create_tree();

    insert_element(my_tree, 50.55);
    insert_element(my_tree, 30.22);
    insert_element(my_tree, 70.88);
    insert_element(my_tree, 20.11);
    insert_element(my_tree, 40.44);
    insert_element(my_tree, 60.66);
    insert_element(my_tree, 80.99);

    print_tree(my_tree);

    double search_val = 40.44;
    Node* found = search_element(my_tree, search_val);
    if (found != NULL) {
        printf("Found element: %.2f\n\n", found->data);
    } else {
        printf("Element %.2f not found\n\n", search_val);
    }

    printf("Deleting element 30.22...\n");
    delete_element(my_tree, 30.22);
    print_tree(my_tree);

    delete_tree(my_tree);

    return 0;
}
