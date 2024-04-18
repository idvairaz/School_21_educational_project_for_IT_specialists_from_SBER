#include <stdio.h>
#include <stdlib.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief функция удаляет матрицу (прямоугольную таблицу чисел, расположенных в
 * m строках (rows) и n столбцах(columns)). Удаление происходит в обратном
 * созданию матрицы порядке
 * @param A удаляемая матрицa
 * @return (void)не возвращает значение
 */
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}