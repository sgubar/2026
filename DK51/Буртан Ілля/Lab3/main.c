#include <stdio.h>
#include "tree.h" 

int main() {
    // Створюємо дерево
    Tree* myTree = createTree();

    // Додаємо елементи
    insert(myTree, 10 );
    insert(myTree, 5 );
    insert(myTree, 15 );
    insert(myTree, 3 );
    insert(myTree, 7 );

    // Друкуємо
    printTreePostOrder(myTree);

    // Шукаємо елемент
    Node* found = search(myTree, 7);
    if (found != NULL) {
        printf("Found item: %d\n", found->data);
    } else {
        printf("Item not found\n");
    }

    // Видаляємо елемент (перевір, як дерево зміниться!)
    printf("delete 5...\n");
    removeElement(myTree, 5);
    printTreePostOrder(myTree);

    // Знищуємо дерево перед завершенням програми
    deleteTree(myTree);

    return 0;
}
