#ifndef DK_TOOL_H
#define DK_TOOL_H

int get_int_input(const char* message);
int** create_matrix(int rows, int cols);
void free_matrix(int** matrix, int rows);
void fill_matrix(int** matrix, int rows, int cols);
void print_matrix(int** matrix, int rows, int cols);
void mult_matrix_by_num(int** matrix, int rows, int cols, int num);

#endif