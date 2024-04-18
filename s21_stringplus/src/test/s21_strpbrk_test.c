#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strpbrk_1) {
  const char *str1 = "Hell World\0Xd\0Y";
  const char *str2 = "Privetd\0X";
  char *expected = (char *)strpbrk(str1, str2);
  char *result = (char *)s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  const char *str1 = "Hell World\0Xd\0Y";
  const char *str2 = "stp\0";
  char *expected = (char *)strpbrk(str1, str2);
  char *result = (char *)s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  const char *s1 = "Hell World\0Xd\0Y";
  const char *s2 = "X\0";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char *str1 = (char *)calloc((len1 + 1), sizeof(char));
  char *str2 = (char *)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  char *expected = (char *)strpbrk(str1, str2);
  char *result = (char *)s21_strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *suite = suite_create("s21_strpbrk");
  TCase *tcase_core = tcase_create("s21_strpbrk");
  tcase_add_test(tcase_core, test_s21_strpbrk_1);
  tcase_add_test(tcase_core, test_s21_strpbrk_2);
  tcase_add_test(tcase_core, test_s21_strpbrk_3);

  suite_add_tcase(suite, tcase_core);
  return suite;
}