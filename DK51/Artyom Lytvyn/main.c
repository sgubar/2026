#include <stdio.h>
#include "dk_tool.h"
#include <windows.h>

#define MAX_SENTENCE_LEN 1024
#define MAX_WORD_LEN 256

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char sentence[MAX_SENTENCE_LEN];
    char word[MAX_WORD_LEN];

    printf("--- Програма для пошуку кількості occurrence substring ---\n\n");

    
    read_string(sentence, MAX_SENTENCE_LEN, "Введіть речення: ");
    read_string(word, MAX_WORD_LEN, "Введіть послідовність символів для пошуку: ");

    
    int result = count_substring(sentence, word);

 
    printf("\nПослідовність '%s' зустрічається у реченні %d раз(ів).\n", word, result);

    return 0;
}
