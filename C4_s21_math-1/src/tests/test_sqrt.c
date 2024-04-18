#include "s21_test.h"

START_TEST(s21_sqrt_test_1) {
  ck_assert_double_eq_tol(s21_sqrt(0.0), 0.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(1.0), 1.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(4.0), 2.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(9.0), 3.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(16.0), 4.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(25.0), 5.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(36.0), 6.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(49.0), 7.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(64.0), 8.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(81.0), 9.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(100.0), 10.0, 0.000001);
  ck_assert_double_eq_tol(s21_sqrt(121.0), 11.0, 0.000001);
  ck_assert_ldouble_nan(s21_sqrt(-1.0));
}
START_TEST(s21_sqrt_test_2) {
  double x = 2;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_3) {
  double x = 3;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_4) {
  double x = 3;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_5) {
  double x = 6;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_6) {
  double x = 24;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_7) {
  double x = 168;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_8) {
  double x = 336;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_9) {
  double x = 1008;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_10) {
  double x = 8064;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_11) {
  double x = 8064;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_12) {
  double x = 48384;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_13) {
  double x = 96768;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_14) {
  double x = 96768;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_15) {
  double x = 96768;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_16) {
  double x = 1e-08;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_17) {
  double x = 1e-08;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_18) {
  double x = 9e-08;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_19) {
  double x = 6.3e-07;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_20) {
  double x = 6.3e-07;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_21) {
  double x = 1.26e-06;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_22) {
  double x = 3.7800000000000002e-06;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_23) {
  double x = 3.0240000000000002e-05;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_24) {
  double x = 0.00024192000000000001;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_25) {
  double x = 0.00145152;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_26) {
  double x = 0.01306368;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_27) {
  double x = 0.09144576;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_28) {
  double x = 0.64012032;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}
START_TEST(s21_sqrt_test_29) {
  double x = 2;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_30) {
  double x = 6.162;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_31) {
  double x = 12.367134;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_32) {
  double x = 24.882673608;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_33) {
  double x = 25.031969649648;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_34) {
  double x = 25.28228934614448;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_35) {
  double x = 76.0491263532026;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_36) {
  double x = 229.5162633339654;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_37) {
  double x = 463.1638194079421;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_38) {
  double x = 928.643457912924;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_39) {
  double x = 1890.7180803107133;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_40) {
  double x = 5740.220091823326;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_41) {
  double x = 5877.9853740270855;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_42) {
  double x = 17686.8579904475;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_43) {
  double x = 53856.48258091264;
  ck_assert_double_eq_tol(s21_sqrt(x), sqrt(x), 0.000001);
}

START_TEST(s21_sqrt_test_44) {
  double x = NAN;
  ck_assert_ldouble_nan(s21_sqrt(x));
}

START_TEST(s21_sqrt_test_45) {
  double x = INFINITY;
  ck_assert_msg(S21_IS_INF(s21_sqrt(x)) == 1, "func return value failed");
}

START_TEST(s21_sqrt_test_46) {
  double x = -INFINITY;
  ck_assert_ldouble_nan(s21_sqrt(x));
}

START_TEST(s21_sqrt_test_47) {
  long double x = sqrt(S21_MAX_DOUBLE);
  long double s21_x = s21_sqrt(S21_MAX_DOUBLE);
  int exp = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp < 7) exp = 7;
  for (int i = 0; i < 14 && exp; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp--;
  }
}

START_TEST(s21_sqrt_test_48) {
  long double x = sqrt(129874612961282141.0);
  long double s21_x = s21_sqrt(129874612961282141.0);
  int exp = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp < 7) exp = 7;
  for (int i = 0; i < 17 && exp; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp--;
  }
}

Suite *s21_sqrt_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sqrt_test_suite");
  tc = tcase_create("s21_sqrt_test_suite");
  tcase_add_test(tc, s21_sqrt_test_1);
  tcase_add_test(tc, s21_sqrt_test_2);
  tcase_add_test(tc, s21_sqrt_test_3);
  tcase_add_test(tc, s21_sqrt_test_4);
  tcase_add_test(tc, s21_sqrt_test_5);
  tcase_add_test(tc, s21_sqrt_test_6);
  tcase_add_test(tc, s21_sqrt_test_7);
  tcase_add_test(tc, s21_sqrt_test_8);
  tcase_add_test(tc, s21_sqrt_test_9);
  tcase_add_test(tc, s21_sqrt_test_10);
  tcase_add_test(tc, s21_sqrt_test_11);
  tcase_add_test(tc, s21_sqrt_test_12);
  tcase_add_test(tc, s21_sqrt_test_13);
  tcase_add_test(tc, s21_sqrt_test_14);
  tcase_add_test(tc, s21_sqrt_test_15);
  tcase_add_test(tc, s21_sqrt_test_16);
  tcase_add_test(tc, s21_sqrt_test_17);
  tcase_add_test(tc, s21_sqrt_test_18);
  tcase_add_test(tc, s21_sqrt_test_19);
  tcase_add_test(tc, s21_sqrt_test_20);
  tcase_add_test(tc, s21_sqrt_test_21);
  tcase_add_test(tc, s21_sqrt_test_22);
  tcase_add_test(tc, s21_sqrt_test_23);
  tcase_add_test(tc, s21_sqrt_test_24);
  tcase_add_test(tc, s21_sqrt_test_25);
  tcase_add_test(tc, s21_sqrt_test_26);
  tcase_add_test(tc, s21_sqrt_test_27);
  tcase_add_test(tc, s21_sqrt_test_28);
  tcase_add_test(tc, s21_sqrt_test_29);
  tcase_add_test(tc, s21_sqrt_test_30);
  tcase_add_test(tc, s21_sqrt_test_31);
  tcase_add_test(tc, s21_sqrt_test_32);
  tcase_add_test(tc, s21_sqrt_test_33);
  tcase_add_test(tc, s21_sqrt_test_34);
  tcase_add_test(tc, s21_sqrt_test_35);
  tcase_add_test(tc, s21_sqrt_test_36);
  tcase_add_test(tc, s21_sqrt_test_37);
  tcase_add_test(tc, s21_sqrt_test_38);
  tcase_add_test(tc, s21_sqrt_test_39);
  tcase_add_test(tc, s21_sqrt_test_40);
  tcase_add_test(tc, s21_sqrt_test_41);
  tcase_add_test(tc, s21_sqrt_test_42);
  tcase_add_test(tc, s21_sqrt_test_43);
  tcase_add_test(tc, s21_sqrt_test_44);
  tcase_add_test(tc, s21_sqrt_test_45);
  tcase_add_test(tc, s21_sqrt_test_46);
  tcase_add_test(tc, s21_sqrt_test_47);
  tcase_add_test(tc, s21_sqrt_test_48);

  suite_add_tcase(s, tc);
  return s;
}