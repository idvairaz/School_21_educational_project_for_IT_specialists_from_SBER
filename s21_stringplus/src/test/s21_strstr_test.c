#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strstr_1) {
  const char* haystack = "abcd\0";
  const char* needle = "abcd\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_2) {
  const char* haystack = "Hello world!\0";
  const char* needle = "world\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_3) {
  const char* haystack = "Hello world!\0";
  const char* needle = "ups\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_4) {
  const char* haystack = "Hello world!\0";
  const char* needle = "\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_5) {
  const char* haystack = "\0";
  const char* needle = "oh!\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strstr_6) {
  const char* haystack = "H w llo world!\0";
  const char* needle = "world\0";
  char* expected = strstr(haystack, needle);
  char* result = s21_strstr(haystack, needle);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* s21_strstr_suite(void) {
  Suite* suite = suite_create("s21_strstr");
  TCase* tcase_core = tcase_create("s21_strstr");
  tcase_add_test(tcase_core, test_s21_strstr_1);
  tcase_add_test(tcase_core, test_s21_strstr_2);
  tcase_add_test(tcase_core, test_s21_strstr_3);
  tcase_add_test(tcase_core, test_s21_strstr_4);
  tcase_add_test(tcase_core, test_s21_strstr_5);
  tcase_add_test(tcase_core, test_s21_strstr_6);

  suite_add_tcase(suite, tcase_core);
  return suite;
}