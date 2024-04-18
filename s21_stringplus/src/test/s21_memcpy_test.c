#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_memcpy_1) {
  const char* src = "lalalalala\0";
  char* dest1 = (char*)calloc(strlen(src) + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + 1, sizeof(char));
  s21_size_t n = strlen(src + 1);
  char* expected = memcpy(dest1, src, n);
  char* result = s21_memcpy(dest2, src, n);
  ck_assert_mem_eq(result, expected, n);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_memcpy_2) {
  const char* src = "lalala\0";
  s21_size_t n = 100;
  char* dest1 = (char*)calloc(strlen(src) + n + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + n + 1, sizeof(char));
  char* expected = memcpy(dest1, src, n);
  char* result = s21_memcpy(dest2, src, n);
  ck_assert_mem_eq(result, expected, n);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_memcpy_3) {
  const char* src = "lalala\0";
  char* dest1 = (char*)calloc(strlen(src) + 1, sizeof(char));
  char* dest2 = (char*)calloc(strlen(src) + 1, sizeof(char));
  s21_size_t n = 3;
  char* expected = memcpy(dest1, src, n);
  char* result = s21_memcpy(dest2, src, n);
  ck_assert_mem_eq(result, expected, n);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(test_s21_memcpy_4) {
  char src[] = "lalala\0";
  char dest1[] = "destdest\0";
  char dest2[] = "destdest\0";
  s21_size_t n = 5;
  char* expected = memcpy(dest1, src, n);
  char* result = s21_memcpy(dest2, src, n);
  ck_assert_mem_eq(result, expected, n);
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char src[] = "lalala\0";
  char dest1[] = "destdest\0";
  char dest2[] = "destdest\0";
  s21_size_t n = 8;
  char* expected = memcpy(dest1, src, n);
  char* result = s21_memcpy(dest2, src, n);
  ck_assert_mem_eq(result, expected, n);
}
END_TEST

Suite* s21_memcpy_suite(void) {
  Suite* suite = suite_create("s21_memcpy");
  TCase* tcase_core = tcase_create("s21_memcpy");
  tcase_add_test(tcase_core, test_s21_memcpy_1);
  tcase_add_test(tcase_core, test_s21_memcpy_2);
  tcase_add_test(tcase_core, test_s21_memcpy_3);
  tcase_add_test(tcase_core, test_s21_memcpy_4);
  tcase_add_test(tcase_core, test_s21_memcpy_5);

  suite_add_tcase(suite, tcase_core);
  return suite;
}