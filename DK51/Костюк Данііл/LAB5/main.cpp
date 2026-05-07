#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

// === ГЛОБАЛЬНІ ЗМІННІ ===
char title[] = "Lab 2: Parallelepiped (Variant 8)";
float a_x = 25.0f, a_y = 45.0f; // Початкові кути нахилу фігури, щоб ми бачили її об'ємною, а не плоскою
float zoom_param = -12.0f;      // Відстань камери від фігури (мінус означає, що відсуваємо фігуру вглиб екрану)
float zoom_delta = 0.5f;        // На скільки буде наближатись/віддалятись фігура при одному натисканні стрілки

bool moveScene = false;         // Прапорець: чи затиснута зараз ліва кнопка миші?
int mouse_x, mouse_y;           // Тут будемо зберігати останні координати мишки

// === НАЛАШТУВАННЯ ДВИЖКА (Ініціалізація) ===
void initGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Ставимо темно-сірий колір фону (R, G, B, Прозорість)
    glClearDepth(1.0f);                      // Вказуємо максимальну глибину
    glEnable(GL_DEPTH_TEST);                 // ВМИКАЄМО 3D! Без цього грані будуть малюватися одна поверх іншої неправильно
    glDepthFunc(GL_LEQUAL);                  // Правило: малювати піксель, тільки якщо він ближче до камери
}

// === МАЛЮЄМО ФІГУРУ ===
void drawParallelepiped() {
    glBegin(GL_QUADS); // Кажемо OpenGL: "Зараз я буду давати координати точок. Кожні 4 точки — це один квадрат/прямокутник"

    // 1. НИЖНЯ ГРАНЬ (Основа)
    // Завдання вимагає, щоб центр основи був у точці (0,0,0). Тому висота (y) тут всюди дорівнює 0.0f
    glColor3f(0.0f, 0.4f, 0.8f);   // Вибираємо синій колір
    glVertex3f( 2.5f, 0.0f,  1.5f); // Точка 1: x=2.5, y=0, z=1.5
    glVertex3f(-2.5f, 0.0f,  1.5f); // Точка 2: x=-2.5, y=0, z=1.5
    glVertex3f(-2.5f, 0.0f, -1.5f); // Точка 3: x=-2.5, y=0, z=-1.5
    glVertex3f( 2.5f, 0.0f, -1.5f); // Точка 4: x=2.5, y=0, z=-1.5

    // 2. ВЕРХНЯ ГРАНЬ
    // Піднімаємо її на висоту 3.0 (y = 3.0f)
    glColor3f(0.0f, 0.8f, 0.4f);   // Зелений колір
    glVertex3f( 2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f,  1.5f);
    glVertex3f( 2.5f, 3.0f,  1.5f);

    // 3. ПЕРЕДНЯ ГРАНЬ (z = 1.5)
    glColor3f(0.9f, 0.2f, 0.2f);   // Червоний колір
    glVertex3f( 2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 3.0f, 1.5f);
    glVertex3f(-2.5f, 0.0f, 1.5f);
    glVertex3f( 2.5f, 0.0f, 1.5f);

    // 4. ЗАДНЯ ГРАНЬ (z = -1.5)
    glColor3f(0.9f, 0.9f, 0.1f);   // Жовтий колір
    glVertex3f( 2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f( 2.5f, 3.0f, -1.5f);

    // 5. ЛІВА ГРАНЬ (x = -2.5)
    glColor3f(0.6f, 0.1f, 0.8f);   // Фіолетовий колір
    glVertex3f(-2.5f, 3.0f,  1.5f);
    glVertex3f(-2.5f, 3.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f, -1.5f);
    glVertex3f(-2.5f, 0.0f,  1.5f);

    // 6. ПРАВА ГРАНЬ (x = 2.5)
    glColor3f(1.0f, 0.5f, 0.0f);   // Помаранчевий колір
    glVertex3f( 2.5f, 3.0f, -1.5f);
    glVertex3f( 2.5f, 3.0f,  1.5f);
    glVertex3f( 2.5f, 0.0f,  1.5f);
    glVertex3f( 2.5f, 0.0f, -1.5f);

    glEnd(); // Закінчили малювати грані
}

// === ГОЛОВНА ФУНКЦІЯ ВІДОБРАЖЕННЯ ===
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищаємо старий кадр
    glMatrixMode(GL_MODELVIEW); // Вмикаємо режим роботи з моделями
    glLoadIdentity();           // Скидаємо всі минулі зсуви та повороти до нуля

    // ТРАНСФОРМАЦІЇ (працюють знизу вгору, тому спочатку зсув, потім поворот)
    glTranslatef(0.0f, -1.0f, zoom_param); // Зсуваємо сцену: трохи вниз (-1.0 по Y) і вглиб екрану на величину zoom_param
    glRotatef(a_x, 1, 0, 0);               // Крутимо сцену навколо осі X на кут a_x
    glRotatef(a_y, 0, 1, 0);               // Крутимо сцену навколо осі Y на кут a_y

    drawParallelepiped(); // Викликаємо нашу функцію малювання, яку написали вище

    glutSwapBuffers(); // Відправляємо намальований кадр на екран (бо у нас подвійний буфер)
}

