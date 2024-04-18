#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_insert_1) {
  const char *str = "world\0";
  const char *src = "Hello !!!!!!\0";
  s21_size_t start_index = 6;
  char *expected = "Hello world!!!!!!";
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_2) {
  const char *str = s21_NULL;
  const char *src = "Hello !!!!!!\0";
  s21_size_t start_index = 6;
  char *expected = s21_NULL;
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_3) {
  const char *str = "world\0";
  const char *src = s21_NULL;
  s21_size_t start_index = 6;
  char *expected = s21_NULL;
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_4) {
  const char *str = s21_NULL;
  const char *src = s21_NULL;
  s21_size_t start_index = 6;
  char *expected = s21_NULL;
  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, expected);
  free(result);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char src[30] = "hello, world!";
  char str[] = "hELLO, WORLD!";
  char expected[] = "hello, hELLO, WORLD!world!";
  s21_size_t start_index = 7;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char src[30] = "";
  char str[] = "";
  char *expected = s21_NULL;
  s21_size_t start_index = 7;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_7) {
  char *src = s21_NULL;
  char str[] = "";
  char *expected = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_8) {
  char src[30] = "abcdefghij";
  char str[] = "\'I WAS HERE\'";
  char expected[] = "abc\'I WAS HERE\'defghij";
  s21_size_t start_index = 3;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_9) {
  char src[30] = "hello, world!";
  char str[] = "hELLO, WORLD!";
  s21_size_t start_index = -1;
  char *expected = s21_NULL;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_10) {
  char *src = s21_NULL;
  char *str = s21_NULL;
  char *expected = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_11) {
  char src[30] = "";
  char str[] = "";
  char expected[] = "";
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_12) {
  char src[] = "wtf\0";
  char *str = s21_NULL;
  char *expected = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_13) {
  char src[] = "";
  char *str = s21_NULL;
  char *expected = s21_NULL;
  s21_size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST
START_TEST(s21_insert_1) {
  char src[] = "abc\0";
  char str[] = "def\0";
  int start_index = 3;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abcdef");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_2) {
  char src[] = "abc\0";
  char str[] = "def\0";
  int start_index = 2;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abdefc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_3) {
  char src[] = "abc\0";
  char str[] = "def\0";
  int start_index = 1;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "adefbc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_4) {
  char src[] = "abc\0";
  char str[] = "def\0";
  int start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "defabc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_5) {
  char src[] = "abcdefghijkl123456789\0";
  char str[] = "xyz\0";
  int start_index = 5;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abcdexyzfghijkl123456789\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_6) {
  char src[] = "abc\0";
  char str[] = "\0";
  int start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_7) {
  char src[] = "abc\0";
  char str[] = "";
  int start_index = 1;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_8) {
  char src[] = "abc\0";
  char str[] = "";
  int start_index = 3;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_9) {
  char src[] = "";
  char str[] = "abc\0";
  int start_index = 1;
  char *result = s21_insert(src, str, start_index);
  char *expected = s21_NULL;
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_10) {
  char src[] = "";
  char str[] = "abc\0";
  int start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "abc\0");
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_11) {
  char src[] = "";
  char str[] = "abc\0";
  int start_index = 3;
  char *result = s21_insert(src, str, start_index);
  char *expected = s21_NULL;
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_12) {
  char src[] = "";
  char str[] = "";
  int start_index = 3;
  char *result = s21_insert(src, str, start_index);
  char *expected = s21_NULL;
  ck_assert_pstr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_13) {
  char src[] = "";
  char str[] = "";
  int start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_14) {
  const char src[] = "Hello, ";
  const char str[] = "World!";
  size_t start_index = 20;
  char *result = s21_insert(src, str, start_index);
  char *expected = s21_NULL;
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST
START_TEST(test_s21_insert_15) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_insert_16) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_insert_17) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_insert_18) {
  char *src = s21_NULL;
  char *str = s21_NULL;
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_insert_19) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(test_s21_insert_20) {
  char *str = s21_NULL;
  char src[] = "Space  ";
  s21_size_t index = 6;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST
START_TEST(test_s21_insert_21) {
  const char src[] = "Hello, World!";
  const char str[] = " Beautiful";
  size_t start_index = 6;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, Beautiful World!");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_22) {
  const char src[] = "World!";
  const char str[] = "Hello, ";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, World!");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_23) {
  const char src[] = "Hello, ";
  const char str[] = "World!";
  size_t start_index = s21_strlen(src);
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello, World!");
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_24) {
  const char *src = NULL;
  const char *str = "Insert";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
  if (result) free(result);
}
END_TEST

START_TEST(test_s21_insert_25) {
  const char src[] = "Hel\0lo, ";
  const char str[] = "World!";
  size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  char *expected = s21_NULL;
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *suite = suite_create("s21_insert");
  TCase *tcase_core = tcase_create("s21_to_insert");
  tcase_add_test(tcase_core, test_s21_insert_1);
  tcase_add_test(tcase_core, test_s21_insert_2);
  tcase_add_test(tcase_core, test_s21_insert_3);
  tcase_add_test(tcase_core, test_s21_insert_4);
  tcase_add_test(tcase_core, test_s21_insert_5);
  tcase_add_test(tcase_core, test_s21_insert_6);
  tcase_add_test(tcase_core, test_s21_insert_7);
  tcase_add_test(tcase_core, test_s21_insert_8);
  tcase_add_test(tcase_core, test_s21_insert_9);
  tcase_add_test(tcase_core, test_s21_insert_10);
  tcase_add_test(tcase_core, test_s21_insert_11);
  tcase_add_test(tcase_core, test_s21_insert_12);
  tcase_add_test(tcase_core, test_s21_insert_13);

  tcase_add_test(tcase_core, s21_insert_1);
  tcase_add_test(tcase_core, s21_insert_2);
  tcase_add_test(tcase_core, s21_insert_3);
  tcase_add_test(tcase_core, s21_insert_4);
  tcase_add_test(tcase_core, s21_insert_5);
  tcase_add_test(tcase_core, s21_insert_6);
  tcase_add_test(tcase_core, s21_insert_7);
  tcase_add_test(tcase_core, s21_insert_8);
  tcase_add_test(tcase_core, s21_insert_9);
  tcase_add_test(tcase_core, s21_insert_10);
  tcase_add_test(tcase_core, s21_insert_11);
  tcase_add_test(tcase_core, s21_insert_12);
  tcase_add_test(tcase_core, s21_insert_13);

  tcase_add_test(tcase_core, test_s21_insert_14);
  tcase_add_test(tcase_core, test_s21_insert_15);
  tcase_add_test(tcase_core, test_s21_insert_16);
  tcase_add_test(tcase_core, test_s21_insert_17);
  tcase_add_test(tcase_core, test_s21_insert_18);
  tcase_add_test(tcase_core, test_s21_insert_19);
  tcase_add_test(tcase_core, test_s21_insert_20);

  tcase_add_test(tcase_core, test_s21_insert_21);
  tcase_add_test(tcase_core, test_s21_insert_22);
  tcase_add_test(tcase_core, test_s21_insert_23);
  tcase_add_test(tcase_core, test_s21_insert_24);
  tcase_add_test(tcase_core, test_s21_insert_25);

  suite_add_tcase(suite, tcase_core);
  return suite;
}