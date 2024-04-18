#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Матрицы равны. SUCCESS
 */
START_TEST(test_s21_eq_matrix_1) {
  int rowsA = 3, rowsB = 3, columnsA = 2, columnsB = 2;
  matrix_t A = {}, B = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 0.0123456789;
  A.matrix[0][1] = 0.1;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 2.1;

  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 0.0123456888;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  B.matrix[2][0] = 2.0;
  B.matrix[2][1] = 2.1;

  int result = s21_eq_matrix(&A, &B);
  int expected = SUCCESS;

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq_tol(A.matrix[0][0], B.matrix[0][0], 1e-6);
  ck_assert_double_eq_tol(A.matrix[0][1], B.matrix[0][1], 1e-6);

  ck_assert_double_eq_tol(A.matrix[1][0], B.matrix[1][0], 1e-6);
  ck_assert_double_eq_tol(A.matrix[1][1], B.matrix[1][1], 1e-6);

  ck_assert_double_eq_tol(A.matrix[2][0], B.matrix[2][0], 1e-6);
  ck_assert_double_eq_tol(A.matrix[2][1], B.matrix[2][1], 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * разное кол-во рядов, матрицы не равны. FAILURE
 */
START_TEST(test_s21_eq_matrix_2) {
  int rowsA = 3, rowsB = 2, columnsA = 2, columnsB = 2;
  matrix_t A = {}, B = {};

  s21_create_matrix(rowsA, columnsA, &A);

  A.matrix[0][0] = 0.0123456789;
  A.matrix[0][1] = 0.1;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 2.1;

  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 0.0123456888;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  int result = s21_eq_matrix(&A, &B);

  int expected = FAILURE;
  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * одинаковое  кол-во рядов и колонок, но значения
 * соответственно не равны. Матрицы равны. FAILURE
 */
START_TEST(test_s21_eq_matrix_3) {
  int rowsA = 3, rowsB = 3, columnsA = 2, columnsB = 2;
  matrix_t A = {}, B = {};

  s21_create_matrix(rowsA, columnsA, &A);

  A.matrix[0][0] = 0.0123456789;
  A.matrix[0][1] = 0.1111;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  A.matrix[2][0] = 2.222;
  A.matrix[2][1] = 2.1;

  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 0.0123456888;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  B.matrix[2][0] = 2.0;
  B.matrix[2][1] = 2.1;

  int result = s21_eq_matrix(&A, &B);
  int expected = FAILURE;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 * разное кол-во колонок, матрицы не равны. FAILURE
 */
START_TEST(test_s21_eq_matrix_4) {
  int rowsA = 2, rowsB = 2, columnsA = 3, columnsB = 2;
  matrix_t A = {}, B = {};

  s21_create_matrix(rowsA, columnsA, &A);

  A.matrix[0][0] = 0.0123456789;
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

  int result = s21_eq_matrix(&A, &B);
  int expected = FAILURE;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

/**
 *Во входящих параметрах невалидная матрица. FAILURE
 */
START_TEST(test_s21_eq_matrix_5) {
  int rowsA = 0, rowsB = 3, columnsA = 2, columnsB = 2;
  matrix_t A = {}, B = {};

  s21_create_matrix(rowsA, columnsA, &A);
  s21_create_matrix(rowsB, columnsB, &B);

  B.matrix[0][0] = 0.0123456888;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  B.matrix[2][0] = 2.0;
  B.matrix[2][1] = 2.1;

  int result = s21_eq_matrix(&A, &B);
  int expected = FAILURE;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *suite = suite_create("eq_matrix");
  TCase *tcase_core = tcase_create("eq_matrix");
  tcase_add_test(tcase_core, test_s21_eq_matrix_1);
  tcase_add_test(tcase_core, test_s21_eq_matrix_2);
  tcase_add_test(tcase_core, test_s21_eq_matrix_3);
  tcase_add_test(tcase_core, test_s21_eq_matrix_4);
  tcase_add_test(tcase_core, test_s21_eq_matrix_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}