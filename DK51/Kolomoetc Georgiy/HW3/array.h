#ifndef ARRAY_H
#define ARRAY_H

#include "geometry.h"

typedef struct {
    EllipseShape** data;
    int capacity;
    int count;
} FigureArray;

FigureArray* create_array(int capacity);
void destroy_array(FigureArray* arr);
int add_to_array(FigureArray* arr, EllipseShape* el);
int insert_into_array(FigureArray* arr, EllipseShape* el, int index);
void print_array(FigureArray* arr);

#endif
