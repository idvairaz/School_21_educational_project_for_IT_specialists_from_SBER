#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция транспонирует матрицу (заменяет строки матрицы ее
 * столбцами с сохранением их номеров) и результат записывает в
 * итоговую матрицу
 * @param A трансонируемая матрица
 * @param result итоговая матрица
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = OK;

  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;
    return return_value;
  }
  s21_create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return return_value;
}
