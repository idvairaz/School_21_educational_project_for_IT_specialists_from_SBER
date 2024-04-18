#include "test_s21_decimal.h"

START_TEST(test1) {
  s21_decimal dst;
  int src = 123;  // 1111011
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test2) {
  s21_decimal dst;
  int src = 0;  // 0
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test3) {
  s21_decimal dst;
  int src = _MAX_INT;  // 2,147,483,647
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test4) {
  s21_decimal dst;
  int src = _MIN_INT;  // -2,147,483,648
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test5) {
  s21_decimal dst;
  int src = 214748367;  // Максимальное значение int
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test6) {
  s21_decimal dst;
  int src = -2147483648;  // Минимальное значение int
  ck_assert_int_eq(s21_from_int_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test7) {
  s21_decimal dst;
  int src = -2147483648;  // Минимальное значение int
  s21_from_int_to_decimal(src, &dst);
  int result = 0;
  s21_from_decimal_to_int(dst, &result);
  ck_assert_int_eq(result, src);
}
END_TEST

Suite *test_s21_from_int_to_decimal() {
  Suite *s = suite_create("\033[45m-=s21_from_int_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);

  suite_add_tcase(s, tc);
  return s;
}