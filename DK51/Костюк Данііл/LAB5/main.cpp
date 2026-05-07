#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

char title[] = "Lab 2: Parallelepiped (Variant 8)";
float a_x = 25.0f, a_y = 45.0f;
float zoom_param = -12.0f;
float zoom_delta = 0.5f;

void initGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

void drawParallelepiped() {
    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex3f( 2.5f, 0.0f,  1.5f);
    glVertex3f(-2.5f, 0.0f,  1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f( 2.5f, 0.0f, -1.5f);

    glColor3f(0.0f, 0.8f, 0.4f);
    glVertex3f( 2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f,  1.5f);
    glVertex3f( 2.5f, 3.0f,  1.5f);

    glColor3f(0.9f, 0.2f, 0.2f);
    glVertex3f( 2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 0.0f, 1.5f);
    glVertex3f( 2.5f, 0.0f, 1.5f);

    glColor3f(0.9f, 0.9f, 0.1f);
    glVertex3f( 2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f( 2.5f, 3.0f, -1.5f);

    glColor3f(0.6f, 0.1f, 0.8f);
    glVertex3f(-2.5f, 3.0f,  1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f,  1.5f);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f( 2.5f, 3.0f, -1.5f);
    glVertex3f( 2.5f, 3.0f,  1.5f);
    glVertex3f( 2.5f, 0.0f,  1.5f);
    glVertex3f( 2.5f, 0.0f, -1.5f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, -1.0f, zoom_param);
    glRotatef(a_x, 1, 0, 0);
    glRotatef(a_y, 0, 1, 0);

    drawParallelepiped();

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

void specKeyHandler(int sk, int x, int y) {
    if (sk == GLUT_KEY_UP) {
        zoom_param += zoom_delta;
    }
    else if (sk == GLUT_KEY_DOWN) {
        zoom_param -= zoom_delta;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title);

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specKeyHandler);

    glutMainLoop();
    return 0;
}
