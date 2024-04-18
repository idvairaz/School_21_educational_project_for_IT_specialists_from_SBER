#include "test_s21_decimal.h"

START_TEST(test1) {
  s21_decimal dst = {{1111011}};  // 123
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test2) {
  s21_decimal dst = {{0}};  // 0
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test3) {
  s21_decimal dst = {{_MAX_INT}};  // 2,147,483,647
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test4) {
  s21_decimal dst = {
      {0b1111111111111111111111111111111}};  // Максимальное значение int
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test5) {
  s21_decimal dst = {{_MIN_INT}};  // -2,147,483,648
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test6) {
  s21_decimal dst = {
      {0b10000000000000000000000000000000}};  // Минимальное значение int
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

START_TEST(test7) {
  s21_decimal dst = {{0, 0, 1, 0}};  // Вызовет ошибку конвертации
  int src;
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 1);
}
END_TEST

START_TEST(test8) {
  s21_decimal dst;
  int src = -2147483648;  // Минимальное значение int
  s21_from_int_to_decimal(src, &dst);
  ck_assert_int_eq(s21_from_decimal_to_int(dst, &src), 0);
}
END_TEST

Suite *test_s21_from_decimal_to_int() {
  Suite *s = suite_create("\033[45m-=s21_from_decimal_to_int=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_int_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);

  suite_add_tcase(s, tc);
  return s;
}