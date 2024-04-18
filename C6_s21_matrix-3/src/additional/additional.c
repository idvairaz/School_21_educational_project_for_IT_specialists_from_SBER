#include "additional.h"

#include <stdio.h>

#include "../s21_matrix.h"
/**
 * @brief функция печатает матрицу в консоль
 * @param matrix матрица, которую надо распечатать
 * @return (void)не возвращает значение
 */
void print_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      printf("%.8f ", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}

/**
 * @brief функция проверяет валидность матрицы
 * @param matrix матрица, которую надо проверить
 * @return 0 - OK
 *         1 - ERR_INVALID_MAYRIX  (Ошибка, некорректная матрица)
 */
int is_bad_matrix(int rows, int columns) {
  int return_value = OK;

  if (rows <= 0 || columns <= 0) {
    return_value = ERR_INVALID_MATRIX;
  }
  return return_value;
}

/**
 * @brief Функция вычисляет сумму или разность
 * (в зависимости от знака который устанавливается в переменную sign),
 * двух матриц (A и B) с одинаковым колличеством рядов и колонок. Значения
 * эллементов матрицы складываются соответственно и записываются в итоговую
 * матрицу
 *
 * @param A матрица -  I слагаемое
 * @param B матрица -  II слагаемое
 * @param result Сумма - итоговая матрица
 * @param sign знак действия (1 - сумма
 *                            -1 - разность)
 * @return Возвращаемое значение int - код ошибки:
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 * После использования функции удалить матрицу result
 */
int sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int sign) {
  int return_value = OK;

  if (is_bad_matrix(A->rows, A->columns) == ERR_INVALID_MATRIX ||
      is_bad_matrix(B->rows, B->columns) == ERR_INVALID_MATRIX) {
    return_value = ERR_INVALID_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    return_value = ERR_CALCULATION;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j] * sign;
      }
    }
  }
  return return_value;
}

/**
 * @brief Функция вычисляет минор вамтрицы
 *
 * @param A - указатель на матрицу в котрой будет производиться вычисление
 минора
 * @param minor - указатель на минор матрицы
 * @param row - индекс строки элемента для которого вычисляется минор
 * @param col - индекс столбца элемента для которого вычисляется минор

 * @return Возвращаемое значение int - код ошибки://пока void
 *         0 - OK
 *         1 - ERR_INVALID_MATRIX  (Ошибка, некорректная матрица)
 *         2 - ERR_CALCULATION (Ошибка вычисления (несовпадающие размеры матриц;
 *         матрица, для которой нельзя провести вычисления и т.д.))
 */
void get_minor(matrix_t *A, int row, int col, matrix_t *minor) {
  int i_new = 0, j_new = 0;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->rows; j++) {
      if (i != row && j != col) {
        minor->matrix[i_new][j_new++] = A->matrix[i][j];

        if (j_new == A->rows - 1) {
          j_new = 0;
          i_new++;
        }
      }
    }
  }
}

/**
 * @brief Рекурсивная функция для вычисления детерминанта матрицы.
 * @param A - указатель на матрицу для которой требуется вычислить детерминант
 * @param minor - указатель на минор матрицы
 * @param size: Размер матрицы (то, что она квадратная, проверили ранее)
 * @return double: Значение детерминанта матрицы
 **/
double determinant_recursive(matrix_t *A, int size) {
  double det = 0;
  if (size == 1) {
    return A->matrix[0][0];
  }
  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  int sign = 1;
  for (int i = 0; i < size; i++) {
    int minor_i = 0;
    for (int row = 1; row < size; row++) {
      int minor_j = 0;
      for (int col = 0; col < size; col++) {
        if (col == i) {
          continue;
        }
        minor.matrix[minor_i][minor_j] = A->matrix[row][col];
        minor_j++;
      }
      minor_i++;
    }
    det += sign * A->matrix[0][i] * determinant_recursive(&minor, size - 1);
    sign = -sign;
  }

  s21_remove_matrix(&minor);

  return det;
}
/**
 * @brief Функция для перестановки местами строк матрицы
 *
 * @param A - указатель на матрицу в котрой будет производиться перестановка
 * @param row1 - индекс I строки для перестановки
 * @param row2 - индекс II строки для перестановки
 * @return не возвращает значение
 */
void swap_rows(matrix_t *A, int row1, int row2) {
  double *temp = A->matrix[row1];
  A->matrix[row1] = A->matrix[row2];
  A->matrix[row2] = temp;
}