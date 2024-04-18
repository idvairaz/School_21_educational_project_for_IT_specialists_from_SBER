#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

/**
 * Матрицы валидны, вычисления можно произвести. OK
 */
START_TEST(test_s21_calc_complements_1) {
  int rowsA = 3, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;

  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;

  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;

  int result = s21_calc_complements(&A, &res);
  int expected = OK;

  double expected_el_0_0 = 0.0;
  double expected_el_0_1 = 10.0;
  double expected_el_0_2 = -20.0;

  double expected_el_1_0 = 4.0;
  double expected_el_1_1 = -14.0;
  double expected_el_1_2 = 8.0;

  double expected_el_2_0 = -8.0;
  double expected_el_2_1 = -2.0;
  double expected_el_2_2 = 4.0;

  double result_el_0_0 = res.matrix[0][0];
  double result_el_0_1 = res.matrix[0][1];
  double result_el_0_2 = res.matrix[0][2];

  double result_el_1_0 = res.matrix[1][0];
  double result_el_1_1 = res.matrix[1][1];
  double result_el_1_2 = res.matrix[1][2];

  double result_el_2_0 = res.matrix[2][0];
  double result_el_2_1 = res.matrix[2][1];
  double result_el_2_2 = res.matrix[2][2];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq_tol(result_el_0_0, expected_el_0_0, 1e-6);
  ck_assert_double_eq_tol(result_el_0_1, expected_el_0_1, 1e-6);
  ck_assert_double_eq_tol(result_el_0_2, expected_el_0_2, 1e-6);

  ck_assert_double_eq_tol(result_el_1_0, expected_el_1_0, 1e-6);
  ck_assert_double_eq_tol(result_el_1_1, expected_el_1_1, 1e-6);
  ck_assert_double_eq_tol(result_el_1_2, expected_el_1_2, 1e-6);

  ck_assert_double_eq_tol(result_el_2_0, expected_el_2_0, 1e-6);
  ck_assert_double_eq_tol(result_el_2_1, expected_el_2_1, 1e-6);
  ck_assert_double_eq_tol(result_el_2_2, expected_el_2_2, 1e-6);

  //   // printf("A====================\n");
  //   // print_matrix(A);

  //   // printf("M====================\n");
  //   // print_matrix(res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

// /*Матрицы валидны, вычисления можно произвести. OK*/
START_TEST(test_s21_calc_complements_2) {
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

  int result = s21_calc_complements(&A, &res);
  int expected = OK;

  double expected_el_0_0 = -1.0;
  double expected_el_0_1 = 38.0;
  double expected_el_0_2 = -27.0;

  double expected_el_1_0 = 1.0;
  double expected_el_1_1 = -41.0;
  double expected_el_1_2 = 29.0;

  double expected_el_2_0 = -1.0;
  double expected_el_2_1 = 34.0;
  double expected_el_2_2 = -24.0;

  double result_el_0_0 = res.matrix[0][0];
  double result_el_0_1 = res.matrix[0][1];
  double result_el_0_2 = res.matrix[0][2];

  double result_el_1_0 = res.matrix[1][0];
  double result_el_1_1 = res.matrix[1][1];
  double result_el_1_2 = res.matrix[1][2];

  double result_el_2_0 = res.matrix[2][0];
  double result_el_2_1 = res.matrix[2][1];
  double result_el_2_2 = res.matrix[2][2];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq_tol(result_el_0_0, expected_el_0_0, 1e-6);
  ck_assert_double_eq_tol(result_el_0_1, expected_el_0_1, 1e-6);
  ck_assert_double_eq_tol(result_el_0_2, expected_el_0_2, 1e-6);

  ck_assert_double_eq_tol(result_el_1_0, expected_el_1_0, 1e-6);
  ck_assert_double_eq_tol(result_el_1_1, expected_el_1_1, 1e-6);
  ck_assert_double_eq_tol(result_el_1_2, expected_el_1_2, 1e-6);

  ck_assert_double_eq_tol(result_el_2_0, expected_el_2_0, 1e-6);
  ck_assert_double_eq_tol(result_el_2_1, expected_el_2_1, 1e-6);
  ck_assert_double_eq_tol(result_el_2_2, expected_el_2_2, 1e-6);

  //   // printf("A====================\n");
  //   // print_matrix(A);

  //   // printf("M====================\n");
  //   // print_matrix(res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}

END_TEST

// /**
//  матрица не валидна, ERR_INVALID_MATRIX
//  */
START_TEST(test_s21_calc_complements_3) {
  int rowsA = 0, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);

  int result = s21_calc_complements(&A, &res);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}

END_TEST
/**
 * Матрица валидна, но не квадратная. ERR_CALCULATION
 */
START_TEST(test_s21_calc_complements_4) {
  int rowsA = 4, columnsA = 3;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);

  int result = s21_calc_complements(&A, &res);
  int expected = ERR_CALCULATION;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&A);
}
START_TEST(test_s21_calc_complements_5) {
  // success with task reference values
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(test_s21_calc_complements_7) {
  int rowsA = 4, columnsA = 4;
  matrix_t A = {};
  matrix_t res = {};

  s21_create_matrix(rowsA, columnsA, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 3.0;

  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[1][3] = 2.0;

  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  A.matrix[2][3] = 1.0;

  A.matrix[3][0] = 5.0;
  A.matrix[3][1] = 2.0;
  A.matrix[3][2] = 5.0;
  A.matrix[3][3] = 1.0;

  int result = s21_calc_complements(&A, &res);
  int expected = OK;

  double expected_el_0_0 = 0.0;
  double expected_el_0_1 = -40.0;
  double expected_el_0_2 = 0.0;

  double expected_el_1_0 = -16.0;
  double expected_el_1_1 = 56.0;
  double expected_el_1_2 = 0.0;

  double expected_el_2_0 = 32.0;
  double expected_el_2_1 = 8.0;
  double expected_el_2_2 = -40.0;

  double result_el_0_0 = res.matrix[0][0];
  double result_el_0_1 = res.matrix[0][1];
  double result_el_0_2 = res.matrix[0][2];

  double result_el_1_0 = res.matrix[1][0];
  double result_el_1_1 = res.matrix[1][1];
  double result_el_1_2 = res.matrix[1][2];

  double result_el_2_0 = res.matrix[2][0];
  double result_el_2_1 = res.matrix[2][1];
  double result_el_2_2 = res.matrix[2][2];

  ck_assert_int_eq(result, expected);

  ck_assert_double_eq_tol(result_el_0_0, expected_el_0_0, 1e-6);
  ck_assert_double_eq_tol(result_el_0_1, expected_el_0_1, 1e-6);
  ck_assert_double_eq_tol(result_el_0_2, expected_el_0_2, 1e-6);

  ck_assert_double_eq_tol(result_el_1_0, expected_el_1_0, 1e-6);
  ck_assert_double_eq_tol(result_el_1_1, expected_el_1_1, 1e-6);
  ck_assert_double_eq_tol(result_el_1_2, expected_el_1_2, 1e-6);

  ck_assert_double_eq_tol(result_el_2_0, expected_el_2_0, 1e-6);
  ck_assert_double_eq_tol(result_el_2_1, expected_el_2_1, 1e-6);
  ck_assert_double_eq_tol(result_el_2_2, expected_el_2_2, 1e-6);

  // printf("A====================\n");
  // print_matrix(&A);

  // printf("M====================\n");
  // print_matrix(&res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_s21_calc_complements_8) {
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

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_calc_complements_9) {
  matrix_t A = {};
  matrix_t res = {};

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

  int result = s21_calc_complements(&A, &res);
  int expected = OK;

  double expected_el_0_0 = 0.0;
  double expected_el_0_1 = -30.0;
  double expected_el_0_2 = -108.0;
  double expected_el_0_3 = 106.0;

  double expected_el_1_0 = 138.0;
  double expected_el_1_1 = -726.0;
  double expected_el_1_2 = -1137;
  double expected_el_1_3 = 1061;

  double expected_el_2_0 = 0.0;
  double expected_el_2_1 = 12.0;
  double expected_el_2_2 = 57.0;
  double expected_el_2_3 = -47;

  double expected_el_3_0 = 0.0;
  double expected_el_3_1 = 6.0;
  double expected_el_3_2 = -75.0;
  double expected_el_3_3 = 57;

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

Suite *s21_calc_complements_suite(void) {
  Suite *suite = suite_create("calc_complements");
  TCase *tcase_core = tcase_create("calc_complements");
  tcase_add_test(tcase_core, test_s21_calc_complements_1);
  tcase_add_test(tcase_core, test_s21_calc_complements_2);
  tcase_add_test(tcase_core, test_s21_calc_complements_3);
  tcase_add_test(tcase_core, test_s21_calc_complements_4);
  tcase_add_test(tcase_core, test_s21_calc_complements_5);
  tcase_add_test(tcase_core, test_s21_calc_complements_7);
  tcase_add_test(tcase_core, test_s21_calc_complements_8);
  tcase_add_test(tcase_core, test_s21_calc_complements_9);

  suite_add_tcase(suite, tcase_core);
  return suite;
}