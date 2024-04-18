#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../additional/additional.h"
#include "../../s21_matrix.h"
/**
 * @brief Функция вычисляет разность двух матриц (A и B) с одинаковым
 * колличеством рядов и колонок. Значения эллементов матрицы вычтиаются
 * соответственно и записываются в итоговую матрицу
 *
 * @param A матрица -  I уменьшаемое
 * @param B матрица -  II вычитаемое
 * @param result разность -итоговая матрица
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int sign = -1;
  return sum_or_sub_matrix(A, B, result, sign);
}
