#include <stdio.h>
#include "dk_tool.h"

int main() {
    printf("1. Creating binary tree...\n");
    CharTree* tree = create_tree();

    printf("\n2. Inserting elements: 'M', 'B', 'Q', 'A', 'C', 'Z', 'P'\n");
    insert_element(tree, 'M'); // Корінь
    insert_element(tree, 'B'); // Йде вліво від M
    insert_element(tree, 'Q'); // Йде вправо від M
    insert_element(tree, 'A'); // Вліво від B
    insert_element(tree, 'C'); // Вправо від B
    insert_element(tree, 'Z'); // Вправо від Q
    insert_element(tree, 'P'); // Вліво від Q
    
    print_tree(tree);

    printf("\n3. Searching for elements...\n");
    char target1 = 'C';
    CharNode* found = search_element(tree, target1);
    if (found) printf("Element '%c' is FOUND in the tree.\n", found->value);
    else printf("Element '%c' is NOT FOUND.\n", target1);

    char target2 = 'X';
    found = search_element(tree, target2);
    if (found) printf("Element '%c' is FOUND in the tree.\n", found->value);
    else printf("Element '%c' is NOT FOUND.\n", target2);

    printf("\n4. Deleting element 'Q' (Node with two children)...\n");
    delete_element(tree, 'Q');
    print_tree(tree);
    
    printf("\n5. Deleting element 'A' (Leaf node)...\n");
    delete_element(tree, 'A');
    print_tree(tree);

    printf("\n6. Deleting the entire tree...\n");
    delete_tree(tree);
    printf("Memory freed successfully. Done.\n");

    return 0;
}
