#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement *createIntListElement(int value) {
	IntListElement *result = (IntListElement *)malloc(sizeof(IntListElement));

	if (NULL != result) {
		memset(result, 0, sizeof(IntListElement));
		result->value = value;
	}

	return result;
}

void deleteIntListElement(IntListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement *element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

IntList *createIntList(void) {
	IntList *result = (IntList *)malloc(sizeof(IntList));

	if (NULL != result) {
		memset(result, 0, sizeof(IntList));
	}

	return result;
}

void deleteIntList(IntList *list) {
	if (NULL == list) {
		return ;
	}

	IntListElement *element = list->head;

	while(NULL != element) {
		IntListElement *tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}

	free(list);
}

void printfbackward(IntList *list){
    printf("Backward: [");
    IntListElement *current = NULL;
    for (current = list->tail; current != NULL; current = current->prev) {
        printIntListElement(current);
        if (current->prev != NULL) printf(", ");
    }
    printf("]");
    printf("\n");
}

void printfforward(IntList *list){
    printf("Forward: [");
    IntListElement *current = NULL;
    for (current = list->head; current != NULL; current = current->next) {
        printIntListElement(current);
        if (current->next != NULL) printf(", ");
    }
    printf("]");
    printf("\n");
}

void printIntList(IntList *list) {
    if (NULL == list || list->head == NULL) {
        printf("Empty list\n");
        return;
    }
    printfbackward(list);
    printfbackward(list);
    printfforward(list);
    printfforward(list);
}

int addIntValueToIntList(IntList *list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	IntListElement *element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}