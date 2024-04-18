#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_memset_1) {
  char src1[] = "lalala\0";
  char src2[] = "lalala\0";
  int c = '$';
  s21_size_t n = 7;
  char* expected = memset(src1, c, n);
  char* result = s21_memset(src2, c, n);
  ck_assert_mem_eq(result, expected, n);
}
END_TEST

START_TEST(test_s21_memset_2) {
  int c = 50;
  s21_size_t n = 7;
  char* src1 = calloc(n, sizeof(char));
  char* src2 = calloc(n, sizeof(char));
  char* expected = memset(src1, c, n);
  char* result = s21_memset(src2, c, n);
  ck_assert_mem_eq(result, expected, n);
  free(src1);
  free(src2);
}
END_TEST

START_TEST(test_s21_memset_3) {
  char src1[] = "lalala\0";
  char src2[] = "lalala\0";
  int c = 'f';
  s21_size_t n = 0;
  char* expected = memset(src1, c, n);
  char* result = s21_memset(src2, c, n);
  ck_assert_mem_eq(result, expected, n);
}
END_TEST

START_TEST(test_s21_memset_4) {
  int c = 2;
  s21_size_t n = 0;
  char* src1 = calloc(1, sizeof(char));
  char* src2 = calloc(1, sizeof(char));
  char* expected = memset(src1, c, n);
  char* result = s21_memset(src2, c, n);
  ck_assert_mem_eq(result, expected, n);
  free(src1);
  free(src2);
}
END_TEST

Suite* s21_memset_suite(void) {
  Suite* suite = suite_create("s21_memset");
  TCase* tcase_core = tcase_create("s21_memset");
  tcase_add_test(tcase_core, test_s21_memset_1);
  tcase_add_test(tcase_core, test_s21_memset_2);
  tcase_add_test(tcase_core, test_s21_memset_3);
  tcase_add_test(tcase_core, test_s21_memset_4);

  suite_add_tcase(suite, tcase_core);
  return suite;
}