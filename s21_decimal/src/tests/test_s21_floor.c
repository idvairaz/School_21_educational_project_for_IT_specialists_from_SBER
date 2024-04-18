#include "test_s21_decimal.h"

START_TEST(test_floor_1) {
  int res;
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}}, result = {0};
  set_exp(&value_1, 1);
  s21_floor(value_1, &result);

  res = value_2.bits[0] == result.bits[0] &&
        value_2.bits[1] == result.bits[1] &&
        value_2.bits[2] == result.bits[2] && value_2.bits[3] == result.bits[3];

  ck_assert_int_eq(res, 1);
}
END_TEST
START_TEST(test_floor_2) {
  int err;
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}}, result = {0};
  set_exp(&value_1, 1);
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  s21_floor(value_1, &result);

  err = value_2.bits[0] == result.bits[0] &&
        value_2.bits[1] == result.bits[1] &&
        value_2.bits[2] == result.bits[2] && value_2.bits[3] == result.bits[3];

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_floor_3) {
  s21_decimal value_1 = {{100, 0, 0, 0}}, result = {0};
  set_exp(&value_1, 1);
  set_sign(&value_1, 1);
  int err = s21_floor(value_1, &result);

  ck_assert_int_eq(err, 0);
  ck_assert_int_eq(s21_is_equal(value_1, result), 1);
}
END_TEST

Suite *test_s21_floor(void) {
  Suite *s = suite_create("\033[45m-=S21_floor=-\033[0m");
  TCase *tc = tcase_create("s21_floor");

  tcase_add_test(tc, test_floor_1);
  tcase_add_test(tc, test_floor_2);
  tcase_add_test(tc, test_floor_3);

  suite_add_tcase(s, tc);
  return s;
}