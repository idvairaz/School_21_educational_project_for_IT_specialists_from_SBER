#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strlen_1) {
  const char* str = "lalala\0";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_2) {
  const char* str = "";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_3) {
  const char* str = "lala\0  la\0";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_4) {
  const char* str = "* + lala =  \n la =\0";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_5) {
  const char* str = "0123456789\0";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_6) {
  const char* str = "\0";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strlen_7) {
  const char* str = "\n";
  s21_size_t expected = strlen(str);
  s21_size_t result = s21_strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

Suite* s21_strlen_suite(void) {
  Suite* suite = suite_create("s21_strlen");
  TCase* tcase_core = tcase_create("s21_strlen");
  tcase_add_test(tcase_core, test_s21_strlen_1);
  tcase_add_test(tcase_core, test_s21_strlen_2);
  tcase_add_test(tcase_core, test_s21_strlen_3);
  tcase_add_test(tcase_core, test_s21_strlen_4);
  tcase_add_test(tcase_core, test_s21_strlen_5);
  tcase_add_test(tcase_core, test_s21_strlen_6);
  tcase_add_test(tcase_core, test_s21_strlen_7);

  suite_add_tcase(suite, tcase_core);
  return suite;
}