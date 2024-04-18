#include "s21_test.h"

START_TEST(s21_abs_test_1) {
  int x = 0;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_2) {
  int x = S21_MAX_INT;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_3) {
  int x = S21_MIN_INT;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_4) {
  int x = 7;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_5) {
  int x = -0;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_6) {
  int x = -56854;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_7) {
  int x = 123456789;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_8) {
  int x = -32165498;
  int result = s21_abs(x);
  int expected = abs(x);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_abs_test_9) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(s21_abs_test_10) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(s21_abs_test_11) {
  ck_assert_int_eq(s21_abs(S21_MIN_INT), abs((int)S21_MIN_INT));
}
END_TEST

START_TEST(s21_abs_test_12) {
  ck_assert_int_eq(s21_abs(S21_MAX_INT), abs(S21_MAX_INT));
}
END_TEST

START_TEST(s21_abs_test_13) {
  ck_assert_int_eq(s21_abs(-666666), abs(-666666));
}
END_TEST

START_TEST(s21_abs_test_14) { ck_assert_int_eq(s21_abs(1234), abs(1234)); }
END_TEST

Suite *s21_abs_test_suite(void) {
  Suite *suite = suite_create("s21_abs");
  TCase *tcase_core = tcase_create("s21_abs");
  tcase_add_test(tcase_core, s21_abs_test_1);
  tcase_add_test(tcase_core, s21_abs_test_2);
  tcase_add_test(tcase_core, s21_abs_test_3);
  tcase_add_test(tcase_core, s21_abs_test_4);
  tcase_add_test(tcase_core, s21_abs_test_5);
  tcase_add_test(tcase_core, s21_abs_test_6);
  tcase_add_test(tcase_core, s21_abs_test_7);
  tcase_add_test(tcase_core, s21_abs_test_8);
  tcase_add_test(tcase_core, s21_abs_test_9);
  tcase_add_test(tcase_core, s21_abs_test_10);
  tcase_add_test(tcase_core, s21_abs_test_11);
  tcase_add_test(tcase_core, s21_abs_test_12);
  tcase_add_test(tcase_core, s21_abs_test_13);
  tcase_add_test(tcase_core, s21_abs_test_14);

  suite_add_tcase(suite, tcase_core);
  return suite;
}