#include "test_s21_decimal.h"

START_TEST(test_truncate_1) {
  int err;
  s21_decimal value_1 = {{10000, 0, 0, 0x80000000}}, value_2 = {0},
              value_3 = {0};
  set_exp(&value_1, 3);
  s21_truncate(value_1, &value_2);
  s21_from_int_to_decimal(-10, &value_3);
  err = s21_is_equal(value_2, value_3);
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_truncate_2) {
  s21_decimal value_1 = {{0xf4628, 0x0, 0x0, 0x60000}},
              value_2 = {{1, 0, 0, 0}}, value_3 = {0};
  int err = s21_truncate(value_1, &value_3);
  int result = s21_is_equal(value_2, value_3);
  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *test_s21_truncate(void) {
  Suite *s = suite_create("\033[45m-=S21_truncate=-\033[0m");
  TCase *tc = tcase_create("s21_truncate");

  tcase_add_test(tc, test_truncate_1);
  tcase_add_test(tc, test_truncate_2);

  suite_add_tcase(s, tc);
  return s;
}