#include "../additional/additional.h"
#include "../s21_matrix.h"
#include "test.h"

START_TEST(test_s21_remove_matrix_1) {
  int rows = 3;
  int columns = 4;
  matrix_t matrix = {};

  s21_create_matrix(rows, columns, &matrix);
  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
}

Suite *s21_remove_matrix_suite(void) {
  Suite *suite = suite_create("remove_matrix");
  TCase *tcase_core = tcase_create("remove_matrix");
  tcase_add_test(tcase_core, test_s21_remove_matrix_1);

  suite_add_tcase(suite, tcase_core);
  return suite;
}