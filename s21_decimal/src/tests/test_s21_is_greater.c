#include "test_s21_decimal.h"

START_TEST(test_greater_1) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(100, &value_2);
  s21_from_int_to_decimal(10, &value_1);

  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_greater_2) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(10, &value_1);

  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_greater_3) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(10, &value_2);
  s21_from_int_to_decimal(100, &value_1);

  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_greater_4) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(100, &value_2);
  s21_from_int_to_decimal(100, &value_1);
  set_sign(&value_1, 1);

  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(test_greater_5) {
  s21_decimal value_1, value_2;
  s21_from_int_to_decimal(100, &value_2);
  s21_from_int_to_decimal(100, &value_1);
  set_sign(&value_2, 1);

  int error = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(error, 1);
}
END_TEST

Suite *test_s21_is_greater(void) {
  Suite *s = suite_create("\033[45m-=S21_is_greater=-\033[0m");
  TCase *tc = tcase_create("s21_is_greater");

  tcase_add_test(tc, test_greater_1);
  tcase_add_test(tc, test_greater_2);
  tcase_add_test(tc, test_greater_3);
  tcase_add_test(tc, test_greater_4);
  tcase_add_test(tc, test_greater_5);

  suite_add_tcase(s, tc);
  return s;
}