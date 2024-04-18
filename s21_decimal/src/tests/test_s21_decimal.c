#include "test_s21_decimal.h"

int main(void) {
  int failed = 0;
  int total = 0;

  Suite *test_s21_decimal[] = {test_s21_add(),
                               test_s21_sub(),
                               test_s21_mul(),
                               test_s21_div(),
                               test_s21_is_less(),
                               test_s21_is_less_or_equal(),
                               test_s21_is_greater(),
                               test_s21_is_greater_or_equal(),
                               test_s21_is_equal(),
                               test_s21_is_not_equal(),
                               test_s21_from_int_to_decimal(),
                               test_s21_from_float_to_decimal(),
                               test_s21_from_decimal_to_int(),
                               test_s21_from_decimal_to_float(),
                               test_s21_floor(),
                               test_s21_round(),
                               test_s21_truncate(),
                               test_s21_negate(),
                               NULL};

  for (int i = 0; test_s21_decimal[i] != NULL; i++) {
    SRunner *sr = srunner_create(test_s21_decimal[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }
  printf("\033[41m========= FAILED : %-3d =========\033[0m\n", failed);
  printf("\033[42m\033[30m========= SUCCESS: %-3d =========\033[0m\n",
         total - failed);
  printf("\033[42m\033[30m========= TOTAL: %-3d =========\033[0m\n", total);

  return failed == 0 ? 0 : 1;
}