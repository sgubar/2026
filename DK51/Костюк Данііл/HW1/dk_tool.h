#ifndef DK_TOOL_H
#define DK_TOOL_H

// Функція для підрахунку слів у рядку
int countWords(const char *str);

// Допоміжна функція для безпечного вводу рядка (уникаємо дублювання fgets)
void getTextInput(char *buffer, int size);

#endif