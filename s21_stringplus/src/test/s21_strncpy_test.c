#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strncpy_1) {
  const char* src = "lalala\0";
  int n = 3;
  char* dest1 = calloc(n + 1, sizeof(char));
  char* dest2 = calloc(n + 1, sizeof(char));
  char* expected = strncpy(dest1, src, n);
  char* result = s21_strncpy(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  const char* src = "lalala\0";
  char* dest1 = (char*)calloc(strlen(src) + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + 1, sizeof(char));
  s21_size_t n = 0;
  char* expected = strncpy(dest1, src, n);
  char* result = s21_strncpy(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  const char* src = "lalala\0";
  s21_size_t n = 100;
  char* dest1 = (char*)calloc(strlen(src) + n + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + n + 1, sizeof(char));
  char* expected = strncpy(dest1, src, n);
  char* result = s21_strncpy(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char src[] = "lalala\0";
  char dest1[20] = "dest\0";
  char dest2[20] = "dest\0";
  s21_size_t n = 3;
  char* expected = strncpy(dest1, src, n);
  char* result = s21_strncpy(dest2, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char str1[] = "test of string";
  char dest1[15] = "";

  char str2[] = "test\0";
  char dest2[5] = "";

  char str3[6] = "test ";
  char dest3[11] = "crushcrush";

  ck_assert_str_eq(strncpy(dest1, str1, 5), s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq(strncpy(dest2, str2, 4), s21_strncpy(dest2, str2, 4));
  ck_assert_str_eq(strncpy(dest3, str3, 10), s21_strncpy(dest3, str3, 10));
}
END_TEST

Suite* s21_strncpy_suite(void) {
  Suite* suite = suite_create("s21_strncpy");
  TCase* tcase_core = tcase_create("s21_strncpy");
  tcase_add_test(tcase_core, test_s21_strncpy_1);
  tcase_add_test(tcase_core, test_s21_strncpy_2);
  tcase_add_test(tcase_core, test_s21_strncpy_3);
  tcase_add_test(tcase_core, test_s21_strncpy_4);
  tcase_add_test(tcase_core, test_s21_strncpy_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}