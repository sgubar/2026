#ifndef DK_TOOL_H
#define DK_TOOL_H

#define MAX 10

int vvid_chisla(const char *text, int min, int max);
void zapolny_matr(int n, int m[MAX][MAX], char simvol);
void vivod_matr(int n, int m[MAX][MAX], const char *nazva);
void mnozh_matr(int n, int A[MAX][MAX], int B[MAX][MAX], int Rez[MAX][MAX]);

#endif
