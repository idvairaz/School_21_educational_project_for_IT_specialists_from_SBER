#ifndef _ADDITTIONAL_H
#define _ADDITTIONAL_H

#include "../s21_matrix.h"

void print_matrix(matrix_t *matrix);
int is_bad_matrix(int rows, int columns);
int sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int mode);
void get_minor(matrix_t *A, int row, int col, matrix_t *minor);
double determinant_recursive(matrix_t *A, int size);
#endif /*_ADDITTIONAL_H*/