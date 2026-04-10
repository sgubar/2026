#include <stdio.h>
#include <stdlib.h>
#include "array.h"

FigureArray* create_array(int capacity) {
    if (capacity <= 0) return NULL;
    FigureArray* arr = (FigureArray*)malloc(sizeof(FigureArray));
    if (arr == NULL) return NULL;
    arr->capacity = capacity;
    arr->count = 0;
    arr->data = (EllipseShape**)malloc(capacity * sizeof(EllipseShape*));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    for (int i = 0; i < capacity; i++) {
        arr->data[i] = NULL;
    }
    return arr;
}

void destroy_array(FigureArray* arr) {
    if (arr != NULL) {
        if (arr->data != NULL) {
            for (int i = 0; i < arr->capacity; i++) {
                if (arr->data[i] != NULL) {
                    destroy_ellipse(arr->data[i]);
                }
            }
            free(arr->data);
        }
        free(arr);
    }
}

int add_to_array(FigureArray* arr, EllipseShape* el) {
    if (arr == NULL || el == NULL) return -1;
    for (int i = 0; i < arr->capacity; i++) {
        if (arr->data[i] == NULL) {
            arr->data[i] = el;
            arr->count++;
            return i;
        }
    }
    return -1;
}

int insert_into_array(FigureArray* arr, EllipseShape* el, int index) {
    if (arr == NULL || el == NULL || index < 0 || index >= arr->capacity) return -1;
    if (arr->data[index] != NULL) {
        destroy_ellipse(arr->data[index]);
        arr->count--;
    }
    arr->data[index] = el;
    arr->count++;
    return index;
}

void print_array(FigureArray* arr) {
    if (arr == NULL) {
        printf("Array is NULL\n");
        return;
    }
    printf("\n--- Array Status ---\n");
    printf("Capacity: %d, Current Count: %d\n", arr->capacity, arr->count);
    for (int i = 0; i < arr->capacity; i++) {
        printf("Index %d:\n", i);
        if (arr->data[i] != NULL) {
            print_ellipse_parameters(arr->data[i]);
        } else {
            printf("  [Empty Slot]\n");
        }
    }
    printf("--------------------\n\n");
}
