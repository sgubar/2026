// ============================================================================
// Завдання 1: Двовимірна графіка засобами OpenGL з залученням списків
// Варіант: 8
// Користувацький опис:
// Обрані фігури: Трикутник та Квадрат (згідно з умовою про заміну кола).
// Операції над списком фігур:
// - Клавіша '1': Створення та вставка трикутника в список.
// - Клавіша '2': Створення та вставка квадрата в список.
// - Клавіша '3': Видалення останнього доданого елемента зі списку.
// Фігури обертаються навколо початку координат.
// ============================================================================

#include <GL/glut.h>
#include <stdlib.h>

typedef struct Node {
    int type; // 0 - трикутник, 1 - квадрат
    float x, y;
    float r, g, b;
    struct Node* next;
} Node;

Node* head = NULL;
float angle = 0.0f;

void insertShape(int type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->x = ((float)rand() / RAND_MAX) * 1.5f - 0.75f;
    newNode->y = ((float)rand() / RAND_MAX) * 1.5f - 0.75f;
    newNode->r = (float)rand() / RAND_MAX;
    newNode->g = (float)rand() / RAND_MAX;
    newNode->b = (float)rand() / RAND_MAX;
    newNode->next = head;
    head = newNode;
}

void deleteShape() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
}

void drawSquare() {
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Node* curr = head;
    while (curr != NULL) {
        glPushMatrix();
        glRotatef(angle, 0.0f, 0.0f, 1.0f); // Обертання навколо початку координат
        glTranslatef(curr->x, curr->y, 0.0f); // Позиція фігури
        glColor3f(curr->r, curr->g, curr->b);

        if (curr->type == 0) drawTriangle();
        else drawSquare();

        glPopMatrix();
        curr = curr->next;
    }

    glutSwapBuffers();
}

void timer(int value) {
    angle += 2.0f;
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '1') insertShape(0);
    if (key == '2') insertShape(1);
    if (key == '3') deleteShape();
}

int main(int argc, char** argv) {
    insertShape(0);
    insertShape(1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL List 2D");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
