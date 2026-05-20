#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "word.h"

void getValidFilename(char* buffer, int maxLength) {
    bool fileReady = false;

    while (!fileReady) {
        printf("Введіть назву текстового файлу для зчитування (макс. %d символів, наприклад: test.txt):\n> ", maxLength - 1);

        // зчитування рядка
        if (fgets(buffer, maxLength, stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            if (strlen(buffer) == 0) {
                printf("Помилка. Назва файлу не може бути порожньою. Спробуйте ще раз\n\n");
                continue;
            }

            FILE* testFile = fopen(buffer, "r");
            if (testFile != NULL) {
                fclose(testFile);
                fileReady = true;
            } else {
                printf("Помилка. Файл '%s' не знайдено у папці\n", buffer);
                printf("Бажаєте автоматично створити цей файл із тестовим текстом? (y - так / n - ні, ввести іншу назву):\n> ");

                char choice[10];
                if (fgets(choice, sizeof(choice), stdin) != NULL) {
                    if (choice[0] == 'y' || choice[0] == 'Y' || choice[0] == 'н' || choice[0] == 'Н') {
                        FILE* newFile = fopen(buffer, "w");
                        if (newFile != NULL) {
                            fprintf(newFile, "danya_golishovec\n");
                            fprintf(newFile, "Hello World\n");
                            fprintf(newFile, "12345 67890\n");
                            fclose(newFile);
                            printf("Файл '%s' успішно створено!", buffer);
                            fileReady = true;
                        } else {
                            printf("Критична помилка. Не вдалося створити файл. Немає прав доступу\n\n");
                        }
                    } else {
                        printf("Спробуємо ще раз\n\n");
                    }
                }
            }
        } else {
            printf("Помилка. Некоректне введення\n\n");
            clearerr(stdin);
        }
    }
}

int main() {
    char filename[256];
    system("chcp 65001 > nul");

    getValidFilename(filename, sizeof(filename));

    printf("\nРезультат обробки файлу '%s'\n", filename);

    processFile(filename);

    printf("Роботу завершено\n");
    
    return 0;
}