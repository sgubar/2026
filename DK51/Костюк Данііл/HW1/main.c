#include <stdio.h>
#include "dk_tool.h"

int main() {
    char sentence[256];
    
    getTextInput(sentence, sizeof(sentence));
    
    int result = countWords(sentence);
    
    printf("---------------------------\n");
    printf("Result: %d word(s) found.\n", result);
    printf("---------------------------\n");

    return 0;
}
