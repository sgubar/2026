#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float pan_x = 0.0f;
float pan_y = 0.0f;
float zoom = 1.0f;

int isDragging = 0;
int lastMouseX = 0;
int lastMouseY = 0;

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void drawAxes() {
    glColor3f(0.0f, 0.6f, 0.0f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f( 20.0f, 0.0f);
    glVertex2f(0.0f, -20.0f);
    glVertex2f(0.0f,  20.0f);
    for (int i = -20; i <= 20; i++) {
        if (i == 0) continue;
        glVertex2f((float)i, -0.1f);
        glVertex2f((float)i,  0.1f);
        glVertex2f(-0.1f, (float)i);
        glVertex2f( 0.1f, (float)i);
    }
    glEnd();
}

void drawGraph() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0f; t <= 4.0f * M_PI; t += 0.01f) {
        float r = 2.0f + cos((5.0f * t) / 2.0f);
        float x = r * cos(t);
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(pan_x, pan_y, 0.0f);
    glScalef(zoom, zoom, 1.0f);
    drawAxes();
    drawGraph();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = (float)width / (float)height;
    gluOrtho2D(-5.0 * aspect, 5.0 * aspect, -5.0, 5.0);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isDragging = 1;
            lastMouseX = x;
            lastMouseY = y;
        } else {
            isDragging = 0;
        }
    }
    if (state == GLUT_UP) {
        if (button == 3) zoom *= 1.1f;
        if (button == 4) zoom /= 1.1f;
        glutPostRedisplay();
    }
}

void mouseMove(int x, int y) {
    if (isDragging) {
        float dx = (x - lastMouseX) * 0.015f / zoom;
        float dy = (lastMouseY - y) * 0.015f / zoom;
        pan_x += dx;
        pan_y += dy;
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab: Parametric Curve - Variant 8");
    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    glutMainLoop();
    return 0;
}