// === ЯКЩО ЗМІНИЛИ РОЗМІР ВІКНА ===
void reshape(int width, int height) {
    if (height == 0) height = 1; // Захист від ділення на нуль
    GLfloat aspect = (GLfloat)width / (GLfloat)height; 
    glViewport(0, 0, width, height); 
    glMatrixMode(GL_PROJECTION); // Перемикаємось на об'єктив камери
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f); // Налаштовуємо перспективу (кут огляду 45 градусів)
}

// === СПЕЦІАЛЬНІ КЛАВІШІ (Стрілки для зуму) ===
// Це реалізація твого 8-го варіанту (Наближення/віддалення на стрілки)
void specKeyHandler(int sk, int x, int y) {
    if (sk == GLUT_KEY_UP) {       // Якщо натиснули стрілку ВГОРУ
        zoom_param += zoom_delta;  // Збільшуємо параметр (камера під'їжджає ближче)
    }
    else if (sk == GLUT_KEY_DOWN) { // Якщо натиснули стрілку ВНИЗ
        zoom_param -= zoom_delta;   // Зменшуємо параметр (камера від'їжджає далі)
    }
    glutPostRedisplay(); // Кажемо екрану перемалюватися з новими параметрами
}

// === РОБОТА З МИШЕЮ (Затискання) ===
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { // Якщо затиснули ліву кнопку
        moveScene = true; // Ставимо прапорець "Можна крутити"
        mouse_x = x;      // Запам'ятовуємо, де зараз була мишка
        mouse_y = y;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) { // Якщо відпустили кнопку
        moveScene = false; // Знімаємо прапорець
    }
}

// === РОБОТА З МИШЕЮ (Рух) ===
void mouseMove(int x, int y) {
    if (moveScene) { // Якщо мишка затиснута
        int dx = mouse_x - x; // Рахуємо, на скільки пікселів мишка зсунулась по горизонталі
        int dy = mouse_y - y; // І по вертикалі
        a_x -= 0.25f * dy;    // Змінюємо кут повороту відповідно до руху
        a_y -= 0.25f * dx;
        mouse_x = x;          // Оновлюємо старі координати на поточні
        mouse_y = y;
        glutPostRedisplay();  // Перемальовуємо екран
    }
}

int main(int argc, char* argv[]) {
    // Тут все стандартно: створюємо вікно, прив'язуємо функції і запускаємо нескінченний цикл
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title);

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specKeyHandler); // Прив'язуємо наші стрілки
    glutMouseFunc(mouseClick);       // Прив'язуємо кліки миші
    glutMotionFunc(mouseMove);       // Прив'язуємо рух миші

    glutMainLoop(); // Запуск програми
    return 0;
}
