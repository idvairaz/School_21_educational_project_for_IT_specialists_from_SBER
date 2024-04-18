#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief функция создает матрицу (прямоугольную таблицу чисел, расположенных в
 * m строках (rows) и n столбцах(columns))
 * @param rows кол-во рядов матрицы
 * @param columns кол-во колонок матрицы
 * @param result созданная матрица записывается в result
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *             матрица, для которой нельзя провести вычисления и т.д.))
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = OK;
  if (rows == 0) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  if (columns == 0) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  if (result == NULL) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (result->matrix == NULL) return_value = ERR_OUT_OFF_MEMORY;

  int my_break = 0;

  for (int i = 0; i < rows && result->matrix && !my_break; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) free(result->matrix[j]);

      free(result->matrix);
      return_value = ERR_OUT_OFF_MEMORY;
      my_break = 1;
    }
  }
  return return_value;
}
