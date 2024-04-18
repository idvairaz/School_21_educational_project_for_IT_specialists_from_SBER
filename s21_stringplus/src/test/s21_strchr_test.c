#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strchr_1) {
  const char* str = "lalala\0";
  int c = 'a';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_2) {
  const char* str = "lalala\0";
  int c = 'b';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_3) {
  const char* str = "la\nlala\0";
  int c = '\n';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_4) {
  const char* str = "l\0alala\0";
  int c = 'a';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strchr_5) {
  const char* s = "llla\0";
  int len = strlen(s);
  char* str = (char*)calloc((len + 1), sizeof(char));
  memcpy(str, s, len);
  int c = 'a';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
  ck_assert_str_eq(result, expected);

  free(str);
}

START_TEST(test_s21_strchr_6) {
  const char* s = "\0";
  int len = strlen(s);
  char* str = (char*)calloc((len + 1), sizeof(char));
  memcpy(str, s, len);
  int c = 'a';
  char* expected = strchr(str, c);
  char* result = s21_strchr(str, c);
  ck_assert_ptr_eq(result, expected);
  free(str);
}

START_TEST(test_s21_strchr_7) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char* ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char* ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char* ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char* ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST
START_TEST(s21_strchr_test_8) {
  char* str1 = "I ";
  char* str2 = "am";
  char* str3 = " the ";
  char* str4 = "";
  char* str5 = "TEST";
  char* str6 = " 1235 4523 13245291 !";
  char* expected = strchr(str5, 'e');
  char* result = s21_strchr(str5, 'e');
  ck_assert_str_eq(s21_strchr(str1, 'I'), strchr(str1, 'I'));
  ck_assert_str_eq(s21_strchr(str3, ' '), strchr(str3, ' '));
  ck_assert_ptr_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
  ck_assert_str_eq(s21_strchr(str2, 'm'), strchr(str2, 'm'));
  ck_assert_str_eq(s21_strchr(str3, 'h'), strchr(str3, 'h'));
  ck_assert_ptr_eq(s21_strchr(str4, ' '), strchr(str4, ' '));
  ck_assert_ptr_eq(result, expected);
  ck_assert_str_eq(s21_strchr(str6, '9'), strchr(str6, '9'));
}
END_TEST

Suite* s21_strchr_suite(void) {
  Suite* suite = suite_create("s21_strchr");
  TCase* tcase_core = tcase_create("s21_strchr");
  tcase_add_test(tcase_core, test_s21_strchr_1);
  tcase_add_test(tcase_core, test_s21_strchr_2);
  tcase_add_test(tcase_core, test_s21_strchr_3);
  tcase_add_test(tcase_core, test_s21_strchr_4);
  tcase_add_test(tcase_core, test_s21_strchr_5);
  tcase_add_test(tcase_core, test_s21_strchr_6);
  tcase_add_test(tcase_core, test_s21_strchr_7);
  tcase_add_test(tcase_core, s21_strchr_test_8);

  suite_add_tcase(suite, tcase_core);
  return suite;
}