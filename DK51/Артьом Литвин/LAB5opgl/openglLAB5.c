#include <GL/glut.h>
#include <stdlib.h>

char title[] = "Cube - Variant 9";
float a_x = 0;
float zoom_param = -7.0;

void initGL() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, -1.0f, zoom_param);
    glRotatef(a_x, 1, 0, 0);

    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, -1.0f);
    glVertex3f(-1.0f, 2.0f, -1.0f);
    glVertex3f(-1.0f, 2.0f, 1.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);
    glVertex3f(-1.0f, 2.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.0f, 2.0f, -1.0f);
    glVertex3f(1.0f, 2.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 2.0f, 1.0f);
    glVertex3f(-1.0f, 2.0f, -1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 2.0f, -1.0f);
    glVertex3f(1.0f, 2.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);

    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    case 'w':
    case 'W':
        a_x -= 5.0f;
        break;
    case 's':
    case 'S':
        a_x += 5.0f;
        break;
    }
}

void Timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, Timer, 0);

    initGL();
    glutMainLoop();

    return 0;
}

//  Які функції для роботи безпосередньо з OpenGL ви імплементували? Коротко опишіть їхнє призначення.
// glClearColor
// glClear
// glEnable(GL_DEPTH_TEST)
// glMatrixMode
// glLoadIdentity
// glTranslatef
// glRotatef
// glBegin / glEnd
// glColor3f
// glVertex3f
// glViewport

// Які функції реєстрації зворотних викликів ви використовували? Коротко опишіть
// glutDisplayFunc
// glutReshapeFunc
// glutKeyboardFunc
// glutTimerFunc


// Які існують інші функції обробки подій (зміна розміру вікна, введення інформації від користувача)? Коротко опишіть їхнє призначення.
// glutMouseFunc
// glutMotionFunc
// glutPassiveMotionFunc
// glutSpecialFunc 
