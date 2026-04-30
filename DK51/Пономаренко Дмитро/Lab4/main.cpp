#include <GL/freeglut.h>
#include <list>
#include <cstdlib>
#include <iostream>
#include "Shape.h"

using namespace std;

list<Shape> figuresList;
float angle = 0.0f;

void addFigure() {
    Shape s;

    s.x = (rand() % 200 - 100) / 100.0f;
    s.y = (rand() % 200 - 100) / 100.0f;

    s.r = (rand() % 100) / 100.0f;
    s.g = (rand() % 100) / 100.0f;
    s.b = (rand() % 100) / 100.0f;

    figuresList.push_back(s);
}

void removeFigure() {
    if (!figuresList.empty()) {
        figuresList.pop_back();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //glRotatef(80.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    for (auto const& s : figuresList) {
        glPushMatrix();

        glTranslatef(s.x, s.y, 0.0f);
        glColor3f(s.r, s.g, s.b);

        glBegin(GL_QUADS);
        glVertex2f(-0.1f, 0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(-0.1f, -0.1f);
        glEnd();

        glPopMatrix();
    }

    glutSwapBuffers();
}

void timer(int value) {
    angle += 1.5f;
    if (angle > 360.0f) angle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': addFigure(); break;
    case '2': removeFigure(); break;
    case 27: exit(0); break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Main");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    for (int i = 0; i < 100; i++) {
        addFigure();
    }

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

//#1
//Контрольні запитання:
//display() - головна функція відмальовування. Очищає буфери, застосовує трансформації та малює всі фігури зі списку на екрані.
//timer() — функція оновлення стану для анімації. Збільшує кут обертання та генерує запит на перемальовування кадру.
//keyboard() — обробляє натискання клавіш користувачем, викликаючи функції додавання або видалення елементів зі списку.

//#2
//Призначення списку — динамічне зберігання параметрів фігур
//Поєднання функціоналу списку з OpenGL відбувається у функції display()

//#3
//Анімація реалізована за допомогою обробки подій від таймера через функцію glutTimerFunc()

//#4
//Для обертання використовувалася функція glRotatef(angle, 0.0f, 0.0f, 1.0f);

//#5
//glMatrixMode(), glLoadIdentity(), glPushMatrix(), glPopMatrix(), glTranslatef(), glRotatef(), glScalef()

//#6
//glutTimerFunc() — реєструє функцію, яка буде викликана один раз через вказану кількість мілісекунд
//glutIdleFunc() — реєструє функцію, яка викликається постійно у фоновому режимі
