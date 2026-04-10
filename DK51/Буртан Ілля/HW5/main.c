#include "tree.h"

int main() {
    // 1. Створення дерева
    Tree* myTree = createTree();

    // 2. Вставка елементів (тип double)
    insert(myTree, 50.5);
    insert(myTree, 30.2);
    insert(myTree, 70.8);
    insert(myTree, 20.1);
    insert(myTree, 40.9);
    insert(myTree, 60.3);
    insert(myTree, 80.0);

    printf("--- Our tree ---\n");
    printTree(myTree->root, 0);

    // 3. Пошук елемента
    double valToSearch = 40.9;
    Node* foundNode = search(myTree, valToSearch);
    if (foundNode != NULL) {
        printf("\nelement %.2lf is found!\n", foundNode->data);
    } else {
        printf("\nelement %.2lf is not found\n", valToSearch);
    }

    // 4. Видалення елемента
    printf("\n--- tree after deleting 30.2 ---\n");
    deleteElement(myTree, 30.2);
    printTree(myTree->root, 0);

    // 5. Видалення всього дерева (звільнення пам'яті)
    deleteTree(myTree);
    printf("\ntree successfully deleted.\n");

    return 0;
}