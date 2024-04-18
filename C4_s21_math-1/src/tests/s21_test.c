#include "s21_test.h"

int main() {
  Suite *cases[] = {s21_fabs_test_suite(),  s21_abs_test_suite(),
                    s21_pow_test_suite(),   s21_sqrt_test_suite(),
                    s21_sin_test_suite(),   s21_cos_test_suite(),
                    s21_tan_test_suite(),   s21_ceil_test_suite(),
                    s21_floor_test_suite(), s21_fmod_test_suite(),
                    s21_atan_test_suite(),  s21_asin_test_suite(),
                    s21_acos_test_suite(),  s21_log_test_suite(),
                    s21_exp_test_suite(),   NULL};

  int total = 0;
  int failed = 0;

  for (int i = 0; i < (int)(sizeof(cases) / sizeof(cases[0])); i++) {
    printf("\n");
    SRunner *sr = srunner_create(cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    total += srunner_ntests_run(sr);
    srunner_free(sr);
  }
  printf("\n");

  printf("Total: %d\nFailed: %d\nGood: %d\n", total, failed, total - failed);

  return 0;
}
