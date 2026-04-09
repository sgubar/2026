#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Створення трикутника
Triangle* create_from_coordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    Triangle* t = (Triangle*)malloc(sizeof(Triangle));
    if (t) {
        t->p[0] = (Point){x1, y1};
        t->p[1] = (Point){x2, y2};
        t->p[2] = (Point){x3, y3};
    }
    return t;
}

// Знищення трикутника
void destroy_triangle(Triangle* t) {
    if (t) free(t);
}

// Друк трикутника (АНГЛІЙСЬКОЮ)
void print_triangle_info(const Triangle* t) {
    if (!t) return;
    printf("  Vertices: A(%.1f, %.1f), B(%.1f, %.1f), C(%.1f, %.1f)\n", 
           t->p[0].x, t->p[0].y, t->p[1].x, t->p[1].y, t->p[2].x, t->p[2].y);
}

// a) Функція створення масиву
TriangleArray* create_array(int capacity) {
    if (capacity <= 0) return NULL;
    
    TriangleArray* arr = (TriangleArray*)malloc(sizeof(TriangleArray));
    if (!arr) return NULL;
    
    arr->elements = (Triangle**)malloc(capacity * sizeof(Triangle*));
    if (!arr->elements) {
        free(arr);
        return NULL;
    }
    
    arr->capacity = capacity;
    for (int i = 0; i < capacity; i++) {
        arr->elements[i] = NULL;
    }
    
    return arr;
}

// b) Функція знищення масиву
void free_array(TriangleArray* arr) {
    if (!arr) return;
    for (int i = 0; i < arr->capacity; i++) {
        if (arr->elements[i]) {
            destroy_triangle(arr->elements[i]);
        }
    }
    free(arr->elements);
    free(arr);
}

// c) Функція додавання елементу
int add_element(TriangleArray* arr, Triangle* t) {
    if (!arr || !t) return -1;
    for (int i = 0; i < arr->capacity; i++) {
        if (arr->elements[i] == NULL) {
            arr->elements[i] = t;
            return i;
        }
    }
    return -1;
}

// d) Функція вставки за індексом
int insert_element(TriangleArray* arr, Triangle* t, int index) {
    if (!arr || !t || index < 0 || index >= arr->capacity) return -1;
    
    if (arr->elements[index]) {
        destroy_triangle(arr->elements[index]); // Запобігаємо витоку пам'яті
    }
    arr->elements[index] = t;
    return index;
}

// e) Функція друку масиву (АНГЛІЙСЬКОЮ)
void print_array(const TriangleArray* arr) {
    if (!arr) return;
    printf("--- Array Content (capacity: %d) ---\n", arr->capacity);
    for (int i = 0; i < arr->capacity; i++) {
        printf("[%d]: ", i);
        if (arr->elements[i]) {
            print_triangle_info(arr->elements[i]);
        } else {
            printf("Empty\n");
        }
    }
    printf("------------------------------------\n\n");
}
