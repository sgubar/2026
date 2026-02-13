#include "dk_tools.h"
#include "math.h"

int Check(char numbers[]) {
	for (int i = 0; numbers[i] != '\0'; i++) {
		if (numbers[i] > '7') return 0;
	}
	return 1;
}

int GetArraySize(char arr[]) {
	int size = 0;

	for (int i = 0; arr[i] != '\0'; i++) {
		size++;
	}

	return size;
}

int Convert(char arr[]) {
	int result = 0;
	int arrSize = GetArraySize(arr);

	for (int i = 0; arr[i] != '\0'; i++) {
		int number = arr[i] - '0';
		result += number * pow(8, --arrSize);
	}

	return result;
}