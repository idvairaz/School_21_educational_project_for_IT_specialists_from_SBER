#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "./../../s21_matrix.h"
/**
 * @brief Функция для вычисления определителя матрицы (незаконченная функция)
 *
 * @param tmp указатель на матрицу, в которой нужно вычислить определитель
 * @param result указатель на адрес, по которому будет записан детерминант
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 */
int s21_determinant(matrix_t *A, double *result) {
  int return_value = OK;
  matrix_t _tmp;
  matrix_t *tmp = &_tmp;
  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  if (A->rows != A->columns) {
    return_value = ERR_CALCULATION;
    return return_value;
  }
  if (A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    int i = 0;
    int sign = 1;
    while (A->matrix[i][0] == 0) i++;
    if (i == A->rows)
      *result = 0;
    else {
      s21_create_matrix(A->rows, A->columns, tmp);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          tmp->matrix[i][j] = A->matrix[i][j];
        }
      }
      if (i != 0) {
        sign = -1;
        for (int j = 0; j < tmp->columns; j++) {
          double temp = tmp->matrix[0][j];
          tmp->matrix[0][j] = tmp->matrix[i][j];
          tmp->matrix[i][j] = temp;
        }
      }
      *result = 1.0;
      double ratio;
      for (int i = 0; i < tmp->rows; i++) {
        if (tmp->matrix[i][i] == 0.0) *result = 0.0;
        for (int j = i + 1; j < tmp->columns; j++) {
          ratio = tmp->matrix[j][i] / tmp->matrix[i][i];
          for (int k = 0; k < tmp->columns; k++) {
            tmp->matrix[j][k] = tmp->matrix[j][k] - ratio * tmp->matrix[i][k];
          }
        }
      }
      for (int i = 0; i < tmp->rows; i++) {
        *result = *result * tmp->matrix[i][i];
      }
      *result *= sign;
      s21_remove_matrix(tmp);
    }
  }
  return return_value;
}

