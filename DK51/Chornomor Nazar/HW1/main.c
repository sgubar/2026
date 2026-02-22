#include <stdio.h>
#include "dk_tool.h"
// #include "tests.h"

const char USAGE_INFO[] = "\nUsage:\n HW1.exe [num]\n\n num - binary number (1 byte)\n\n";

int main(int argc, const char *argv[] ) {
    
    if (argc !=2) {printf(USAGE_INFO); return -1;}
    if (!check(argv)) {printf(USAGE_INFO); return -1;}
    // if (!tests()) {printf("tests failed!"); return -1;}

    printf("Result: %d",convert(argv[1]));

    return 0;
}
