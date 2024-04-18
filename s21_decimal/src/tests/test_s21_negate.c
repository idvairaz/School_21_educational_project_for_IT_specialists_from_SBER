#include "test_s21_decimal.h"

START_TEST(test_negate_1) {
  int err;
  s21_decimal value_1 = {{0x1, 0, 0, 0x80000000}}, value_2;

  s21_negate(value_1, &value_2);

  err = value_1.bits[0] == value_2.bits[0] &&
        value_1.bits[1] == value_2.bits[1] &&
        value_1.bits[2] == value_2.bits[2] &&
        get_sign(value_1) != get_sign(value_2) &&
        get_exp_10(value_1) == get_exp_10(value_2);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_negate_2) {
  int err;
  s21_decimal value_1 = {{0x1, 0, 0, 0}}, value_2;

  s21_negate(value_1, &value_2);

  err = value_1.bits[0] == value_2.bits[0] &&
        value_1.bits[1] == value_2.bits[1] &&
        value_1.bits[2] == value_2.bits[2] &&
        get_sign(value_1) != get_sign(value_2) &&
        get_exp_10(value_1) == get_exp_10(value_2);

  ck_assert_int_eq(err, 1);
}
END_TEST

Suite *test_s21_negate(void) {
  Suite *s = suite_create("\033[45m-=S21_negate=-\033[0m");
  TCase *tc = tcase_create("s21_negate");

  tcase_add_test(tc, test_negate_1);
  tcase_add_test(tc, test_negate_2);

  suite_add_tcase(s, tc);
  return s;
}