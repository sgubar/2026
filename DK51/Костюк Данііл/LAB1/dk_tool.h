#ifndef DK_TOOL_H
#define DK_TOOL_H

double power(double base, int exp);
double calculate_sum(int A);
double calculate_Q(int A, double B, double C);

int get_valid_int(const char* prompt, int min_val);
double get_valid_double(const char* prompt);

#endif // DK_TOOL_H
