#include <stdio.h>
#include <string.h>
#include "dk_tool.h"

int count_substring(const char* text, const char* word) {
    if (!text || !word || *word == '\0') {
        return 0;
    }

    int count = 0;
    int word_len = strlen(word);
    const char* p = text;

    while ((p = strstr(p, word)) != NULL) {
        count++;
        p += word_len;
    }

    return count;
}

void input_string(const char* prompt, char* buffer, int max_size) {
    printf("%s", prompt);
    if (fgets(buffer, max_size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}
