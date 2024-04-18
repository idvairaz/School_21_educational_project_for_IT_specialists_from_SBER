#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция создает матрицу (прямоугольную таблицу чисел, расположенных в
 * m строках (rows) и n столбцах(columns)) Проверяемая точность дробной части
 * значений матриц - максимум 6 знаков после запятой.
 * @param A матрица сравниваемая с В матрицей
 * @param B матрица сравниваемая с A матрицей
 * @return Возвращаемое значение int - код ошибки:
 *         0 - FAILURE
 *         1 - SUCCESS
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;

  if (A->rows != B->rows || A->columns != B->columns ||
      is_bad_matrix(B->rows, B->columns) == ERR_INVALID_MATRIX) {
    return_value = FAILURE;
    return return_value;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns && return_value != FAILURE; j++) {
      char infoA[20];
      const char formatA[] = "%.7f";
      sprintf(infoA, formatA, A->matrix[i][j]);

      char infoB[20];
      const char formatB[] = "%.7f";
      sprintf(infoB, formatB, B->matrix[i][j]);

      int eq = strcmp(infoA, infoB);

      if (eq != 0) {
        return_value = FAILURE;
      }
    }
  }
  return return_value;
}
