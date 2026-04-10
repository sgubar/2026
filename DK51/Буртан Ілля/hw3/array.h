#include "geometry_.h"

// Структура масиву для зберігання вказівників на Квадрати
typedef struct tagSquareArray {
    Square** elements; // Динамічний масив вказівників на фігури
    int capacity;      // Місткість масиву
    int count;         // Поточна кількість елементів
} SquareArray;

// Функції для роботи з масивом
SquareArray* create_array(int capacity);
void destroy_array(SquareArray* arr);
int add_element(SquareArray* arr, Square* sq);
int insert_element(SquareArray* arr, Square* sq, int index);
void print_array(SquareArray* arr);

