#include "array.h"
#include <stdio.h>
#include <stdlib.h>

// створення масиву
TriangleArray* create_array(int capacity) {
    if (capacity <= 0) return NULL;

    TriangleArray* arr = (TriangleArray*)malloc(sizeof(TriangleArray));
    if (arr == NULL) return NULL;

    arr->elements = (Triangle**)calloc(capacity, sizeof(Triangle*));
    if (arr->elements == NULL) {
        free(arr);
        return NULL;
    }

    arr->capacity = capacity;
    arr->current_size = 0;
    return arr;
}

// знищення масиву
void destroy_array(TriangleArray* arr) {
    if (arr != NULL) {
        if (arr->elements != NULL) {
            for (int i = 0; i < arr->capacity; i++) {
                if (arr->elements[i] != NULL) {
                    destroy_triangle(arr->elements[i]);
                }
            }
            free(arr->elements);
        }
        free(arr);
    }
}

// додавання елементу (в кінець)
int add_element(TriangleArray* arr, Triangle* elem) {
    if (arr == NULL || elem == NULL || arr->current_size >= arr->capacity) {
        return -1; // Масив повний або передані некоректні дані
    }

    // знаходимо першу вільну позицію
    for (int i = 0; i < arr->capacity; i++) {
        if (arr->elements[i] == NULL) {
            arr->elements[i] = elem;
            arr->current_size++;
            return i;
        }
    }
    return -1;
}

// вставка елементу за індексом
int insert_element(TriangleArray* arr, Triangle* elem, int index) {
    if (arr == NULL || elem == NULL || index < 0 || index >= arr->capacity) {
        return -1;
    }

    if (arr->elements[index] != NULL) {
        destroy_triangle(arr->elements[index]);
    } else {
        arr->current_size++;
    }

    arr->elements[index] = elem;
    return index;
}

// друк масиву
void print_array(const TriangleArray* arr) {
    if (arr == NULL) {
        printf("Масив це NULL\n");
        return;
    }

    printf("Масив (Місткість: %d, розмір: %d):\n", arr->capacity, arr->current_size);
    for (int i = 0; i < arr->capacity; i++) {
        printf("[%d]: ", i);
        if (arr->elements[i] != NULL) {
            print_triangle(arr->elements[i]);
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}