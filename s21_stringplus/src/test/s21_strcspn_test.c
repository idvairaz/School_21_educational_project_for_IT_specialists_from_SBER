#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strcspn_1) {
  const char* str1 = "la\0";
  const char* str2 = "st2\0";

  s21_size_t expected = strcspn(str1, str2);
  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  const char* str1 = "last2\0";
  const char* str2 = "st2\0";

  s21_size_t expected = strcspn(str1, str2);
  s21_size_t result = s21_strcspn(str1, str2);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  const char* s1 = "lala\nla st 2\0";
  const char* s2 = "st2\0";

  int len1 = strlen(s1);
  int len2 = strlen(s2);

  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));

  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);

  s21_size_t expected = strcspn(str1, str2);
  s21_size_t result = s21_strcspn(str1, str2);

  ck_assert_int_eq(result, expected);

  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  const char* s1 = "lala\nla st 2\0";
  const char* s2 = "\0";

  int len1 = strlen(s1);
  int len2 = strlen(s2);

  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));

  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);

  s21_size_t expected = strcspn(str1, str2);
  s21_size_t result = s21_strcspn(str1, str2);

  ck_assert_int_eq(result, expected);

  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  const char* s1 = "\0";
  const char* s2 = "st2\0";

  int len1 = strlen(s1);
  int len2 = strlen(s2);

  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));

  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);

  s21_size_t expected = strcspn(str1, str2);
  s21_size_t result = s21_strcspn(str1, str2);

  ck_assert_int_eq(result, expected);

  free(str1);
  free(str2);
}

Suite* s21_strcspn_suite(void) {
  Suite* suite = suite_create("s21_strcspn");
  TCase* tcase_core = tcase_create("s21_strcspn");
  tcase_add_test(tcase_core, test_s21_strcspn_1);
  tcase_add_test(tcase_core, test_s21_strcspn_2);
  tcase_add_test(tcase_core, test_s21_strcspn_3);
  tcase_add_test(tcase_core, test_s21_strcspn_4);
  tcase_add_test(tcase_core, test_s21_strcspn_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}