#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция для вычисления матрицы алгебраических дополнений
 * @param A указатель на матрицу над которой нужно произвести вычисления
 * @param result указатель на итоговую матрицу
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  double det;
  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  if (A->columns != A->rows) {
    return_value = ERR_CALCULATION;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {};
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        get_minor(A, i, j, &minor);
        s21_determinant(&minor, &det);
        result->matrix[i][j] = det;
        s21_remove_matrix(&minor);
      }
    }
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if ((i + j) % 2 != 0) {
          result->matrix[i][j] *= -1;
        }
      }
    }
  }
  return return_value;
}
