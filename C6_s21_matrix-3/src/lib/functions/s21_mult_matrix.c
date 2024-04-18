#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция для вычисления произведения матриц A и B .
 * Результат записывается в итоговую матрицу.
 * (Произведением матрицы A = m × k на матрицу B = k × n называется
 * матрица C = m × n = A × B размера m × n, элементы которой определяются
 * равенством C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) × B(k,j).
 * )
 * @param A матрица -  I множитель
 * @param B матрица -  II множитель
 * @param result произведение -итоговая матрица
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result

 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = OK;

  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX ||
      is_bad_matrix(B->rows, B->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;

  } else if (A->columns != B->rows) {
    return_value = ERR_CALCULATION;

  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] =
              result->matrix[i][j] + A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return return_value;
}
