#include "dk_tool.h"
#include <stdio.h>

int getArraySize(const char array[]) {
    int count = 0;
    while (array[count] != '\0')
        count++;
    return count;
}

int power(int num, int powernum) {
    int result = 1;
    for (int i = 1; i <= powernum;i++) {
        result *= num;
    }
    return result;
}

int check(const char nums[]) {
    int arraySize = getArraySize(nums);

    if (arraySize > 8) return 0;
    
    for (int i = 0; i < arraySize; i++) {
        if (!(nums[i] == '0' || nums[i] == '1')) return 0;
    }
    
    return 1;

}

int convert(const char nums[]) {
    if (!check(nums)) return -1;

    int result = 0;
    int arraySize = getArraySize(nums);

    for (int i = 0; i < arraySize; i++) {
        int bit = nums[i] - '0';
        result += bit * power(2, arraySize - 1 - i);
    }
    return result;
}