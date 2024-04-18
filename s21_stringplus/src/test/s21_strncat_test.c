#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strncat_1) {
  char* src = "world!\0";
  char* tmp = "Hello \0";
  char* dest1 = (char*)calloc(strlen(src) + strlen(tmp) + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + strlen(tmp) + 1, sizeof(char));
  strcpy(dest1, tmp);
  strcpy(dest2, tmp);
  s21_size_t n = 5;
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncat_2) {
  char* src = "world!\0";
  char* tmp = "Hello \0";
  s21_size_t n = 100;
  char* dest1 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  strcpy(dest1, tmp);
  strcpy(dest2, tmp);
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncat_3) {
  char* src = "world!\0";
  char* tmp = "Hello \0";
  s21_size_t n = 0;
  char* dest1 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  strcpy(dest1, tmp);
  strcpy(dest2, tmp);
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncat_4) {
  char* src = "world!\0";
  char* tmp = "\0";
  s21_size_t n = 5;
  char* dest1 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + strlen(tmp) + n + 1, sizeof(char));
  strcpy(dest1, tmp);
  strcpy(dest2, tmp);
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_strncat_5) {
  char src[] = "world!\0";
  char dest1[20] = "Hello \0";
  char dest2[20] = "Hello \0";
  s21_size_t n = 3;
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncat_6) {
  char src[] = "world!\0";
  char dest1[20] = "Hello \0";
  char dest2[20] = "Hello \0";
  s21_size_t n = 100;
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncat_7) {
  char src[] = "\0";
  char dest1[20] = "Hello \0";
  char dest2[20] = "Hello \0";
  s21_size_t n = 5;
  char* expected = strncat(dest1, src, n);
  char* result = s21_strncat(dest2, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite* s21_strncat_suite(void) {
  Suite* suite = suite_create("s21_strncat");
  TCase* tcase_core = tcase_create("s21_strncat");
  tcase_add_test(tcase_core, test_s21_strncat_1);
  tcase_add_test(tcase_core, test_s21_strncat_2);
  tcase_add_test(tcase_core, test_s21_strncat_3);
  tcase_add_test(tcase_core, test_s21_strncat_4);
  tcase_add_test(tcase_core, test_s21_strncat_5);
  tcase_add_test(tcase_core, test_s21_strncat_6);
  tcase_add_test(tcase_core, test_s21_strncat_7);

  suite_add_tcase(suite, tcase_core);
  return suite;
}