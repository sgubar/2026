#ifndef ARRAY_H
#define ARRAY_H

#include "triangle.h"

typedef struct {
    Triangle** elements;
    int capacity;
    int current_size;
} TriangleArray;

TriangleArray* create_array(int capacity);

void destroy_array(TriangleArray* arr);
int add_element(TriangleArray* arr, Triangle* elem);
int insert_element(TriangleArray* arr, Triangle* elem, int index);
void print_array(const TriangleArray* arr);

#endif