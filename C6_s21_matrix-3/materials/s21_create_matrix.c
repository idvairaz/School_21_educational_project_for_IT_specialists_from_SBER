#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "./../../s21_matrix.h"
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
 *         4 - ERR_OUT_OFF_MEMORY (ошибка выделения памяти)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = OK;
  if (is_bad_matrix(rows, columns)) {
    return ERR_INVALID_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(rows, sizeof(double *));

  //  result->matrix = NULL;
  if (result->matrix == NULL) return_value = ERR_OUT_OFF_MEMORY;

  for (int i = 0; i < rows && result->matrix; i++) {
    // result->matrix[i]= NULL;
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) free(result->matrix[j]);

      free(result->matrix);
      return_value = ERR_OUT_OFF_MEMORY;
      break;
    }
  }
  return return_value;
}

// int s21_create_matrix(int rows, int columns, matrix_t *result) {
//   if (rows <= 0 || columns <= 0 || result == NULL) {
//     return ERR_INVALID_MATRIX;
//   }

//   int res = OK;
//   result->matrix = (double **)calloc(
//       rows * sizeof(double *) + rows * columns * sizeof(double),
//       rows * columns);
//   if (result->matrix != NULL) {
//     //  if ((result->matrix = NULL)) {
//     result->matrix[0] = (double *)(result->matrix + rows);
//     for (int i = 1; i < rows; i++) {
//       result->matrix[i] = result->matrix[0] + i * columns;
//     }
//   } else {
//     res = ERR_INVALID_MATRIX;
//     free(result->matrix);
//     result->matrix = NULL;
//   }

//   return res;
// }
