#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция для вычисления определителя матрицы
 *
 * @param A указатель на матрицу, в которой нужно вычислить определитель
 * @param result указатель на адрес, по которому будет записан детерминант
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 */
int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return ERR_INVALID_MATRIX;
  }

  if (A->rows != A->columns) {
    return ERR_CALCULATION;
  }

  *result = determinant_recursive(A, A->rows);

  return OK;
}