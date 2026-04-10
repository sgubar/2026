#include "tree.h"

// Створення порожнього дерева
Tree* createTree() {
    Tree* myTree = (Tree*)malloc(sizeof(Tree));
    if (myTree != NULL) {
        myTree->root = NULL;
    }
    return myTree;
}

// Створення нового вузла
Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Допоміжна рекурсивна функція для вставки
Node* insertRecursive(Node* root, double value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    // Якщо значення менше, йдемо вліво, якщо більше - вправо
    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }
    
    return root;
}

// Вставка елемента
void insert(Tree* tree, double value) {
    if (tree != NULL) {
        tree->root = insertRecursive(tree->root, value);
    }
}

// Допоміжна рекурсивна функція для пошуку
Node* searchRecursive(Node* root, double value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
    if (value < root->data) {
        return searchRecursive(root->left, value);
    }
    return searchRecursive(root->right, value);
}

// Пошук елемента
Node* search(Tree* tree, double value) {
    if (tree == NULL) return NULL;
    return searchRecursive(tree->root, value);
}

// Пошук мінімального елемента (потрібно для видалення)
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Допоміжна рекурсивна функція для видалення вузла
Node* deleteRecursive(Node* root, double value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = deleteRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = deleteRecursive(root->right, value);
    } else {
        // Вузол знайдено. Варіант 1: Немає нащадків або один нащадок
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Варіант 2: Вузол має двох нащадків
        // Знаходимо найменший елемент у правому піддереві
        Node* temp = findMin(root->right);
        root->data = temp->data; // Копіюємо значення
        // Видаляємо той найменший елемент
        root->right = deleteRecursive(root->right, temp->data);
    }
    return root;
}

// Видалення елемента
void deleteElement(Tree* tree, double value) {
    if (tree != NULL) {
        tree->root = deleteRecursive(tree->root, value);
    }
}

// Рекурсивне звільнення пам'яті всіх вузлів
void freeTreeRecursive(Node* root) {
    if (root != NULL) {
        freeTreeRecursive(root->left);
        freeTreeRecursive(root->right);
        free(root);
    }
}

// Видалення всього дерева
void deleteTree(Tree* tree) {
    if (tree != NULL) {
        freeTreeRecursive(tree->root);
        free(tree);
    }
}

// Вивід дерева (повернуто на 90 градусів для наочності)
void printTree(Node* root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("       ");
        }
        printf("%.2lf\n", root->data);
        printTree(root->left, level + 1);
    }
}
