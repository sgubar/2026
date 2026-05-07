#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h> // Потрібна для синусів (sin) та косинусів (cos)
#include <stdlib.h>

// Визначаємо число ПІ, якщо воно не вбудоване в систему
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// === ГЛОБАЛЬНІ ЗМІННІ (Для переміщення та масштабування) ===
float pan_x = 0.0f; // Наскільки графік зсунутий вліво/вправо
float pan_y = 0.0f; // Наскільки графік зсунутий вгору/вниз
float zoom = 1.0f;  // Поточний масштаб (1.0 = 100%)

int isDragging = 0; // Прапорець: 1 - мишка затиснута, 0 - відпущена
int lastMouseX = 0; // Останні координати миші для обчислення зсуву
int lastMouseY = 0;

// === НАЛАШТУВАННЯ ДВИЖКА ===
void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Білий фон (згідно з варіантом 8: R=1, G=1, B=1)
    glEnable(GL_LINE_SMOOTH);             // Згладжування ліній (щоб не були "сходинками")
    glEnable(GL_BLEND);                   // Дозвіл на змішування кольорів (необхідно для згладжування)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
}

// === МАЛЮВАННЯ ОСЕЙ КООРДИНАТ ===
void drawAxes() {
    glColor3f(0.0f, 0.6f, 0.0f); // Зелений колір осей (згідно з варіантом 8)
    glLineWidth(1.5f);           // Робимо осі трохи товстішими

    glBegin(GL_LINES); // Починаємо малювати окремі відрізки
    
    // Малюємо самі осі
    glVertex2f(-20.0f, 0.0f); // Горизонтальна вісь X (від -20 до 20)
    glVertex2f( 20.0f, 0.0f);
    glVertex2f(0.0f, -20.0f); // Вертикальна вісь Y (від -20 до 20)
    glVertex2f(0.0f,  20.0f);

    // Малюємо поділки (рисочки) на осях
    for (int i = -20; i <= 20; i++) { // Проходимось від -20 до 20
        if (i == 0) continue; // Нуль пропускаємо (там перетин осей)
        
        // Поділки на осі X (маленькі вертикальні лінії)
        glVertex2f((float)i, -0.1f); 
        glVertex2f((float)i,  0.1f);
        
        // Поділки на осі Y (маленькі горизонтальні лінії)
        glVertex2f(-0.1f, (float)i);
        glVertex2f( 0.1f, (float)i);
    }
    glEnd();
}

// === МАЛЮВАННЯ САМОГО ГРАФІКА (Варіант 8) ===
void drawGraph() {
    glColor3f(0.0f, 0.0f, 0.0f); // Чорний колір графіка (згідно з варіантом)
    glLineWidth(2.0f);           // Товщина лінії графіка - 2 пікселі

    glBegin(GL_LINE_STRIP); // LINE_STRIP з'єднує всі точки однією суцільною лінією
    
    // Цикл по параметру 't' від 0 до 4*Pi (згідно з умовою)
    // Крок 0.01f гарантує, що лінія буде плавною (ми рахуємо дуже багато точок)
    for (float t = 0.0f; t <= 4.0f * M_PI; t += 0.01f) {
        // Формула з варіанту: 
        // Спочатку вираховуємо спільну частину (2 + cos(5t/2))
        float r = 2.0f + cos((5.0f * t) / 2.0f);
        
        // Потім множимо її на cos(t) та sin(t)
        float x = r * cos(t);
        float y = r * sin(t);
        
        glVertex2f(x, y); // Ставимо точку графіка
    }
    glEnd();
}

// === ГОЛОВНА ФУНКЦІЯ ВІДОБРАЖЕННЯ ===
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Очищаємо екран (заливаємо білим фоном)
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Застосовуємо наші глобальні змінні для навігації
    glTranslatef(pan_x, pan_y, 0.0f); // Зсув графіка, якщо ми його потягнули мишкою
    glScalef(zoom, zoom, 1.0f);       // Масштабування, якщо ми покрутили коліщатко

    drawAxes();  // Викликаємо малювання осей
    drawGraph(); // Викликаємо малювання кривої

    glutSwapBuffers();
}

// === ПІДТРИМКА ПРОПОРЦІЙ ПРИ РОЗТЯГУВАННІ ВІКНА ===
void reshape(int width, int height) {
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // Щоб при розтягуванні вікна вшир круги не ставали овалами:
    float aspect = (float)width / (float)height; 
    gluOrtho2D(-5.0 * aspect, 5.0 * aspect, -5.0, 5.0); // 2D ортографічна проекція
}

// === ОБРОБКА КОЛІЩАТКА ТА КЛІКІВ МИШІ ===
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) { // Якщо це ліва кнопка миші
        if (state == GLUT_DOWN) {     // Якщо натиснули
            isDragging = 1;           // Вмикаємо режим "перетягування"
            lastMouseX = x;           // Запам'ятовуємо, де схопили
            lastMouseY = y;
        } else {
            isDragging = 0;           // Якщо відпустили — вимикаємо режим
        }
    }
    // В GLUT коліщатко часто читається як кнопки 3 (вгору) та 4 (вниз)
    if (state == GLUT_UP) {
        if (button == 3) zoom *= 1.1f; // Крутимо вперед -> Збільшуємо масштаб на 10%
        if (button == 4) zoom /= 1.1f; // Крутимо назад -> Зменшуємо
        glutPostRedisplay();
    }
}

// === ПЕРЕТЯГУВАННЯ ГРАФІКА ===
void mouseMove(int x, int y) {
    if (isDragging) { // Працює тільки тоді, коли кнопка натиснута
        // Вираховуємо різницю (дельта) між старим положенням миші та новим.
        // Ділимо на zoom, щоб при сильному наближенні графік не "відлітав" надто швидко.
        float dx = (x - lastMouseX) * 0.015f / zoom;
        float dy = (lastMouseY - y) * 0.015f / zoom; // Y перевернутий, тому віднімаємо навпаки
        
        pan_x += dx; // Додаємо зсув до глобальних координат
        pan_y += dy;
        
        lastMouseX = x; // Оновлюємо збережені координати
        lastMouseY = y;
        
        glutPostRedisplay(); // Перемальовуємо картинку в новій позиції
    }
}

int main(int argc, char* argv[]) {
    // Ініціалізація, як завжди
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE); // MULTISAMPLE робить лінії ще красивішими
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab: Parametric Curve - Variant 8");

    initGL();

    // Прив'язка всіх наших функцій
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);

    glutMainLoop();
    return 0;
}
