#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

char title[] = "Rotating Rectangles Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; 
float theta_spd = 2.0f; 
float theta = 0.0f; 
FigureList_s* figlist;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    drawFigList(figlist);
    glFlush();
    glPopMatrix();
}

void timer_dis(int v) {
    theta += theta_spd;
    if (theta >= 360.0f) {
        theta -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(t, timer_dis, 0);
}

int main(int argc, char* argv[]) {
    Point* points1[4];
    Point* points2[4];
    Point* points3[4];
    Point* points4[4];
    Figure_s *figure1, *figure2, *figure3, *figure4;

    figlist = createFigList();


    points1[0] = createPoint(10, 10);
    points1[1] = createPoint(50, 10);
    points1[2] = createPoint(50, 40);
    points1[3] = createPoint(10, 40);
    figure1 = createFigure(points1, createColor(1.0, 0.0, 0.0));
    addFigToFigList(figlist, figure1);

    points2[0] = createPoint(-60, -10);
    points2[1] = createPoint(-20, -10);
    points2[2] = createPoint(-20, -40);
    points2[3] = createPoint(-60, -40);
    figure2 = createFigure(points2, createColor(1.0, 1.0, 0.0));
    addFigToFigList(figlist, figure2);

  
    points3[0] = createPoint(-30, 20);
    points3[1] = createPoint(20, 20);
    points3[2] = createPoint(20, 50);
    points3[3] = createPoint(-30, 50);
    figure3 = createFigure(points3, createColor(0.5, 0.5, 0.5));
    addFigToFigList(figlist, figure3);

   
    removeFigFromFigListAtIndex(figlist, 1);

    
    points4[0] = createPoint(-70, -20);
    points4[1] = createPoint(-30, -20);
    points4[2] = createPoint(-30, -60);
    points4[3] = createPoint(-70, -60);
    figure4 = createFigure(points4, createColor(0.0, 0.0, 1.0));
    insertFigToFigListAtIndex(figlist, 1, figure4);

    glutInit(&argc, argv);
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    
    glutDisplayFunc(display);
    glutTimerFunc(0, timer_dis, 0);
    glutMainLoop();

    // Звільнення пам'яті перед виходом
    deleteFigList(figlist);

    return 0;
}
