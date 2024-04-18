#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_trim_1) {
  const char *str = "123abc456xyz789\0";
  const char *trim_chars = "123456789\0";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = "abc456xyz\0";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_2) {
  const char *str = "123abc456xyz789\0";
  const char *trim_chars = s21_NULL;
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = s21_NULL;
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_3) {
  const char *str = s21_NULL;
  const char *trim_chars = "123456789\0";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = s21_NULL;
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_4) {
  const char *str = "\0";
  const char *trim_chars = "123456789\0";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = "\0";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_5) {
  const char *str = "123abc456xyz789\0";
  const char *trim_chars = "\0";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = "123abc456xyz789\0";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_6) {
  const char *str = "1234ab45678\0";
  const char *trim_chars = "123456789\0";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = "ab\0";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_trim_7) {
  const char *str = " \n   Hello, world!  !\n";
  const char *trim_chars = "";
  char *result = (char *)s21_trim(str, trim_chars);
  char *expected = " \n   Hello, world!  !\n";
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite = suite_create("s21_trim");
  TCase *tcase_core = tcase_create("s21_trim");
  tcase_add_test(tcase_core, test_s21_trim_1);
  tcase_add_test(tcase_core, test_s21_trim_2);
  tcase_add_test(tcase_core, test_s21_trim_3);
  tcase_add_test(tcase_core, test_s21_trim_4);
  tcase_add_test(tcase_core, test_s21_trim_5);
  tcase_add_test(tcase_core, test_s21_trim_6);
  tcase_add_test(tcase_core, test_s21_trim_7);

  suite_add_tcase(suite, tcase_core);
  return suite;
}