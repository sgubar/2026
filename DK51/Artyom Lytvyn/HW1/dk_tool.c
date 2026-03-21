#include <stdio.h>
#include <string.h>
#include "dk_tool.h"


int count_substring(const char* sentence, const char* word) {
    int count = 0;
    int word_len = strlen(word);

    
    if (word_len == 0) {
        return 0;
    }

    const char* tmp = sentence;

    
    
    while ((tmp = strstr(tmp, word)) != NULL) {
        count++;
        tmp += word_len; 
        
    }

    return count;
}


void read_string(char* buffer, int max_length, const char* prompt) {
    printf("%s", prompt);

    
    if (fgets(buffer, max_length, stdin) != NULL) {
        size_t len = strlen(buffer);

        
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        else {
            
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}
