#include "../s21_string.h"
#include "test.h"

START_TEST(test_s21_strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char s[] = "Hello, world!";
  int ch = '\n';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_ptr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *suite = suite_create("s21_strrchr");
  TCase *tcase_core = tcase_create("s21_strrchr");

  suite_add_tcase(suite, tcase_core);
  tcase_add_test(tcase_core, test_s21_strrchr_1);
  tcase_add_test(tcase_core, test_s21_strrchr_2);
  tcase_add_test(tcase_core, test_s21_strrchr_3);
  tcase_add_test(tcase_core, test_s21_strrchr_4);
  tcase_add_test(tcase_core, test_s21_strrchr_5);
  tcase_add_test(tcase_core, test_s21_strrchr_6);
  tcase_add_test(tcase_core, test_s21_strrchr_7);
  tcase_add_test(tcase_core, test_s21_strrchr_8);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
