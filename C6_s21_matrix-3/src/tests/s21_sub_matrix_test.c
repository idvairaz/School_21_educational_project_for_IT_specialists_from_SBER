#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Матрицы для суммирования валидны и равноразмерны. OK
 */
START_TEST(test_s21_sub_matrix_1) {
  int rows = 3, columns = 2;
  matrix_t A = {}, B = {}, result_matrix = {};

  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 22.2;  // 1.126688;
  A.matrix[0][1] = 0.1;

  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 1.1;

  A.matrix[2][0] = 2.0;
  A.matrix[2][1] = 2.1;

  s21_create_matrix(rows, columns, &B);

  B.matrix[0][0] = 11.1;  // 2.883456;
  B.matrix[0][1] = 0.1;

  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 1.1;

  B.matrix[2][0] = 2.0;
  B.matrix[2][1] = 2.1;

  int result = s21_sub_matrix(&A, &B, &result_matrix);
  int expected = OK;

  double expected_el_0_0 = 11.1;  //-1.756768;
  double expected_el_0_1 = 0.0;
  double expected_el_1_0 = 0.0;
  double expected_el_1_1 = 0.0;
  double expected_el_2_0 = 0.0;
  double expected_el_2_1 = 0.0;

  double result_el_0_0 = result_matrix.matrix[0][0];
  double result_el_0_1 = result_matrix.matrix[0][1];
  double result_el_1_0 = result_matrix.matrix[1][0];
  double result_el_1_1 = result_matrix.matrix[1][1];
  double result_el_2_0 = result_matrix.matrix[2][0];
  double result_el_2_1 = result_matrix.matrix[2][1];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq(result_el_0_0, expected_el_0_0);
  ck_assert_double_eq(result_el_0_1, expected_el_0_1);
  ck_assert_double_eq(result_el_1_0, expected_el_1_0);
  ck_assert_double_eq(result_el_1_1, expected_el_1_1);
  ck_assert_double_eq(result_el_2_0, expected_el_2_0);
  ck_assert_double_eq(result_el_2_1, expected_el_2_1);

  // printf("A====================\n");
  // print_matrix(A);
  // printf("B====================\n");
  // print_matrix(B);
  // printf("Res====================\n");
  // print_matrix(result_matrix);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_matrix);
}
END_TEST

/**
 матрицы не валидны, ERR_INVALID_MATRIX
 */
START_TEST(test_s21_sub_matrix_2) {
  int rows = 0, columns = 2;
  matrix_t A = {}, B = {}, result_matrix = {};

  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int result = s21_sub_matrix(&A, &B, &result_matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

/**
 * Матрицы валидны, но НЕравноразмерны. ERR_CALCULATION
 */
START_TEST(test_s21_sub_matrix_3) {
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

  int result = s21_sub_matrix(&A, &B, &result_matrix);
  int expected = ERR_CALCULATION;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *suite = suite_create("sub_matrix");
  TCase *tcase_core = tcase_create("sub_matrix");
  tcase_add_test(tcase_core, test_s21_sub_matrix_1);
  tcase_add_test(tcase_core, test_s21_sub_matrix_2);
  tcase_add_test(tcase_core, test_s21_sub_matrix_3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}