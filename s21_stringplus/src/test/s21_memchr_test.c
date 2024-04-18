#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_memchr_1) {
  const char* str = "lalala\0";
  int c = 'a';
  s21_size_t n = 4;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_2) {
  const char* str = "lalala\0";
  int c = 'b';
  s21_size_t n = sizeof(str);
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_3) {
  const char* str = "lalalab\0";
  int c = 'b';
  s21_size_t n = sizeof(str);
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_4) {
  const char* str = "lalalai\0";
  int c = 'i';
  s21_size_t n = 2;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_5) {
  const char* str = "la\nlala\0";
  int c = '\n';
  s21_size_t n = 4;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_6) {
  const char* str = "l\0alala\0";
  int c = 'a';
  s21_size_t n = 4;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_7) {
  const char* str = "lalala\0";
  int c = 'a';
  s21_size_t n = 8;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_8) {
  const char* str = "lalala\0";
  int c = 'b';
  s21_size_t n = 100;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_9) {
  const char* str = "lalala\0";
  int c = 'l';
  s21_size_t n = 1;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_10) {
  const char* s = "llla\0";
  int len = strlen(s);
  char* str = (char*)calloc((len + 1), sizeof(char));
  memcpy(str, s, len);
  int c = 'a';
  s21_size_t n = 10;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
  free(str);
}
END_TEST

START_TEST(test_s21_memchr_11) {
  const char* s = "llla\0";
  int len = strlen(s);
  char* str = (char*)calloc((len + 1), sizeof(char));
  memcpy(str, s, len);
  int c = 'a';
  s21_size_t n = 0;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
  free(str);
}
END_TEST

START_TEST(test_s21_memchr_12) {
  const char* s = "llla\0";
  int len = strlen(s);
  char* str = (char*)calloc((len + 1), sizeof(char));
  memcpy(str, s, len);
  int c = 'a';
  s21_size_t n = 100;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
  free(str);
}
END_TEST

START_TEST(test_s21_memchr_13) {
  const char* str = "\0";
  int c = 'l';
  s21_size_t n = 10;
  char* expected = memchr(str, c, n);
  char* result = s21_memchr(str, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite* s21_memchr_suite(void) {
  Suite* suite = suite_create("s21_memchr");
  TCase* tcase_core = tcase_create("s21_memchr");
  tcase_add_test(tcase_core, test_s21_memchr_1);
  tcase_add_test(tcase_core, test_s21_memchr_2);
  tcase_add_test(tcase_core, test_s21_memchr_3);
  tcase_add_test(tcase_core, test_s21_memchr_4);
  tcase_add_test(tcase_core, test_s21_memchr_5);
  tcase_add_test(tcase_core, test_s21_memchr_6);
  tcase_add_test(tcase_core, test_s21_memchr_7);
  tcase_add_test(tcase_core, test_s21_memchr_8);
  tcase_add_test(tcase_core, test_s21_memchr_9);
  tcase_add_test(tcase_core, test_s21_memchr_10);
  tcase_add_test(tcase_core, test_s21_memchr_11);
  tcase_add_test(tcase_core, test_s21_memchr_12);
  tcase_add_test(tcase_core, test_s21_memchr_13);

  suite_add_tcase(suite, tcase_core);
  return suite;
}