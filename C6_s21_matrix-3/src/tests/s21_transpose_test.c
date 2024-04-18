#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Все матрицы валидны и совпадают с нужными размерами. OK
 */
START_TEST(test_s21_transpose_1) {
  int rowsA = 3, columnsA = 2;
  matrix_t A = {}, result_matrix = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;

  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;

  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  int result = s21_transpose(&A, &result_matrix);
  int expected = OK;

  double expected_el_0_0 = 1.0;
  double expected_el_0_1 = 2.0;
  double expected_el_0_2 = 3.0;

  double expected_el_1_0 = 4.0;
  double expected_el_1_1 = 5.0;
  double expected_el_1_2 = 6.0;

  double result_el_0_0 = result_matrix.matrix[0][0];
  double result_el_0_1 = result_matrix.matrix[0][1];
  double result_el_0_2 = result_matrix.matrix[0][2];

  double result_el_1_0 = result_matrix.matrix[1][0];
  double result_el_1_1 = result_matrix.matrix[1][1];
  double result_el_1_2 = result_matrix.matrix[1][2];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq(result_el_0_0, expected_el_0_0);
  ck_assert_double_eq(result_el_0_1, expected_el_0_1);
  ck_assert_double_eq(result_el_0_2, expected_el_0_2);

  ck_assert_double_eq(result_el_1_0, expected_el_1_0);
  ck_assert_double_eq(result_el_1_1, expected_el_1_1);
  ck_assert_double_eq(result_el_1_2, expected_el_1_2);

  // printf("A====================\n");
  // print_matrix(A);
  // printf("Res====================\n");
  // print_matrix(result_matrix);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result_matrix);
}
END_TEST

/**
 матрицы не валидны, ERR_INVALID_MATRIX
 */
START_TEST(test_s21_transpose_2) {
  int rowsA = 0, columnsA = 2;
  matrix_t A = {}, result_matrix = {};

  s21_create_matrix(rowsA, columnsA, &A);

  int result = s21_transpose(&A, &result_matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *suite = suite_create("transpose");
  TCase *tcase_core = tcase_create("transpose");
  tcase_add_test(tcase_core, test_s21_transpose_1);
  tcase_add_test(tcase_core, test_s21_transpose_2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}