#include <GL/glut.h> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// Назва та розміри вікна
char title[] = "lab4";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // Період обертання фігури навколо початку координат
float theta_spd = 360.0f / t; // Кут оберту між кадрами
float theta = 0.0f; // Кут оберту як глобальна змінна
FigureList_s* figlist; // Наш список фігур

void display()
{
    drawFigList(figlist);
    glFlush();
}

void timer_dis(int v)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    drawFigList(figlist);
    glFlush();
    glPopMatrix();
    glutTimerFunc(t, timer_dis, 0);

    theta -= theta_spd;
    if (theta <= 0){
        theta = 360;
    }
}

int main(int argc, char* argv[])
{
    Figure_s *figure1, *figure2, *figure3, *figure4;

    // Створимо список фігур
    figlist = createFigList();

    // Створимо овали (центр, радіус X, радіус Y, колір) і додамо їх до списку
    figure1 = createFigure(createPoint(30, 30), 40, 20, createColor(1.0, 0.0, 0.0));
    addFigToFigList(figlist, figure1);

    figure2 = createFigure(createPoint(-50, -30), 20, 30, createColor(1.0, 1.0, 0.0));
    addFigToFigList(figlist, figure2);

    figure3 = createFigure(createPoint(30, -30), 30, 15, createColor(0.5, 0.5, 0.5));
    addFigToFigList(figlist, figure3);

    // Видаляємо овал
    removeFigFromFigListAtIndex(figlist, 1);

    figure4 = createFigure(createPoint(-50, -10), 25, 40, createColor(0.0, 0.0, 1.0));
    insertFigToFigListAtIndex(figlist, 1, figure4);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    
    glutDisplayFunc(display);
    glutTimerFunc(0, timer_dis, 0);
    glutMainLoop();

    return 0;
}
