#include "s21_test.h"

START_TEST(s21_exp_test_1) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 0.000001);
}

START_TEST(s21_exp_test_2) {
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 0.000001);
}

START_TEST(s21_exp_test_3) {
  ck_assert_ldouble_eq_tol(s21_exp(2), exp(2), 0.000001);
}
START_TEST(s21_exp_test_4) {
  ck_assert_ldouble_eq_tol(s21_exp(2), exp(2), 0.000001);
}
START_TEST(s21_exp_test_5) {
  ck_assert_ldouble_eq_tol(s21_exp(-2), exp(-2), 0.000001);
}
START_TEST(s21_exp_test_6) {
  long double x = exp(144);
  long double s21_x = s21_exp(144);
  char x_str[100];
  char s21_x_str[100];
  int y = 16;
  if (x > 9999999999999999.0) y = 6;
  sprintf(s21_x_str, "%.*Le", y, s21_x);
  sprintf(x_str, "%.*Le", y, x);
  ck_assert_str_eq(x_str, s21_x_str);
}
START_TEST(s21_exp_test_7) {
  long double x = exp(144);
  long double s21_x = s21_exp(144);
  int exp = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp < 7) exp = 7;
  for (int i = 0; i < 15 && exp; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp--;
  }
}

START_TEST(s21_exp_test_8) {
  char a[100];
  char b[100];
  sprintf(a, "%.15e", (double)s21_exp(-144));
  sprintf(b, "%.15e", exp(-144));
  ck_assert_str_eq(a, b);
}

START_TEST(s21_exp_test_9) {
  long double x = exp(-543.0);
  long double s21_x = s21_exp(-543.0);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}
START_TEST(s21_exp_test_10) {
  long double x = exp(1e-13);
  long double s21_x = s21_exp(1e-13);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_11) {
  long double x = exp(0.0450000000001);
  long double s21_x = s21_exp(0.0450000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_12) {
  long double x = exp(0.0880000000001);
  long double s21_x = s21_exp(0.0880000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_13) {
  long double x = exp(0.13100000000009998);
  long double s21_x = s21_exp(0.13100000000009998);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_14) {
  long double x = exp(0.1730000000001);
  long double s21_x = s21_exp(0.1730000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_15) {
  long double x = exp(0.2160000000001);
  long double s21_x = s21_exp(0.2160000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_16) {
  long double x = exp(0.2610000000001);
  long double s21_x = s21_exp(0.2610000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_17) {
  long double x = exp(0.30400000000009997);
  long double s21_x = s21_exp(0.30400000000009997);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_18) {
  long double x = exp(0.35100000000009995);
  long double s21_x = s21_exp(0.35100000000009995);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_19) {
  long double x = exp(0.39600000000009994);
  long double s21_x = s21_exp(0.39600000000009994);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_20) {
  long double x = exp(0.4420000000000999);
  long double s21_x = s21_exp(0.4420000000000999);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_21) {
  long double x = exp(0.4820000000000999);
  long double s21_x = s21_exp(0.4820000000000999);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_22) {
  long double x = exp(0.5250000000000999);
  long double s21_x = s21_exp(0.5250000000000999);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_23) {
  long double x = exp(0.5720000000001);
  long double s21_x = s21_exp(0.5720000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_24) {
  long double x = exp(0.6150000000001);
  long double s21_x = s21_exp(0.6150000000001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_25) {
  long double x = exp(0.6570000000001001);
  long double s21_x = s21_exp(0.6570000000001001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_26) {
  long double x = exp(0.7070000000001001);
  long double s21_x = s21_exp(0.7070000000001001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_27) {
  long double x = exp(0.7540000000001001);
  long double s21_x = s21_exp(0.7540000000001001);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_28) {
  long double x = exp(0.7960000000001002);
  long double s21_x = s21_exp(0.7960000000001002);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_29) {
  long double x = exp(0.8420000000001002);
  long double s21_x = s21_exp(0.8420000000001002);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_30) {
  long double x = exp(0.8840000000001003);
  long double s21_x = s21_exp(0.8840000000001003);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_31) {
  long double x = exp(0.9280000000001003);
  long double s21_x = s21_exp(0.9280000000001003);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_32) {
  long double x = exp(0.9770000000001003);
  long double s21_x = s21_exp(0.9770000000001003);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_33) {
  long double x = exp(3.005);
  long double s21_x = s21_exp(3.005);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_34) {
  long double x = exp(3.0260349999999994);
  long double s21_x = s21_exp(3.0260349999999994);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_35) {
  long double x = exp(15.145305174999997);
  long double s21_x = s21_exp(15.145305174999997);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_exp_test_36) {
  long double x = exp(75.86283362157499);
  long double s21_x = s21_exp(75.86283362157499);
  char x_str[100];
  char s21_x_str[100];
  int y = 16;
  if (x > 9999999999999999.0) y = 6;
  sprintf(s21_x_str, "%.*Le", y, s21_x);
  sprintf(x_str, "%.*Le", y, x);
  ck_assert_str_eq(s21_x_str, x_str);
}

START_TEST(s21_exp_test_37) {
  long double x = exp(227.74);
  long double s21_x = s21_exp(227.74);
  int exp = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp < 7) exp = 7;
  for (int i = 0; i < 15 && exp; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp--;
  }
}

START_TEST(s21_exp_test_38) {
  for (double i = -14.0; i < 10; i += 0.1) {
    ck_assert_ldouble_eq_tol(s21_exp(0.0 + i), exp(0.0 + i), EPSILON);
  }
}
END_TEST

START_TEST(s21_exp_test_39) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST

START_TEST(s21_exp_test_40) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), EPSILON);
}
END_TEST

START_TEST(s21_exp_test_41) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test_42) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(s21_exp_test_43) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test_44) {
  ck_assert_double_eq_tol(s21_exp(0), exp(0), EPSILON);
}
END_TEST

START_TEST(s21_exp_test_45) {
  ck_assert_double_eq_tol(s21_exp(1), exp(1), EPSILON);
}
END_TEST

START_TEST(s21_exp_test_46) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), EPSILON);
}
END_TEST

