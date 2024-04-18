#include "./tests/test.h"

int main() {
  run_tests();
  return 0;
}

void run_testcase(Suite *testscase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');
  printf("Test %d:\n", counter_testcase);

  SRunner *sr = srunner_create(testscase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);  // изменить CK_ENV на CK_VERBOSE , для более
                                // подробного вывода информации о тестах
  srunner_free(sr);
}
void run_tests() {
  int counter_testcase = 0;
  Suite *list_cases[] = {
      s21_create_matrix_suite(),  s21_remove_matrix_suite(),
      s21_eq_matrix_suite(),      s21_sum_matrix_suite(),
      s21_sub_matrix_suite(),     s21_mult_number_suite(),
      s21_mult_matrix_suite(),    s21_transpose_suite(),
      s21_determinant_suite(),    s21_calc_complements_suite(),
      s21_inverse_matrix_suite(), NULL};

  for (Suite **testcase = list_cases; *testcase; testcase++) {
    run_testcase(*testcase, ++counter_testcase);
  }
}
