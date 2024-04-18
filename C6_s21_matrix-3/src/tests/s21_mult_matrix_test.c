#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Все матрицы валидны и совпадают с нужными размерами. OK
 */
START_TEST(test_s21_mult_matrix_1) {
  int rowsA = 3, columnsA = 2, rowsB = 2, columnsB = 3;
  matrix_t A = {}, B = {}, result_matrix = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;

  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;

  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;

  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;

  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;

  int result = s21_mult_matrix(&A, &B, &result_matrix);
  int expected = OK;

  double expected_el_0_0 = 9.0;
  double expected_el_0_1 = 11.0;
  double expected_el_0_2 = 17.0;

  double expected_el_1_0 = 12.0;
  double expected_el_1_1 = 13.0;
  double expected_el_1_2 = 22.0;

  double expected_el_2_0 = 15.0;
  double expected_el_2_1 = 15.0;
  double expected_el_2_2 = 27.0;

  double result_el_0_0 = result_matrix.matrix[0][0];
  double result_el_0_1 = result_matrix.matrix[0][1];
  double result_el_0_2 = result_matrix.matrix[0][2];

  double result_el_1_0 = result_matrix.matrix[1][0];
  double result_el_1_1 = result_matrix.matrix[1][1];
  double result_el_1_2 = result_matrix.matrix[1][2];

  double result_el_2_0 = result_matrix.matrix[2][0];
  double result_el_2_1 = result_matrix.matrix[2][1];
  double result_el_2_2 = result_matrix.matrix[2][2];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq(result_el_0_0, expected_el_0_0);
  ck_assert_double_eq(result_el_0_1, expected_el_0_1);
  ck_assert_double_eq(result_el_0_2, expected_el_0_2);

  ck_assert_double_eq(result_el_1_0, expected_el_1_0);
  ck_assert_double_eq(result_el_1_1, expected_el_1_1);
  ck_assert_double_eq(result_el_1_2, expected_el_1_2);

  ck_assert_double_eq(result_el_2_0, expected_el_2_0);
  ck_assert_double_eq(result_el_2_1, expected_el_2_1);
  ck_assert_double_eq(result_el_2_2, expected_el_2_2);

  // print_matrix(A);
  // printf("A====================\n");
  // print_matrix(B);
  // printf("B====================\n");
  // print_matrix(result_matrix);
  // printf("Res====================\n");

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_matrix);
}
END_TEST

/**
 матрицы не валидны, ERR_INVALID_MATRIX
 */
START_TEST(test_s21_mult_matrix_2) {
  int rows = 0, columns = 2;
  matrix_t A = {}, B = {}, result_matrix = {};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int result = s21_mult_matrix(&A, &B, &result_matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

/**
 * Матрицы валидны, но не совпадают нужные размеры. ERR_CALCULATION
 */
START_TEST(test_s21_mult_matrix_3) {
  int rowsA = 2, rowsB = 2, columnsA = 3, columnsB = 2;
  matrix_t A = {}, B = {}, result_matrix = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 0.012345;
  A.matrix[0][1] = 0.1;
  A.matrix[0][2] = 2.0;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;
  A.matrix[1][2] = 2.1;

  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 0.0123458888;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  int result = s21_mult_matrix(&A, &B, &result_matrix);
  int expected = ERR_CALCULATION;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_matrix);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *suite = suite_create("mult_matrix");
  TCase *tcase_core = tcase_create("mult_matrix");
  tcase_add_test(tcase_core, test_s21_mult_matrix_1);
  tcase_add_test(tcase_core, test_s21_mult_matrix_2);
  tcase_add_test(tcase_core, test_s21_mult_matrix_3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}