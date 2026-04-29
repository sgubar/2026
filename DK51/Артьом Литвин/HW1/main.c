#include <stdio.h>
#include <windows.h>
#include "dk_tool.h"

int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[256];
    char word[64];

    printf("--- Підрахунок входжень підрядка ---\n\n");

    input_string("Введіть текст: ", text, sizeof(text));
    input_string("Введіть послідовність для пошуку: ", word, sizeof(word));

    if (text[0] == '\0' || word[0] == '\0') {
        printf("Помилка: Ви нічого не ввели.\n");
        return 1;
    }

    int result = count_substring(text, word);
    printf("Кількість входжень: %d\n", result);

    return 0;
}
