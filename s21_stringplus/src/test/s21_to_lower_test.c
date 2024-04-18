#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_to_lower_1) {
  const char *str = "GfGyUjO2+0hF\0";
  char *expected = "gfgyujo2+0hf\0";
  char *result = (char *)s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_2) {
  const char *str = s21_NULL;
  char *expected = s21_NULL;
  char *result = (char *)s21_to_lower(str);
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_3) {
  const char *str = "\0";
  char *expected = "\0";
  char *result = (char *)s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_to_lower_4) {
  const char *str = "LLaa 12 + 12 = 24\t LLaa\0";
  char *expected = "llaa 12 + 12 = 24\t llaa\0";
  char *result = (char *)s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase_core = tcase_create("s21_to_lower");
  tcase_add_test(tcase_core, test_s21_to_lower_1);
  tcase_add_test(tcase_core, test_s21_to_lower_2);
  tcase_add_test(tcase_core, test_s21_to_lower_3);
  tcase_add_test(tcase_core, test_s21_to_lower_4);

  suite_add_tcase(suite, tcase_core);
  return suite;
}