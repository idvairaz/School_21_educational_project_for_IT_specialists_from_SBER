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
  if (A != NULL && B != NULL && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows && return_value == SUCCESS; i++) {
      for (int j = 0; j < A->columns && return_value == SUCCESS; j++) {
        if (((A->matrix[i][j] > B->matrix[i][j])
                 ? A->matrix[i][j] - B->matrix[i][j]
                 : B->matrix[i][j] - A->matrix[i][j]) >= 1e-7) {
          return_value = FAILURE;
        }
      }
    }
  } else {
    return_value = FAILURE;
  }
  return return_value;
}