START_TEST(s21_exp_test_47) {
  double num = 0.5 * s21_log(853321.123);

  ck_assert_double_eq_tol(s21_exp(num), exp(num), EPSILON);
}
END_TEST

START_TEST(s21_exp_test_48) {
  double num = 1234567.0;
  ck_assert_msg(S21_IS_INF(s21_exp(num)) == 1, "func return value failed");
}
END_TEST

START_TEST(s21_exp_test_49) {
  double num = 0.000000000000012345;
  ck_assert_double_eq_tol(s21_exp(num), exp(num), EPSILON);
}
END_TEST

Suite *s21_exp_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_exp_test_suite");
  tc = tcase_create("s21_exp_test_case");

  tcase_add_test(tc, s21_exp_test_1);
  tcase_add_test(tc, s21_exp_test_2);
  tcase_add_test(tc, s21_exp_test_3);
  tcase_add_test(tc, s21_exp_test_4);
  tcase_add_test(tc, s21_exp_test_5);
  tcase_add_test(tc, s21_exp_test_6);
  tcase_add_test(tc, s21_exp_test_7);
  tcase_add_test(tc, s21_exp_test_8);
  tcase_add_test(tc, s21_exp_test_9);
  tcase_add_test(tc, s21_exp_test_10);
  tcase_add_test(tc, s21_exp_test_11);
  tcase_add_test(tc, s21_exp_test_12);
  tcase_add_test(tc, s21_exp_test_13);
  tcase_add_test(tc, s21_exp_test_14);
  tcase_add_test(tc, s21_exp_test_15);
  tcase_add_test(tc, s21_exp_test_16);
  tcase_add_test(tc, s21_exp_test_17);
  tcase_add_test(tc, s21_exp_test_18);
  tcase_add_test(tc, s21_exp_test_19);
  tcase_add_test(tc, s21_exp_test_20);
  tcase_add_test(tc, s21_exp_test_21);
  tcase_add_test(tc, s21_exp_test_22);
  tcase_add_test(tc, s21_exp_test_23);
  tcase_add_test(tc, s21_exp_test_24);
  tcase_add_test(tc, s21_exp_test_25);
  tcase_add_test(tc, s21_exp_test_26);
  tcase_add_test(tc, s21_exp_test_27);
  tcase_add_test(tc, s21_exp_test_28);
  tcase_add_test(tc, s21_exp_test_29);
  tcase_add_test(tc, s21_exp_test_30);
  tcase_add_test(tc, s21_exp_test_31);
  tcase_add_test(tc, s21_exp_test_32);
  tcase_add_test(tc, s21_exp_test_33);
  tcase_add_test(tc, s21_exp_test_34);
  tcase_add_test(tc, s21_exp_test_35);
  tcase_add_test(tc, s21_exp_test_36);
  tcase_add_test(tc, s21_exp_test_37);
  tcase_add_test(tc, s21_exp_test_38);
  tcase_add_test(tc, s21_exp_test_39);
  tcase_add_test(tc, s21_exp_test_40);
  tcase_add_test(tc, s21_exp_test_41);
  tcase_add_test(tc, s21_exp_test_42);
  tcase_add_test(tc, s21_exp_test_43);
  tcase_add_test(tc, s21_exp_test_44);
  tcase_add_test(tc, s21_exp_test_45);
  tcase_add_test(tc, s21_exp_test_46);
  tcase_add_test(tc, s21_exp_test_47);
  tcase_add_test(tc, s21_exp_test_48);
  tcase_add_test(tc, s21_exp_test_49);

  suite_add_tcase(s, tc);
  return s;
}