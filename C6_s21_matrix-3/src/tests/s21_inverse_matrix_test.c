#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Матрицы валидны, обратная матрица есть. OK
 */
START_TEST(test_s21_inverse_matrix_1) {
  int rowsA = 3, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;

  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;

  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;

  int result = s21_inverse_matrix(&A, &res);
  int expected = OK;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

/**
 матрицы не валидны, ERR_INVALID_MATRIX
 */
START_TEST(test_s21_inverse_matrix_2) {
  int rowsA = 0, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);

  int result = s21_inverse_matrix(&A, &res);
  int expected = ERR_INVALID_MATRIX;
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  int rowsA = 4, columnsA = 4;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;

  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[1][3] = 6.0;

  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  A.matrix[2][3] = 55.0;

  A.matrix[3][0] = 8.0;
  A.matrix[3][1] = 6.0;
  A.matrix[3][2] = 4.0;
  A.matrix[3][3] = 1.0;

  int result = s21_inverse_matrix(&A, &res);
  int expected = OK;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

/**
 * Матрицы валидны, детерминант = 0. ERR_CALCULATION
 */
START_TEST(test_s21_inverse_matrix_4) {
  int rowsA = 3, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;

  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  int result = s21_inverse_matrix(&A, &res);
  int expected = ERR_CALCULATION;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_s21_inverse_matrix_5) {
  int rowsA = 4, columnsA = 4;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;

  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;

  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  int result = s21_inverse_matrix(&A, &res);
  int expected = OK;

  double expected_el_0_0 = 0.0;
  double expected_el_0_1 = 1.0;
  double expected_el_0_2 = 0.0;
  double expected_el_0_3 = 0.0;

  double expected_el_1_0 = -5.0 / 23.0;
  double expected_el_1_1 = -121.0 / 23.0;
  double expected_el_1_2 = 2.0 / 23.0;
  double expected_el_1_3 = 1.0 / 23.0;

  double expected_el_2_0 = -18.0 / 23.0;
  double expected_el_2_1 = -379.0 / 46.0;
  double expected_el_2_2 = 19.0 / 46.0;
  double expected_el_2_3 = -25.0 / 46.0;

  double expected_el_3_0 = 53.0 / 69.0;
  double expected_el_3_1 = 1061.0 / 138.0;
  double expected_el_3_2 = -47.0 / 138.0;
  double expected_el_3_3 = 19.0 / 46.0;

  double result_el_0_0 = res.matrix[0][0];
  double result_el_0_1 = res.matrix[0][1];
  double result_el_0_2 = res.matrix[0][2];
  double result_el_0_3 = res.matrix[0][3];

  double result_el_1_0 = res.matrix[1][0];
  double result_el_1_1 = res.matrix[1][1];
  double result_el_1_2 = res.matrix[1][2];
  double result_el_1_3 = res.matrix[1][3];

  double result_el_2_0 = res.matrix[2][0];
  double result_el_2_1 = res.matrix[2][1];
  double result_el_2_2 = res.matrix[2][2];
  double result_el_2_3 = res.matrix[2][3];

  double result_el_3_0 = res.matrix[3][0];
  double result_el_3_1 = res.matrix[3][1];
  double result_el_3_2 = res.matrix[3][2];
  double result_el_3_3 = res.matrix[3][3];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq_tol(result_el_0_0, expected_el_0_0, 1e-6);
  ck_assert_double_eq_tol(result_el_0_1, expected_el_0_1, 1e-6);
  ck_assert_double_eq_tol(result_el_0_2, expected_el_0_2, 1e-6);
  ck_assert_double_eq_tol(result_el_0_3, expected_el_0_3, 1e-6);

  ck_assert_double_eq_tol(result_el_1_0, expected_el_1_0, 1e-6);
  ck_assert_double_eq_tol(result_el_1_1, expected_el_1_1, 1e-6);
  ck_assert_double_eq_tol(result_el_1_2, expected_el_1_2, 1e-6);
  ck_assert_double_eq_tol(result_el_1_3, expected_el_1_3, 1e-6);

  ck_assert_double_eq_tol(result_el_2_0, expected_el_2_0, 1e-6);
  ck_assert_double_eq_tol(result_el_2_1, expected_el_2_1, 1e-6);
  ck_assert_double_eq_tol(result_el_2_2, expected_el_2_2, 1e-6);
  ck_assert_double_eq_tol(result_el_2_3, expected_el_2_3, 1e-6);

  ck_assert_double_eq_tol(result_el_3_0, expected_el_3_0, 1e-6);
  ck_assert_double_eq_tol(result_el_3_1, expected_el_3_1, 1e-6);
  ck_assert_double_eq_tol(result_el_3_2, expected_el_3_2, 1e-6);
  ck_assert_double_eq_tol(result_el_3_3, expected_el_3_3, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_s21_inverse_matrix_6) {
  // success matrix 1x1
  matrix_t A = {};
  matrix_t res = {};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  int result = s21_inverse_matrix(&A, &res);
  int expected = OK;

  double result_el_0_0 = res.matrix[0][0];

  ck_assert_int_eq(result, expected);
  ck_assert_double_eq_tol(result_el_0_0, 1.0 / 21.0, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST
START_TEST(test_s21_inverse_matrix_7) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *suite = suite_create("inverse_matrix");
  TCase *tcase_core = tcase_create("inverse_matrix");
  tcase_add_test(tcase_core, test_s21_inverse_matrix_1);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_2);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_3);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_4);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_5);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_6);
  tcase_add_test(tcase_core, test_s21_inverse_matrix_7);

  suite_add_tcase(suite, tcase_core);
  return suite;
}