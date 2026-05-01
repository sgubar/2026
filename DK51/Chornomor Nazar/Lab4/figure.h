#ifndef figure_h
#define figure_h

#include <stdio.h>
#include "point.h"

typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;

Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);

// Фігура змінена на овал
typedef struct Figure_s{
    Point* center; // Центр овалу
    int rx;        // Радіус по осі X
    int ry;        // Радіус по осі Y
    Color_s* color;
} Figure_s;

Figure_s* createFigure(Point* center, int rx, int ry, Color_s * color);
void deleteFigure(Figure_s* figure);
void drawFigure(Figure_s* figure);

// Елемент списку фігур
typedef struct FigureListElement_s{
    struct FigureListElement_s* prev;
    struct FigureListElement_s* next;
    Figure_s* figure;
} FigureListElement_s;

FigureListElement_s* createListElement(Figure_s* figure);
void deleteListElement(FigureListElement_s* listElement);
void drawListElement(FigureListElement_s* listElement);

// Двозв'язний список фігур
typedef struct FigureList_s{
    FigureListElement_s* head;
    FigureListElement_s* tail;
} FigureList_s;

FigureList_s *createFigList(void);
void deleteFigList(FigureList_s *list);
void drawFigList(FigureList_s *list);
long countOfFigList(FigureList_s *list);
int addFigToFigList(FigureList_s *list, Figure_s* figure); 
void removeLastElementFromFigList(FigureList_s *list);
void removeFirstElementFromFigList(FigureList_s *list);
int insertFigToFigListAtIndex(FigureList_s *list, int index, Figure_s* figure); 
int removeFigFromFigListAtIndex(FigureList_s *list, int index); 

#endif