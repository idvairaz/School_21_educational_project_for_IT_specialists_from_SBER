#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Исходящая и итоговая матрицы валидны и равноразмерны. OK
 */
START_TEST(test_s21_mult_number_1) {
  int rows = 3, columns = 2;
  double number = 2.2;
  matrix_t A = {}, result_matrix = {};

  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 22.2;
  A.matrix[0][1] = 0.4;  // 0.1;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.6;  // 0.1; //1.1;

  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 2.4;  // 2.1;

  int result = s21_mult_number(&A, number, &result_matrix);
  int expected = OK;

  double expected_el_0_0 = 48.84;
  double expected_el_0_1 = 0.88;  // 0.22;
  double expected_el_1_0 = 2.2;
  double expected_el_1_1 = 1.32;  // 0.22; //2.42;
  double expected_el_2_0 = 4.4;
  double expected_el_2_1 = 5.28;  // 4.62;

  double result_el_0_0 = result_matrix.matrix[0][0];
  double result_el_0_1 = result_matrix.matrix[0][1];
  double result_el_1_0 = result_matrix.matrix[1][0];
  double result_el_1_1 = result_matrix.matrix[1][1];
  double result_el_2_0 = result_matrix.matrix[2][0];
  double result_el_2_1 = result_matrix.matrix[2][1];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq(result_el_0_0, expected_el_0_0);
  ck_assert_ldouble_eq_tol(result_el_0_1, expected_el_0_1, 1e-6);
  ck_assert_double_eq(result_el_1_0, expected_el_1_0);
  ck_assert_double_eq_tol(result_el_1_1, expected_el_1_1, 1e-6);
  ck_assert_double_eq(result_el_2_0, expected_el_2_0);
  ck_assert_double_eq(result_el_2_1, expected_el_2_1);

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
START_TEST(test_s21_mult_number_2) {
  int rows = 0, columns = 2;
  double number = 2.2;
  matrix_t A = {}, result_matrix = {};

  s21_create_matrix(rows, columns, &A);

  int result = s21_mult_number(&A, number, &result_matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *suite = suite_create("mult_number");
  TCase *tcase_core = tcase_create("mult_number");
  tcase_add_test(tcase_core, test_s21_mult_number_1);
  tcase_add_test(tcase_core, test_s21_mult_number_2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}