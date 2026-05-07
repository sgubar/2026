#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

/* * ЛАБОРАТОРНА РОБОТА №2
 * Студент: Костюк Данііл (ДК-51)
 * Варіант №8: Паралелепіпед
 * Взаємодія: Наближення/віддалення (Клавіші ↑, ↓)
 */

 // Глобальні змінні
char title[] = "Lab 2: Parallelepiped (Variant 8)";
float a_x = 25.0f, a_y = 45.0f; // Початкові кути огляду для об'єму
float zoom_param = -12.0f;      // Початкова дистанція (віддалення)
float zoom_delta = 0.2f;        // Швидкість зміни відстані

bool moveScene = false;         // Стан затиснутої миші
int mouse_x, mouse_y;

// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f); // Майже чорний фон
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);                 // Тест глибини для 3D
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);                 // Плавне зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Функція малювання паралелепіпеда згідно з варіантом
void drawParallelepiped()
{
    glBegin(GL_QUADS);

    // 1. НИЖНЯ ГРАНЬ (y = 0.0) - Центр основи у (0,0,0)
    glColor3f(0.0f, 0.4f, 0.8f); // Блакитна
    glVertex3f(2.5f, 0.0f, 1.5f);
    glVertex3f(-2.5f, 0.0f, 1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(2.5f, 0.0f, -1.5f);

    // 2. ВЕРХНЯ ГРАНЬ (y = 3.0)
    glColor3f(0.0f, 0.8f, 0.4f); // Смарагдова
    glVertex3f(2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, 1.5f);
    glVertex3f(2.5f, 3.0f, 1.5f);

    // 3. ПЕРЕДНЯ ГРАНЬ (z = 1.5)
    glColor3f(0.9f, 0.2f, 0.2f); // Червона
    glVertex3f(2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 0.0f, 1.5f);
    glVertex3f(2.5f, 0.0f, 1.5f);

    // 4. ЗАДНЯ ГРАНЬ (z = -1.5)
    glColor3f(0.9f, 0.9f, 0.1f); // Жовта
    glVertex3f(2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(2.5f, 3.0f, -1.5f);

    // 5. ЛІВА ГРАНЬ (x = -2.5)
    glColor3f(0.6f, 0.1f, 0.8f); // Фіолетова
    glVertex3f(-2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, 1.5f);

    // 6. ПРАВА ГРАНЬ (x = 2.5)
    glColor3f(1.0f, 0.5f, 0.0f); // Помаранчева
    glVertex3f(2.5f, 3.0f, -1.5f);
    glVertex3f(2.5f, 3.0f, 1.5f);
    glVertex3f(2.5f, 0.0f, 1.5f);
    glVertex3f(2.5f, 0.0f, -1.5f);

    glEnd();
}

// Рендеринг сцени
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Застосування трансформацій
    glTranslatef(0.0f, -1.0f, zoom_param); // Зміщення камери
    glRotatef(a_x, 1, 0, 0);               // Обертання по X
    glRotatef(a_y, 0, 1, 0);               // Обертання по Y

    drawParallelepiped();

    glutSwapBuffers();
}

// Оновлення проекції при зміні розміру вікна
void reshape(int width, int height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Обробка спеціальних клавіш (Наближення/віддалення)
void specKeyHandler(int sk, int x, int y)
{
    if (sk == GLUT_KEY_UP) {
        zoom_param += zoom_delta; // Наближення
    }
    else if (sk == GLUT_KEY_DOWN) {
        zoom_param -= zoom_delta; // Віддалення
    }
    glutPostRedisplay();
}

// Стандартні клавіші
void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) exit(0); // Вихід на Esc
}

// Робота з мишею для зручного огляду
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        moveScene = true;
        mouse_x = x;
        mouse_y = y;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        moveScene = false;
    }
}

void mouseMove(int x, int y)
{
    if (moveScene) {
        int dx = mouse_x - x;
        int dy = mouse_y - y;
        a_x -= 0.25f * dy;
        a_y -= 0.25f * dx;
        mouse_x = x;
        mouse_y = y;
        glutPostRedisplay();
    }
}

// Таймер для плавного перемальовування
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title);

    initGL();

    // Реєстрація всіх обробників
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specKeyHandler);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    glutTimerFunc(0, Timer, 0);

    glutMainLoop();
    return 0;
}
