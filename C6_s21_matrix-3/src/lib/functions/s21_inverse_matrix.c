#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция для вычисления обратной матрицы
 * @param A указатель на матрицу над которой нужно произвести вычисления
 * @param result указатель на итоговую матрицу
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  double det;

  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  s21_determinant(A, &det);
  if (fabs(det) < 1e-6) {
    return_value = ERR_CALCULATION;
  } else {
    if (A->rows == 1) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
      matrix_t complements_matrix = {}, trans_matrix = {};
      s21_calc_complements(A, &complements_matrix);
      s21_transpose(&complements_matrix, &trans_matrix);
      s21_mult_number(&trans_matrix, 1.0 / det, result);
      s21_remove_matrix(&complements_matrix);
      s21_remove_matrix(&trans_matrix);
    }
  }

  return return_value;
}
