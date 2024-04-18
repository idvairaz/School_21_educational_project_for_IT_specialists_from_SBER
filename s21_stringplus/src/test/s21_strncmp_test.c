#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strncmp_1) {
  const char* str1 = "abcd\0";
  const char* str2 = "abcd\0";
  s21_size_t n = sizeof(str1);
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  const char* str1 = "acd\0";
  const char* str2 = "hcd\0";
  s21_size_t n = 1;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  const char* str1 = "bcd\0";
  const char* str2 = "abcd\0";
  s21_size_t n = 4;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  const char* str1 = "abcd\0ee\0";
  const char* str2 = "abcd\0ef\0";
  s21_size_t n = 100;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  const char* str1 = "abcd\0ee\0";
  const char* str2 = "abcd\0ee\0";
  s21_size_t n = 100;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  const char* s1 = "abcd\0ee\0";
  const char* s2 = "b\0";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  s21_size_t n = 100;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  const char* s1 = "b\0";
  const char* s2 = "abcd\0ee\0";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  s21_size_t n = 100;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  const char* s1 = "abcdee\0";
  const char* s2 = "abcdee\0";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  s21_size_t n = 6;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  const char* s1 = "floppa";
  const char* s2 = "";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  s21_size_t n = 0;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  const char* s1 = "floppa";
  const char* s2 = "";
  s21_size_t len1 = strlen(s1);
  s21_size_t len2 = strlen(s2);
  char* str1 = (char*)calloc((len1 + 1), sizeof(char));
  char* str2 = (char*)calloc((len2 + 1), sizeof(char));
  memcpy(str1, s1, len1);
  memcpy(str2, s2, len2);
  s21_size_t n = 0;
  int expected = strncmp(str1, str2, n);
  if (expected > 0) {
    expected = 1;
  } else if (expected < 0) {
    expected = -1;
  } else {
    expected = 0;
  }
  int result = s21_strncmp(str1, str2, n);
  if (result > 0) {
    result = 1;
  } else if (result < 0) {
    result = -1;
  } else {
    result = 0;
  }
  ck_assert_int_eq(result, expected);
  free(str1);
  free(str2);
}
END_TEST

Suite* s21_strncmp_suite(void) {
  Suite* suite = suite_create("s21_strncmp");
  TCase* tcase_core = tcase_create("s21_strncmp");
  tcase_add_test(tcase_core, test_s21_strncmp_1);
  tcase_add_test(tcase_core, test_s21_strncmp_2);
  tcase_add_test(tcase_core, test_s21_strncmp_3);
  tcase_add_test(tcase_core, test_s21_strncmp_4);
  tcase_add_test(tcase_core, test_s21_strncmp_5);
  tcase_add_test(tcase_core, test_s21_strncmp_6);
  tcase_add_test(tcase_core, test_s21_strncmp_7);
  tcase_add_test(tcase_core, test_s21_strncmp_8);
  tcase_add_test(tcase_core, test_s21_strncmp_9);
  tcase_add_test(tcase_core, test_s21_strncmp_10);

  suite_add_tcase(suite, tcase_core);
  return suite;
}