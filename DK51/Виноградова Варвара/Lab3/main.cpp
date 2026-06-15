#include <iostream>
#include <windows.h> 
#include <limits> // Для очищення буфера вводу 

using namespace std;

// Структура вузла бінарного дерева
struct Node {
    float data; // За варіантом 4: тип елементів float
    Node* left;
    Node* right;
};

// 1. Функція СТВОРЕННЯ нового вузла
Node* createNode(float value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// 2. Функція ВСТАВКИ елементу
Node* insertNode(Node* root, float value) {
    // Якщо дерево порожнє, створюємо корінь
    if (root == nullptr) {
        return createNode(value);
    }
    
    // Інакше йдемо ліворуч або праворуч
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    // Якщо значення вже є, нічого не робимо (дублікати не додаємо)
    return root;
}

// 3. Функція ДРУКУ дерева (Симетричний обхід)
// Порядок: Ліве піддерево -> Корінь -> Праве піддерево
// Завдяки цьому обходу елементи виводяться за зростанням!
void printSymmetric(Node* root) {
    if (root != nullptr) {
        printSymmetric(root->left);
        cout << root->data << "  ";
        printSymmetric(root->right);
    }
}

// 4. Функція ПОШУКУ елементу
Node* searchNode(Node* root, float value) {
    if (root == nullptr || root->data == value) {
        return root; // Знайшли або дійшли до кінця (не знайшли)
    }
    // Шукаємо в лівому або правому піддереві
    if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Допоміжна функція для знаходження мінімального елемента (потрібна для видалення)
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// 5. Функція ВИДАЛЕННЯ елементу
Node* deleteNode(Node* root, float value) {
    if (root == nullptr) return root;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Знайшли вузол для видалення
        // Випадок 1 та 2: вузол має 1 нащадка або взагалі не має
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Випадок 3: вузол має 2 нащадків
        // Шукаємо найменший елемент у правому піддереві
        Node* temp = findMin(root->right);
        root->data = temp->data; // Копіюємо значення
        root->right = deleteNode(root->right, temp->data); // Видаляємо той найменший елемент
    }
    return root;
}

// 6. Функція ВИДАЛЕННЯ всього дерева (очищення пам'яті)
void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Допоміжна функція для безпечного вводу чисел (захист від дурня)
float safeInput(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Помилка! Введіть коректне число." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Node* root = nullptr;
    int choice;

    while (true) {
        cout << "\nМеню роботи з бінарним деревом" << endl;
        cout << "1. Додати елемент (float)" << endl;
        cout << "2. Видалити елемент" << endl;
        cout << "3. Знайти елемент" << endl;
        cout << "4. Вивести дерево (симетричний обхід)" << endl;
        cout << "5. Видалити все дерево" << endl;
        cout << "0. Вийти" << endl;
        
        // Захищений ввід для вибору меню
        while (true) {
            cout << "Оберіть дію (0-5): ";
            if (cin >> choice && choice >= 0 && choice <= 5) break;
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (choice == 0) {
            deleteTree(root);
            cout << "Програму завершено. Пам'ять очищена." << endl;
            break;
        }

        float val;
        Node* found;

        switch (choice) {
            case 1:
                val = safeInput("Введіть значення (float) для додавання: ");
                root = insertNode(root, val);
                cout << "Елемент додано." << endl;
                break;
            case 2:
                if (root == nullptr) {
                    cout << "Дерево порожнє!" << endl;
                    break;
                }
                val = safeInput("Введіть значення для видалення: ");
                root = deleteNode(root, val);
                cout << "Спроба видалення завершена." << endl;
                break;
            case 3:
                val = safeInput("Введіть значення для пошуку: ");
                found = searchNode(root, val);
                if (found != nullptr) {
                    cout << "Елемент " << val << " знайдено в дереві!" << endl;
                } else {
                    cout << "Елемент " << val << " НЕ знайдено." << endl;
                }
                break;
            case 4:
                if (root == nullptr) {
                    cout << "Дерево порожнє!" << endl;
                } else {
                    cout << "Елементи дерева (симетричний обхід): ";
                    printSymmetric(root);
                    cout << endl;
                }
                break;
            case 5:
                deleteTree(root);
                root = nullptr; // Обов'язково обнуляємо корінь після видалення
                cout << "Дерево повністю видалено." << endl;
                break;
        }
    }
    return 0;
}