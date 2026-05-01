#pragma once
#include <stdio.h>

struct tagPoint {
    int x;
    int y;
};
typedef struct tagPoint Point;


Point *createPoint(int x, int y);
Point *copyPoint(Point *a);
void deletePoint(Point *a);
void printPoint(Point *a);
void fillPoint(Point *a);
void setPointValues(Point* point, int x, int y);
