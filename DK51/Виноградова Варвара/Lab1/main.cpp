#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits> //  для очищення буфера вводу 

using namespace std;

// функція для піднесення до степеня
double myPow(double base, int exp) {
    if (exp == 0) return 1.0;
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
// Функція для обчислення конкретної формули Q
double calculateQ(int A, double B, double C) {
    // 1. Обчислюємо першу частину формули (дріб)
    double fraction = (A + B + C) / (100.0 - B - C);

    // 2. Обчислюємо суму
    double sum = 0.0;
    for (int D = 0; D <= A; D++) {
        sum += myPow(2.0, D + A); 
    }

    // 3. Повертаємо загальний результат
    return fraction + sum;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int A;
    double B, C;

    cout << "--- Програма для обчислення формули Q ---" << endl;

    // Введення A із захистом від помилок
    // A має бути >= 0, оскільки це верхня межа для циклу (суми)
    while (true) {
        cout << "Введіть ціле число A (A >= 0): ";
        if (cin >> A && A >= 0) {
            break; // Якщо ввели правильно - виходимо з циклу
        } else {
            cout << "Помилка! A має бути цілим невід'ємним числом." << endl;
            cin.clear(); // Скидаємо стан помилки вводу
            cin.ignore(10000, '\n'); // Очищуємо буфер від некоректних символів (букв тощо)
        }
    }

    // Введення B із захистом
    while (true) {
        cout << "Введіть дійсне число B: ";
        if (cin >> B) {
            break;
        } else {
            cout << "Помилка! Введено не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Введення C із перевіркою знаменника
    while (true) {
        cout << "Введіть дійсне число C (так, щоб 100 - B - C не дорівнювало 0): ";
        if (cin >> C) {
            // Перевірка на недопустимі значення (ділення на нуль)
            if ((100.0 - B - C) == 0) {
                cout << "Помилка! При таких значеннях знаменник дорівнює нулю. Змініть число C." << endl;
            } else {
                break; // Все добре
            }
        } else {
            cout << "Помилка! Введено не число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Виклик модуля обчислення
    double result = calculateQ(A, B, C);

    // Виведення результату
    cout << "\nРезультат обчислення Q = " << result << endl;

    return 0;
}