#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция последовательно умножает эллементы матриы на число n. Значения
 * умноженных эллементов соответственно записываются в итоговую матрицу
 *
 * @param A матрица -  I уменьшаемое
 * @param B матрица -  II вычитаемое
 * @param result разность -итоговая матрица
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result

 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = OK;

  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;

  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return return_value;
}
