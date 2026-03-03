#include <stdio.h>
#include "dk_tool.h"

int countWords(const char *str) {
    int count = 0;
    int inWord = 0; 

    while (*str != '\0') {
        
        if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r') {
            inWord = 0;
        } 
        else if (inWord == 0) {
        
            inWord = 1;
            count++;
        }
        str++;
    }
    return count;
}

void getTextInput(char *buffer, int size) {
    printf("Enter your text: ");
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
    }
}