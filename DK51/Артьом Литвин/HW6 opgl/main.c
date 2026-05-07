#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

float zoom = 1.0f;
float offsetX = 0.0f;
float offsetY = 0.0f;

void display()
{
    float x, y, t, px, py;

    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(offsetX, offsetY, 0.0f);
    glScalef(zoom, zoom, 1.0f);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0, -2.0);
    glVertex2f(0.0, 2.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-2.0, 0.0);
    glVertex2f(2.0, 0.0);
    glEnd();

    for (x = -2.0; x <= 2.0; x += 0.2) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(x, -0.05);
        glVertex2f(x, 0.05);
        glEnd();
    }

    for (y = -2.0; y <= 2.0; y += 0.2) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.05, y);
        glVertex2f(0.05, y);
        glEnd();
    }

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);

    for (t = 0.001f; t <= M_PI; t += 0.01f) {
        px = sin(3 * t) * cos(t);
        py = sin(3 * t) * sin(t);
        glVertex2f(px, py);
    }
    glEnd();

    glPopMatrix();
    glFlush();
}

void keyboard(unsigned char key, int mouse_x, int mouse_y) {
    switch (key) {
    case '=':
    case '+': zoom += 0.1f; break;
    case '-': zoom -= 0.1f; break;
    case 'w': offsetY -= 0.1f; break;
    case 's': offsetY += 0.1f; break;
    case 'a': offsetX += 0.1f; break;
    case 'd': offsetX -= 0.1f; break;
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Variant 9 Graph");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

// Які функції OpenGL Ви застосовували для ініціалізації роботи з графікою (початок роботи з OpenGL, налаштування вікна)? Яке їхнє призначення?
// glutInit()
// glutInitWindowSize()
// glutWindowPosition()
// glutCreateWindow()
// glutDisplayFunc()
// glutMainLoop()

// Які функції OpenGL Ви застосовували для створення графічних примітивів? Які параметри примітивів налаштовуються через ці функції?

// glBegin(GL_LINE_STRIP) та glEnd()
// glVertex2f(x, y)
// glColor3f(r, g, b)
// glTranslatef(x, y, z) and glScalef(x, y, z)

// Які ще існують типи графічних примітивів OpenGL?
// крім використанного гл лайн стріп, є GL_POINTS 
// GL_LINES (окремі відрізки) GL_LINE_LOOP (замкнена ламана) GL_TRIANGLES (окремі трикутники)
// GL_TRIANGLE_STRIP (стрічка трикутників), GL_TRIANGLE_FAN (віяло трикутників)
// GL_QUADS (чотирикутники), GL_QUAD_STRIP (стрічка чотирикутників) та GL_POLYGON (опуклі багатокутники)
