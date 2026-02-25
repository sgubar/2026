#ifndef DK_TOOL_H
#define DK_TOOL_H

int** create_matrix(int rows, int cols);

void free_matrix(int** matrix, int rows);

void fill_matrix(int** matrix, int rows, int cols, char name);

void print_matrix(int** matrix, int rows, int cols, const char* name);

int** subtract_matrices(int** mat1, int** mat2, int rows, int cols);

#endif
