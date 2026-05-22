#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//#include <stdlib.h>

// Глобальні змінні
char title[] = "Cube";
bool perspective = true;
float a_z = 0;
float zoom_param = -7.0;
float zoom_delta = 0.1;


// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f); // Фон - чорний та прозорий
    glClearDepth(1.f); // Глибина фону - найбільш віддалена
    glEnable(GL_DEPTH_TEST); // Дозвіл тестування глибини
    glDepthFunc(GL_LEQUAL); // Тип функції тестування глибини
    glShadeModel(GL_SMOOTH); // Дозвіл гладкого зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Корекція перспективи
}


// Функція обробки запиту на перемалювання. Виконує малювання сцени.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // Очищення буферу кольору
    GL_DEPTH_BUFFER_BIT); // та буферу глибини
    glMatrixMode(GL_MODELVIEW); // Вибір матриці модель-вигляд
    glLoadIdentity(); // Скидання параметрів матриці шляхом
    // завантаження одиничної матриці

    glTranslatef(0.f, 0.f, zoom_param); // Зміщення об'єкта у глибину екрану
    glRotatef(a_z, 0, 0, 1); // Обертання навколо осі z

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f); 
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f( 0.0f,  1.0f,  0.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 0.0f,  1.0f,  0.0f); 
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f( 0.0f,  1.0f,  0.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f( 0.0f,  1.0f,  0.0f); 
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glEnd(); // Завершення малювання піраміди

    glutSwapBuffers(); // Обмін буферів кадру
}


// Функція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height)
{
    // Обчислення відношення сторін вікна нового розміру
    if (height == 0) // Перевірка для уникнення ділення на 0
    height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Встановлення розміру поля огляду відповідно до нових розмірів вікна
    glViewport(0, 0, width, height);

    // Встановлення параметрів проекційної матриці
    glMatrixMode(GL_PROJECTION); // Вибір матриці проекції
    glLoadIdentity(); // Скидання матриці

    // Використання перспективної проекції з
    // параметрами fovy = 45, aspect, zNear = 0.1 та zFar = 100
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


// Функція обробки події, що виникає при натисканні клавіш клавіатури
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27: // Esc
            exit(0);
            break;
    }
}



// Функція обробки події, що виникає при спрацюванні таймеру
void Timer(int value)
{
    a_z += 1.5f;
    if (a_z > 360.f)  {
        a_z = 0;
    }

    glutPostRedisplay(); // Генерування запиту на перемалювання
    // сцени викликає функцію display()

    glutTimerFunc(30, Timer, 0); // Новий запуск таймера на 30 мс
}


// Головна функція: програма GLUT виконується як консольний додаток
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutKeyboardFunc(keyboard); // Реєстрація обробника подій клавіатури

    glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки
    // подій
return 0;
}
