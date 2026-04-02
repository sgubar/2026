#include "tree.h"

Tree* createTree(){
    Tree* myTree = (Tree*)malloc(sizeof(Tree));
    myTree->root = NULL;
    return myTree;
}

Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;   //Три головні складові цього вузла
    newNode->right = NULL;

    return newNode; //Повертаємо головний вузол
}
// Функція зворотного обходу (Post-order)
void postOrder(struct Node* node){
    if (node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d", node->data);
}
// Функція-помічник, яка шукає місце і вставляє вузол
Node* insertNode(Node* current, int value){
    
    // Якщо ми дійшли до порожнього місця - створюємо тут новий вузол
    if (current == NULL){
        return createNode(value);
    }
    
    // Якщо число менше поточного - ідемо вліво
    if (value < current->data){
        current->left = insertNode(current->left, value);
    }

    // ... ідемо враво
    else{
        current->right = insertNode(current->right, value);
    }

    // Повертаємо незмінний потоочний вузол
    return current;
}

void insert(Tree* tree, int value){

    //якщо дерево взагалі не існує, нічого не робимо
    if (tree == NULL) return;

    // Запускаємо процес пошуку місця, починаючи з кореня
    tree->root = insertNode(tree->root,value);
}

// наша рекурсивна функція друку (працює з вузлами)
void postOrderNode(Node* node){
    if (node == NULL) return;
    postOrderNode(node->left);
    postOrderNode(node->right);
    printf("%d", node->data);
}

// Голвона функція друку для виклику з main
void printTreePostOrder(Tree* tree){
    if(tree == NULL) return;
    printf("reverse bypass:\n");
    postOrderNode(tree->root);
    printf("\n");
}

// Рукурсивний помічник для пошуку
Node* searchNode(Node* current, int value){
    // Якщо дійшли до кінця ( не знайшли) АБО знайшли потрібне число - повертаємо цей вузол
    if (current == NULL || current->data == value){
        return current;
    }

    // Якщо шукане число МЕНШЕ - шукаємо вліво
    if (value < current->data){
        return searchNode(current->left, value);
    }

    // В іншому випадку (бІЛЬШЕ) - шукаємо вправо
    return searchNode(current->right, value);
}

// головна функція пошуку
Node* search(Tree* tree, int value){
    if (tree == NULL) return NULL;
    return searchNode(tree->root, value);
}

// Рекурсивний помічник для звільнення пам'яті вузлів
void freeNodes(Node* node){
    if (node == NULL) return;

    freeNodes(node->left); 
    freeNodes(node->right);
    free(node);
}

// Головна функція видалення всього дерева
void deleteTree(Tree* tree){
    if(tree == NULL) return;

    freeNodes(tree->root);
    free(tree);
}

// ФУНКЦІЇ ДЛЯ ВИДАЛЕННЯ ОДНОГО ЕЛЕМЕНТА

// 1. Маленька функція-помічник для пошуку найменшого вузла в гілці

Node* findMinNode(Node* current) {
    // Найменший елемент завжди знаходиться в самому низу ліворуч,
    // тому ми просто йдемо вліво, поки це можливо.
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// 2. Рекурсивна функція видалення, яка шукає і знищує потрібний вузол
Node* removeNode(Node* current, int value) {
    // БАЗОВИЙ ВИПАДОК: Якщо дійшли до порожнечі, значить такого числа в дереві немає
    if (current == NULL) {
        return current;
    }

    // КРОК 1: ШУКАЄМО ВУЗОЛ
    if (value < current->data) {
        // Якщо число менше, йдемо шукати в ліву гілку
        current->left = removeNode(current->left, value);
    } 
    else if (value > current->data) {
        // Якщо число більше, йдемо шукати в праву гілку
        current->right = removeNode(current->right, value);
    } 
    // КРОК 2: ЗНАЙШЛИ! Число дорівнює current->data. Починаємо видалення.
    else {
        // Вузол має одного нащадка або взагалі не має нащадків (листок)
        if (current->left == NULL) {
            // Якщо немає лівого нащадка, зберігаємо правого (навіть якщо він NULL)
            Node* temp = current->right;
            free(current); // Звільняємо пам'ять видаленого вузла
            return temp;   // Повертаємо правого нащадка (підтягуємо її вгору)
        } 
        else if (current->right == NULL) {
            // Аналогічно: якщо немає правого нащадка, підтягуємо лівого
            Node* temp = current->left;
            free(current); 
            return temp;   
        }

        // КЕЙС 3: У вузла є ДВОЄ нащадків
        // 1. Знаходимо "наступника" - найменший елемент у ПРАВІЙ підгілці
        Node* temp = findMinNode(current->right);

        // 2. Копіюємо дані наступника в наш поточний вузол 
        // (тепер цей вузол має значення наступника, але нащадки залишились ті самі)
        current->data = temp->data;

        // 3. Видаляємо самого наступника з правої гілки 
        // (бо його значення ми вже перенесли сюди)
        current->right = removeNode(current->right, temp->data);
    }
    
    // Повертаємо поточний вузол, щоб зв'язки в дереві не розірвалися
    return current;
}

// 3. Головна функція для виклику з main.c (працює з "коробкою" Tree)
void removeElement(Tree* tree, int value) {
    if (tree == NULL) return; // Захист від порожнього дерева
    
    // Запускаємо процес видалення, починаючи з кореня,
    // і оновлюємо корінь (на випадок, якщо ми видалили саме його)
    tree->root = removeNode(tree->root, value);
}