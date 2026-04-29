#include <stdio.h>
#include "LinkedList.h"

int main() {
    Node* list = createList();

    append(&list, 10);
    append(&list, 20);
    append(&list, 30);

    printf("List: ");
    printList(list);

    insertAtIndex(&list, 1, 15);
    insertAtIndex(&list, 0, 5);

    printf("After inserts: ");
    printList(list);

    removeByValue(&list, 20);

    printf("After removal: ");
    printList(list);

    printf("Size: %d\n", getSize(list));

    deleteList(&list);

    printf("After deletion: ");
    printList(list);

    return 0;
}
