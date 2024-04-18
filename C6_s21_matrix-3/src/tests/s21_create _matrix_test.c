#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_s21_create_matrix_1) {
  int rows = 3;
  int columns = 4;
  matrix_t matrix = {};

  int result = s21_create_matrix(rows, columns, &matrix);
  int expected = OK;

  ck_assert_int_eq(result, expected);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  int rows = 0;
  int columns = 4;
  matrix_t matrix = {};

  int result = s21_create_matrix(rows, columns, &matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  int rows = 3;
  int columns = 4;

  int result = s21_create_matrix(rows, columns, NULL);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  int rows = 2;
  int columns = 0;
  matrix_t matrix = {};

  int result = s21_create_matrix(rows, columns, &matrix);
  int expected = ERR_INVALID_MATRIX;

  ck_assert_int_eq(result, expected);
}
END_TEST

END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *suite = suite_create("create_matrix");
  TCase *tcase_core = tcase_create("create_matrix");
  tcase_add_test(tcase_core, test_s21_create_matrix_1);
  tcase_add_test(tcase_core, test_s21_create_matrix_2);
  tcase_add_test(tcase_core, test_s21_create_matrix_3);
  tcase_add_test(tcase_core, test_s21_create_matrix_4);

  suite_add_tcase(suite, tcase_core);
  return suite;
}