#include "s21_test.h"

START_TEST(s21_fabs_test_1) {
  double x = -123456789.1234567895;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_2) {
  double x = S21_MAX_DOUBLE;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_3) {
  double x = S21_MIN_DOUBLE;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_4) {
  double x = 7;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_5) {
  double x = -0.7;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_6) {
  double x = -25.33;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_7) {
  double x = -0.000000000008998;
  long double result = s21_fabs(x);
  long double expected = fabs(x);
  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_8) {
  double x = -0.0;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_9) {
  double x = -123456789123.1234567895;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_10) {
  double x = -12345678910.000005;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_11) {
  double x = 321654987.00000007;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_12) {
  double x = -0.0000000000000009;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_13) {
  double x = S21_INF;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_14) {
  double x = -S21_INF;
  long double result = s21_fabs(x);
  long double expected = fabs(x);

  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_15) {
  double x = S21_NAN;
  long double result = (s21_fabs(x) == 1 ? 1 : 0);
  long double expected = (fabs(x) == 1 ? 1 : 0);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_16) {
  double x = -S21_NAN;
  long double result = (s21_fabs(x) == 1 ? 1 : 0);
  long double expected = (fabs(x) == 1 ? 1 : 0);

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_17) {
  double x = -(-120.245998);
  long double result = s21_fabs(x);
  long double expected = fabs(x);
  ck_assert_ldouble_eq(result, expected);
}
END_TEST

START_TEST(s21_fabs_test_18) { ck_assert_ldouble_infinite(s21_fabs(-S21_INF)); }
END_TEST

START_TEST(s21_fabs_test_19) { ck_assert_ldouble_infinite(s21_fabs(S21_INF)); }
END_TEST

START_TEST(s21_fabs_test_20) { ck_assert_ldouble_nan(s21_fabs(-S21_NAN)); }
END_TEST

START_TEST(s21_fabs_test_21) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(s21_fabs_test_22) { ck_assert_ldouble_infinite(s21_fabs(-S21_INF)); }
END_TEST

START_TEST(s21_fabs_test_23) { ck_assert_ldouble_infinite(s21_fabs(S21_INF)); }
END_TEST

START_TEST(s21_fabs_test_24) { ck_assert_ldouble_nan(s21_fabs(-S21_NAN)); }
END_TEST

START_TEST(s21_fabs_test_25) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

START_TEST(s21_fabs_test_26) {
  ck_assert_ldouble_eq(s21_fabs(-S21_MIN_DOUBLE), fabs(-S21_MIN_DOUBLE));
}
END_TEST

START_TEST(s21_fabs_test_27) {
  ck_assert_ldouble_eq(s21_fabs(S21_MIN_DOUBLE), fabs(S21_MIN_DOUBLE));
}
END_TEST

START_TEST(s21_fabs_test_28) {
  ck_assert_ldouble_eq(s21_fabs(-S21_MAX_DOUBLE), fabs(-S21_MAX_DOUBLE));
}
END_TEST

START_TEST(s21_fabs_test_29) {
  ck_assert_ldouble_eq(s21_fabs(S21_MAX_DOUBLE), fabs(S21_MAX_DOUBLE));
}
END_TEST

START_TEST(s21_fabs_test_30) { ck_assert_int_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST

START_TEST(s21_fabs_test_31) { ck_assert_int_eq(s21_fabs(0.0), fabs(0.0)); }
END_TEST

START_TEST(s21_fabs_test_32) { ck_assert_int_eq(s21_fabs(-1.0), fabs(-1.0)); }
END_TEST

START_TEST(s21_fabs_test_33) { ck_assert_int_eq(s21_fabs(1.0), fabs(1.0)); }
END_TEST

START_TEST(s21_fabs_test_34) {
  ck_assert_int_eq(s21_fabs(-1234.567), fabs(-1234.567));
}
END_TEST

START_TEST(s21_fabs_test_35) {
  ck_assert_int_eq(s21_fabs(1234.567), fabs(1234.567));
}
END_TEST

Suite *s21_fabs_test_suite(void) {
  Suite *suite = suite_create("s21_fabs");
  TCase *tcase_core = tcase_create("s21_fabs");
  tcase_add_test(tcase_core, s21_fabs_test_1);
  tcase_add_test(tcase_core, s21_fabs_test_2);
  tcase_add_test(tcase_core, s21_fabs_test_3);
  tcase_add_test(tcase_core, s21_fabs_test_4);
  tcase_add_test(tcase_core, s21_fabs_test_5);
  tcase_add_test(tcase_core, s21_fabs_test_6);
  tcase_add_test(tcase_core, s21_fabs_test_7);
  tcase_add_test(tcase_core, s21_fabs_test_8);
  tcase_add_test(tcase_core, s21_fabs_test_9);
  tcase_add_test(tcase_core, s21_fabs_test_10);
  tcase_add_test(tcase_core, s21_fabs_test_11);
  tcase_add_test(tcase_core, s21_fabs_test_12);
  tcase_add_test(tcase_core, s21_fabs_test_13);
  tcase_add_test(tcase_core, s21_fabs_test_14);
  tcase_add_test(tcase_core, s21_fabs_test_15);
  tcase_add_test(tcase_core, s21_fabs_test_16);
  tcase_add_test(tcase_core, s21_fabs_test_17);
  tcase_add_test(tcase_core, s21_fabs_test_18);
  tcase_add_test(tcase_core, s21_fabs_test_19);
  tcase_add_test(tcase_core, s21_fabs_test_20);
  tcase_add_test(tcase_core, s21_fabs_test_21);
  tcase_add_test(tcase_core, s21_fabs_test_22);
  tcase_add_test(tcase_core, s21_fabs_test_23);
  tcase_add_test(tcase_core, s21_fabs_test_24);
  tcase_add_test(tcase_core, s21_fabs_test_25);
  tcase_add_test(tcase_core, s21_fabs_test_26);
  tcase_add_test(tcase_core, s21_fabs_test_27);
  tcase_add_test(tcase_core, s21_fabs_test_28);
  tcase_add_test(tcase_core, s21_fabs_test_29);
  tcase_add_test(tcase_core, s21_fabs_test_30);
  tcase_add_test(tcase_core, s21_fabs_test_31);
  tcase_add_test(tcase_core, s21_fabs_test_32);
  tcase_add_test(tcase_core, s21_fabs_test_33);
  tcase_add_test(tcase_core, s21_fabs_test_34);
  tcase_add_test(tcase_core, s21_fabs_test_35);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
