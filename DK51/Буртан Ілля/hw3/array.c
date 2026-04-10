#include <stdio.h>
#include <stdlib.h>
#include "geometry_.h" // Виправляє warning про implicit declaration
#include "array.h"

SquareArray* create_array(int capacity) {
    if (capacity <= 0) return NULL;
    
    SquareArray* arr = (SquareArray*)malloc(sizeof(SquareArray));
    if (!arr) return NULL;
    
    arr->capacity = capacity;
    arr->count = 0;
    
    arr->elements = (Square**)malloc(capacity * sizeof(Square*));
    
    for (int i = 0; i < capacity; i++) {
        arr->elements[i] = NULL;
    }
    
    return arr;
}

void destroy_array(SquareArray* arr) {
    if (arr != NULL) {
        for (int i = 0; i < arr->capacity; i++) {
            if (arr->elements[i] != NULL) {
                destroy_square(arr->elements[i]);
            }
        }
        free(arr->elements);
        free(arr);
        printf("Memory freed (Array).\n");
    }
}

int add_element(SquareArray* arr, Square* sq) {
    if (arr == NULL || sq == NULL || arr->count >= arr->capacity) {
        return -1; 
    }
    
    for (int i = 0; i < arr->capacity; i++) {
        if (arr->elements[i] == NULL) {
            arr->elements[i] = sq;
            arr->count++;
            return i; 
        }
    }
    
    return -1;
}

int insert_element(SquareArray* arr, Square* sq, int index) {
    if (arr == NULL || sq == NULL || index < 0 || index >= arr->capacity) {
        return -1; 
    }
    
    if (arr->elements[index] == NULL) {
        arr->count++;
    } else {
        // Якщо там вже є квадрат, видаляємо його, щоб уникнути витоку пам'яті
        destroy_square(arr->elements[index]);
    }
    
    arr->elements[index] = sq;
    return index;
}

void print_array(SquareArray* arr) {
    if (arr == NULL) {
        printf("Error: Array does not exist.\n");
        return;
    }
    
    printf("\n=== ARRAY STATUS (Capacity: %d, Filled: %d) ===\n", arr->capacity, arr->count);
    for (int i = 0; i < arr->capacity; i++) {
        printf("Index [%d]:\n", i);
        if (arr->elements[i] != NULL) {
            print_square_info(arr->elements[i]); 
        } else {
            printf("  [Empty]\n");
        }
    }
    printf("==============================================\n");
}