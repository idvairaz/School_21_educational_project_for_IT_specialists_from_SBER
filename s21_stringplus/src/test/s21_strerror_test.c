#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strerror_1) {
  for (int i = 0; i < 134; i++) {
    char* expected = strerror(i);
    char* result = s21_strerror(i);
    ck_assert_str_eq(result, expected);
  }
}
END_TEST

START_TEST(test_s21_strerror_2) {
  char* expected = strerror(-1);
  char* result = s21_strerror(-1);
  ck_assert_str_eq(result, expected);
  free(expected);
}
END_TEST

Suite* s21_strerror_suite(void) {
  Suite* suite = suite_create("s21_strerror");
  TCase* tcase_core = tcase_create("s21_strerror");
  tcase_add_test(tcase_core, test_s21_strerror_1);
  tcase_add_test(tcase_core, test_s21_strerror_2);

  suite_add_tcase(suite, tcase_core);
  return suite;
}