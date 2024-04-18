#include "s21_test.h"

START_TEST(s21_pow_test_1) {
  ck_assert_double_eq_tol(s21_pow(2, 3), pow(2, 3), 0.000001);
}
START_TEST(s21_pow_test_2) {
  ck_assert_double_eq_tol(s21_pow(-2, 3), pow(-2, 3), 0.000001);
}
START_TEST(s21_pow_test_3) {
  ck_assert_double_eq_tol(s21_pow(2, -3), pow(2, -3), 0.000001);
}

START_TEST(s21_pow_test_4) {
  ck_assert_ldouble_eq_tol(s21_pow(9, 0.5), pow(9, 0.5), 0.000001);
}
START_TEST(s21_pow_test_5) {
  ck_assert_ldouble_eq_tol(s21_pow(9, 0.3), pow(9, 0.3), 0.000001);
}
START_TEST(s21_pow_test_6) {
  ck_assert_ldouble_eq_tol(s21_pow(9, 0), pow(9, 0), 0.000001);
}
START_TEST(s21_pow_test_7) { ck_assert_ldouble_nan(s21_pow(-2, 3.3)); }

START_TEST(s21_pow_test_8) {
  long double x = pow(0.5, 0.5);
  long double s21_x = s21_pow(0.5, 0.5);

  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_pow_test_9) {
  long double x = pow(1, 1);
  long double s21_x = s21_pow(1, 1);
  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_pow_test_10) {
  long double x = pow(1902.008, 2);
  long double s21_x = s21_pow(1902.008, 2);
  ck_assert_ldouble_eq_tol(s21_x, x, 0.000001);
}

START_TEST(s21_pow_test_11) {
  long double x = pow(3809.01, 3);
  long double s21_x = s21_pow(3809.01, 3);
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

START_TEST(s21_pow_test_12) {
  long double x = pow(5709.012000000001, 4);
  long double s21_x = s21_pow(5709.012000000001, 4);
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

START_TEST(s21_pow_test_13) {
  long double x = pow(7612.016, 5);
  long double s21_x = s21_pow(7612.016, 5);
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

START_TEST(s21_pow_test_14) {
  long double x = pow(9520.024000000001, 6);
  long double s21_x = s21_pow(9520.024000000001, 6);
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

START_TEST(s21_pow_test_15) {
  long double x = pow(11422.029000000002, 7);
  long double s21_x = s21_pow(11422.029000000002, 7);
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

START_TEST(s21_pow_test_16) {
  long double x = pow(13322.031000000003, 8);
  long double s21_x = s21_pow(13322.031000000003, 8);
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

START_TEST(s21_pow_test_17) {
  long double x = pow(15225.038000000002, 9);
  long double s21_x = s21_pow(15225.038000000002, 9);
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

START_TEST(s21_pow_test_18) {
  long double x = pow(17127.04, 10);
  long double s21_x = s21_pow(17127.04, 10);
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

START_TEST(s21_pow_test_19) {
  long double x = pow(19034.044, 11);
  long double s21_x = s21_pow(19034.044, 11);
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

START_TEST(s21_pow_test_20) {
  long double x = pow(20937.049000000003, 12);
  long double s21_x = s21_pow(20937.049000000003, 12);
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

START_TEST(s21_pow_test_21) {
  long double x = pow(22844.054000000004, 13);
  long double s21_x = s21_pow(22844.054000000004, 13);
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

START_TEST(s21_pow_test_22) {
  long double x = pow(24751.057000000004, 14);
  long double s21_x = s21_pow(24751.057000000004, 14);
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

START_TEST(s21_pow_test_23) {
  long double x = pow(26656.062000000005, 15);
  long double s21_x = s21_pow(26656.062000000005, 15);
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

START_TEST(s21_pow_test_24) {
  long double x = pow(28561.070000000007, 16);
  long double s21_x = s21_pow(28561.070000000007, 16);
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

START_TEST(s21_pow_test_25) {
  long double x = pow(30465.073, 17);
  long double s21_x = s21_pow(30465.073, 17);
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

START_TEST(s21_pow_test_26) {
  long double x = pow(32373.07900000001, 18);
  long double s21_x = s21_pow(32373.07900000001, 18);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%Le", s21_x);
  sprintf(x_str, "%Le", x);
  ck_assert_str_eq(x_str, s21_x_str);
}

START_TEST(s21_pow_test_27) {
  long double x = pow(34280.08800000001, 19);
  long double s21_x = s21_pow(34280.08800000001, 19);
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

START_TEST(s21_pow_test_28) {
  long double x = pow(36180.09600000001, 20);
  long double s21_x = s21_pow(36180.09600000001, 20);
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

START_TEST(s21_pow_test_29) {
  long double x = pow(38084.10300000001, 21);
  long double s21_x = s21_pow(38084.10300000001, 21);
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

START_TEST(s21_pow_test_30) {
  long double x = pow(39989.11000000001, 22);
  long double s21_x = s21_pow(39989.11000000001, 22);
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

START_TEST(s21_pow_test_31) {
  long double x = pow(41893.113000000005, 23);
  long double s21_x = s21_pow(41893.113000000005, 23);
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

START_TEST(s21_pow_test_32) {
  long double x = pow(43795.119000000006, 24);
  long double s21_x = s21_pow(43795.119000000006, 24);
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

START_TEST(s21_pow_test_33) {
  long double x = pow(45701.12500000001, 25);
  long double s21_x = s21_pow(45701.12500000001, 25);
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

START_TEST(s21_pow_test_34) {
  long double x = pow(47609.132000000005, 26);
  long double s21_x = s21_pow(47609.132000000005, 26);
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

START_TEST(s21_pow_test_35) {
  long double x = pow(49512.134000000005, 27);
  long double s21_x = s21_pow(49512.134000000005, 27);
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

START_TEST(s21_pow_test_36) {
  long double x = pow(51419, 28);
  long double s21_x = s21_pow(51419, 28);
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

START_TEST(s21_pow_test_37) {
  long double x = pow(53323.146, 29);
  long double s21_x = s21_pow(53323.146, 29);
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

START_TEST(s21_pow_test_38) {
  long double x = pow(55229.148, 30);
  long double s21_x = s21_pow(55229.148, 30);
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

START_TEST(s21_pow_test_39) {
  long double x = pow(57134, 31);
  long double s21_x = s21_pow(57134, 31);
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

START_TEST(s21_pow_test_40) {
  long double x = pow(59038.159999999996, 32);
  long double s21_x = s21_pow(59038.159999999996, 32);
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

START_TEST(s21_pow_test_41) {
  long double x = pow(60946.16499999999, 33);
  long double s21_x = s21_pow(60946.16499999999, 33);
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

START_TEST(s21_pow_test_42) {
  long double x = pow(62855.168999999994, 34);
  long double s21_x = s21_pow(62855.168999999994, 34);
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

START_TEST(s21_pow_test_43) {
  long double x = pow(64755.17599999999, 35);
  long double s21_x = s21_pow(64755.17599999999, 35);
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

START_TEST(s21_pow_test_44) {
  long double x = pow(66660.184, 36);
  long double s21_x = s21_pow(66660.184, 36);
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

START_TEST(s21_pow_test_45) {
  long double x = pow(68567.18699999999, 37);
  long double s21_x = s21_pow(68567.18699999999, 37);
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

START_TEST(s21_pow_test_46) {
  long double x = pow(70469.1, 38);
  long double s21_x = s21_pow(70469.1, 38);
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

START_TEST(s21_pow_test_47) {
  long double x = pow(72374.19799999999, 39);
  long double s21_x = s21_pow(72374.19799999999, 39);
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

START_TEST(s21_pow_test_48) {
  long double x = pow(74280.19, 40);
  long double s21_x = s21_pow(74280.19, 40);
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

START_TEST(s21_pow_test_49) {
  long double x = pow(76184.20599999998, 41);
  long double s21_x = s21_pow(76184.20599999998, 41);
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

START_TEST(s21_pow_test_50) {
  long double x = pow(78086.21199999997, 42);
  long double s21_x = s21_pow(78086.21199999997, 42);
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

START_TEST(s21_pow_test_51) {
  long double x = pow(79994.21799999996, 43);
  long double s21_x = s21_pow(79994.21799999996, 43);
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

START_TEST(s21_pow_test_52) {
  long double x = pow(81899.22099999996, 44);
  long double s21_x = s21_pow(81899.22099999996, 44);
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

START_TEST(s21_pow_test_53) {
  long double x = pow(83806.22399999996, 45);
  long double s21_x = s21_pow(83806.22399999996, 45);
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

START_TEST(s21_pow_test_54) {
  long double x = pow(85714.23299999996, 46);
  long double s21_x = s21_pow(85714.23299999996, 46);
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

START_TEST(s21_pow_test_55) {
  long double x = pow(87614.23599999996, 47);
  long double s21_x = s21_pow(87614.23599999996, 47);
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

START_TEST(s21_pow_test_56) {
  long double x = pow(89523.23799999995, 48);
  long double s21_x = s21_pow(89523.23799999995, 48);
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

START_TEST(s21_pow_test_57) {
  long double x = pow(91431.23999999995, 49);
  long double s21_x = s21_pow(91431.23999999995, 49);
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

START_TEST(s21_pow_test_58) {
  long double x = pow(93335.24399999995, 50);
  long double s21_x = s21_pow(93335.24399999995, 50);
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

START_TEST(s21_pow_test_59) {
  long double x = pow(95240.25199999995, 51);
  long double s21_x = s21_pow(95240.25199999995, 51);
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

START_TEST(s21_pow_test_60) {
  long double x = pow(97143.25699999995, 52);
  long double s21_x = s21_pow(97143.25699999995, 52);
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

START_TEST(s21_pow_test_61) {
  long double x = pow(99046.26199999996, 53);
  long double s21_x = s21_pow(99046.26199999996, 53);
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

START_TEST(s21_pow_test_62) {
  long double x = pow(9999.1, 1111.0);
  long double s21_x = s21_pow(9999.1, 11111.0);
  char x_str[100];
  char s21_x_str[100];
  int y = 16;
  if (x > 9999999999999999.0) y = 6;
  sprintf(s21_x_str, "%.*Le", y, s21_x);
  sprintf(x_str, "%.*Le", y, x);
  ck_assert_str_eq(x_str, s21_x_str);
}
START_TEST(s21_pow_test_63) {}
START_TEST(s21_pow_test_64) {
  long double x = pow(9999.1, 1.2);
  long double s21_x = s21_pow(9999.1, 1.2);
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

START_TEST(s21_pow_test_65) {
  ck_assert_double_eq_tol(s21_pow(2, -55555), pow(2, -55555), 0.000001);
}
START_TEST(s21_pow_test_66) {
  ck_assert_double_eq_tol(s21_pow(1.0, 444), pow(1.0, 444), 0.000001);
}
START_TEST(s21_pow_test_67) {
  ck_assert_double_eq_tol(s21_pow(1.0, NAN), pow(1.0, NAN), 0.000001);
}
START_TEST(s21_pow_test_68) { ck_assert_ldouble_nan(s21_pow(1.0, 445)); }

START_TEST(s21_pow_test_69) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_70) {
  // 0.0
  ck_assert_double_eq(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_71) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_72) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_INF, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_73) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_74) {
  // 0.0
  ck_assert_double_eq(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_75) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_76) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_INF, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_77) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_78) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_79) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_80) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_81) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_82) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_83) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_84) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_85) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(6.5, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_86) {
  // -0.0
  ck_assert_double_eq(s21_pow(6.5, -S21_INF), pow(6.5, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_87) {
  // nan
  ck_assert_ldouble_nan(s21_pow(6.5, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_88) {
  // nan
  ck_assert_ldouble_nan(s21_pow(6.5, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_89) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 6.5));
}
END_TEST

START_TEST(s21_pow_test_90) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 6.5));
}
END_TEST

START_TEST(s21_pow_test_91) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 6.5));
}
END_TEST

START_TEST(s21_pow_test_92) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, 6.5));
}
END_TEST

START_TEST(s21_pow_test_93) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-6.5, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_94) {
  // -0.0
  ck_assert_double_eq(s21_pow(-6.5, -S21_INF), pow(-6.5, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_95) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-6.5, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_96) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-6.5, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_97) {
  // 0.0
  ck_assert_double_eq(s21_pow(S21_INF, -6.5), pow(S21_INF, -6.5));
}
END_TEST

START_TEST(s21_pow_test_98) {
  // 0.0
  ck_assert_double_eq(s21_pow(-S21_INF, -6.5), pow(-S21_INF, -6.5));
}
END_TEST

START_TEST(s21_pow_test_99) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -6.5));
}
END_TEST

START_TEST(s21_pow_test_100) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -6.5));
}
END_TEST

START_TEST(s21_pow_test_101) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(6, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_102) {
  // -0.0
  ck_assert_double_eq(s21_pow(6, -S21_INF), pow(6, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_103) {
  // nan
  ck_assert_ldouble_nan(s21_pow(6, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_104) {
  // nan
  ck_assert_ldouble_nan(s21_pow(6, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_105) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 6));
}
END_TEST

START_TEST(s21_pow_test_106) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 6));
}
END_TEST

START_TEST(s21_pow_test_107) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 6));
}
END_TEST

START_TEST(s21_pow_test_108) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, 6));
}
END_TEST

START_TEST(s21_pow_test_109) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-6, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_110) {
  // -0.0
  ck_assert_double_eq(s21_pow(-6, -S21_INF), pow(-6, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_111) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-6, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_112) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-6, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_113) {
  // 0.0
  ck_assert_double_eq(s21_pow(S21_INF, -6), pow(S21_INF, -6));
}
END_TEST

START_TEST(s21_pow_test_114) {
  // 0.0
  ck_assert_double_eq(s21_pow(-S21_INF, -6), pow(-S21_INF, -6));
}
END_TEST

START_TEST(s21_pow_test_115) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -6));
}
END_TEST

START_TEST(s21_pow_test_116) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -6));
}
END_TEST

START_TEST(s21_pow_test_117) {
  // 1.0
  ck_assert_double_eq(s21_pow(1, S21_INF), pow(1, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_118) {
  // -0.0
  ck_assert_double_eq(s21_pow(1, -S21_INF), pow(1, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_119) {
  // 1.0
  ck_assert_double_eq(s21_pow(1, S21_NAN), pow(1, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_120) {
  // 1.0
  ck_assert_double_eq(s21_pow(1, -S21_NAN), pow(1, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_121) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 1));
}
END_TEST

START_TEST(s21_pow_test_122) {
  // inf
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 1));
}
END_TEST

START_TEST(s21_pow_test_123) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, 1));
}
END_TEST

START_TEST(s21_pow_test_124) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, 1));
}
END_TEST

START_TEST(s21_pow_test_125) {
  // 1.0
  ck_assert_double_eq(s21_pow(-1, S21_INF), pow(-1, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_126) {
  // -0.0
  ck_assert_double_eq(s21_pow(-1, -S21_INF), pow(-1, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_127) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-1, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_128) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-1, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_129) {
  // 0.0
  ck_assert_double_eq(s21_pow(S21_INF, -1), pow(S21_INF, -1));
}
END_TEST

START_TEST(s21_pow_test_130) {
  // 0.0
  ck_assert_double_eq(s21_pow(-S21_INF, -1), pow(-S21_INF, -1));
}
END_TEST

START_TEST(s21_pow_test_131) {
  // nan
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -1));
}
END_TEST

START_TEST(s21_pow_test_132) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-S21_NAN, -1));
}
END_TEST

START_TEST(s21_pow_test_133) {
  // 0.0
  ck_assert_double_eq(s21_pow(0, S21_INF), pow(0, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_134) {
  // -0.0
  ck_assert_double_eq(s21_pow(0, -S21_INF), pow(0, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_135) {
  // nan
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_136) {
  // nan
  ck_assert_ldouble_nan(s21_pow(0, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_137) {
  // 1.0
  ck_assert_double_eq(s21_pow(S21_INF, 0), pow(S21_INF, 0));
}
END_TEST

START_TEST(s21_pow_test_138) {
  // 1.0
  ck_assert_double_eq(s21_pow(-S21_INF, 0), pow(-S21_INF, 0));
}
END_TEST

START_TEST(s21_pow_test_139) {
  ck_assert_double_eq(s21_pow(S21_NAN, 0), pow(S21_NAN, 0));
}
END_TEST

START_TEST(s21_pow_test_140) {
  // 1.0
  ck_assert_double_eq(s21_pow(-S21_NAN, 0), pow(-S21_NAN, 0));
}
END_TEST

START_TEST(s21_pow_test_141) {
  // 0.0
  ck_assert_double_eq(s21_pow(-0.0, S21_INF), pow(-0.0, S21_INF));
}
END_TEST

START_TEST(s21_pow_test_142) {
  // -0.0
  ck_assert_double_eq(s21_pow(-0.0, -S21_INF), pow(-0.0, -S21_INF));
}
END_TEST

START_TEST(s21_pow_test_143) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-0.0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_144) {
  // nan
  ck_assert_ldouble_nan(s21_pow(-0.0, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_145) {
  // 0.0
  ck_assert_double_eq(s21_pow(S21_INF, -0), pow(S21_INF, -0));
}
END_TEST

START_TEST(s21_pow_test_146) {
  // 0.0
  ck_assert_double_eq(s21_pow(-S21_INF, -0), pow(-S21_INF, -0));
}
END_TEST

START_TEST(s21_pow_test_147) {
  // 1.0
  ck_assert_double_eq(s21_pow(S21_NAN, -0.0), pow(S21_NAN, -0.0));
}
END_TEST

START_TEST(s21_pow_test_148) {
  // 1.0
  ck_assert_double_eq(s21_pow(-S21_NAN, -0.0), pow(-S21_NAN, -0.0));
}
END_TEST

START_TEST(s21_pow_test_149) {
  double base = 0;
  double exp = 0;
  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_150) {
  double base = -2;
  double exp = 0.3;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_151) {
  double base = 0;
  double exp = -123;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_152) {
  double base = S21_NAN;
  double exp = -123;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_153) {
  double base = 12;
  double exp = S21_NAN;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_154) {
  double base = S21_INF;
  double exp = 20000;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_155) {
  double base = 12;
  double exp = -S21_INF;
  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(s21_pow_test_156) {
  double base = 12;
  double exp = 1.1;
  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), EPSILON);
}
END_TEST

START_TEST(s21_pow_test_157) {
  double base = 0.9;
  double exp = S21_MAX_DOUBLE - 1;
  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), EPSILON);
}
END_TEST

START_TEST(s21_pow_test_158) {
  double base = 25.25;
  double exp = 0.5;
  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), EPSILON);
}
END_TEST

START_TEST(s21_pow_test_159) {
  double base = -S21_INF;
  double exp = -4;
  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), EPSILON);
}
END_TEST

START_TEST(s21_pow_test_160) {
  ck_assert_double_eq_tol(s21_pow(20, 0.4), pow(20, 0.4), EPSILON);
}
END_TEST

START_TEST(s21_pow_test_161) {
  ck_assert_double_nan(s21_pow(-20, 0.4));
  ck_assert_double_nan(pow(-20, 0.4));
}
END_TEST

START_TEST(s21_pow_test_162) {
  ck_assert_double_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test_163) {
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_164) {
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_test_165) {
  ck_assert_double_nan(s21_pow(INFINITY, NAN));
  ck_assert_double_nan(pow(INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test_166) {
  ck_assert_double_nan(s21_pow(NAN, INFINITY));
  ck_assert_double_nan(pow(NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_test_167) {
  ck_assert_double_nan(s21_pow(-INFINITY, NAN));
  ck_assert_double_nan(pow(-INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test_168) {
  ck_assert_double_nan(s21_pow(NAN, -INFINITY));
  ck_assert_double_nan(pow(NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_169) {
  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test_170) {
  ck_assert_double_eq(s21_pow(INFINITY, -INFINITY), pow(INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_171) {
  ck_assert_double_eq_tol(s21_pow(12.69, 0), pow(12.69, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_172) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 3), pow(-20.63, 3), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_173) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 6), pow(-20.63, 6), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_174) {
  ck_assert_double_eq_tol(s21_pow(-INFINITY, 0), pow(-INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_175) {
  ck_assert_double_eq_tol(s21_pow(INFINITY, 0), pow(INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_176) {
  ck_assert_double_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_177) {
  ck_assert_double_eq(s21_pow(0, -INFINITY), pow(0, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test_178) {
  ck_assert_double_eq_tol(s21_pow(0, INFINITY), pow(0, INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_pow_test_179) {
  ck_assert_double_nan(s21_pow(0, NAN));
  ck_assert_double_nan(pow(0, NAN));
}
END_TEST

START_TEST(s21_pow_test_180) { ck_assert_double_eq(s21_pow(0, 0), pow(0, 0)); }
END_TEST

START_TEST(s21_pow_test_181) {
  ck_assert_double_eq(s21_pow(16894.2629, 1545), pow(16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test_182) {
  ck_assert_double_eq(s21_pow(16894.2629, -1545), pow(16894.2629, -1545));
}
END_TEST

START_TEST(s21_pow_test_183) {
  ck_assert_double_eq(s21_pow(-16894.2629, 1545), pow(-16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test_184) {
  ck_assert_double_eq(s21_pow(-16894.2629, -1545), pow(-16894.2629, -1545));
}
END_TEST
START_TEST(s21_pow_test_185) {
  ck_assert_double_eq(s21_pow(-12894.2629, -1545), pow(-12894.2629, -1545));
}
END_TEST
START_TEST(s21_pow_test_186) {
  ck_assert_double_eq(s21_pow(124125.0, 1234.0), pow(124125.0, 1234.0));
}
END_TEST
START_TEST(s21_pow_test_187) {
  double base = 0.5;
  double exp = S21_INF;
  long double x = pow(base, exp);
  long double s21_x = s21_pow(base, exp);
  int exp_count = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp_count < 7) exp_count = 7;
  for (int i = 0; i < 17 && exp_count; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp_count--;
  }
}
END_TEST
START_TEST(s21_pow_test_188) {
  double base = -0.5;
  double exp = -S21_INF;
  long double x = pow(base, exp);
  long double s21_x = s21_pow(base, exp);
  int exp_count = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp_count < 7) exp_count = 7;
  for (int i = 0; i < 17 && exp_count; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp_count--;
  }
}
END_TEST
START_TEST(s21_pow_test_189) {
  double base = -0.5;
  double exp = S21_INF;
  long double x = pow(base, exp);
  long double s21_x = s21_pow(base, exp);
  int exp_count = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp_count < 7) exp_count = 7;
  for (int i = 0; i < 17 && exp_count; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp_count--;
  }
}
END_TEST
START_TEST(s21_pow_test_190) {
  double base = 0.5;
  double exp = -S21_INF;
  long double x = pow(base, exp);
  long double s21_x = s21_pow(base, exp);
  int exp_count = (int)log10l(s21_x);
  char x_str[100];
  char s21_x_str[100];
  sprintf(s21_x_str, "%.15Le", s21_x);
  sprintf(x_str, "%.15Le", x);
  if (exp_count < 7) exp_count = 7;
  for (int i = 0; i < 17 && exp_count; i++) {
    ck_assert_int_eq(s21_x_str[i], x_str[i]);
    exp_count--;
  }
}
END_TEST
Suite *s21_pow_test_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_pow_test_suite");
  tc = tcase_create("s21_pow_test_case");
  tcase_add_test(tc, s21_pow_test_1);
  tcase_add_test(tc, s21_pow_test_2);
  tcase_add_test(tc, s21_pow_test_3);
  tcase_add_test(tc, s21_pow_test_4);
  tcase_add_test(tc, s21_pow_test_5);
  tcase_add_test(tc, s21_pow_test_6);
  tcase_add_test(tc, s21_pow_test_7);
  tcase_add_test(tc, s21_pow_test_8);
  tcase_add_test(tc, s21_pow_test_9);
  tcase_add_test(tc, s21_pow_test_10);
  tcase_add_test(tc, s21_pow_test_11);
  tcase_add_test(tc, s21_pow_test_12);
  tcase_add_test(tc, s21_pow_test_13);
  tcase_add_test(tc, s21_pow_test_14);
  tcase_add_test(tc, s21_pow_test_15);
  tcase_add_test(tc, s21_pow_test_16);
  tcase_add_test(tc, s21_pow_test_17);
  tcase_add_test(tc, s21_pow_test_18);
  tcase_add_test(tc, s21_pow_test_19);
  tcase_add_test(tc, s21_pow_test_20);
  tcase_add_test(tc, s21_pow_test_21);
  tcase_add_test(tc, s21_pow_test_22);
  tcase_add_test(tc, s21_pow_test_23);
  tcase_add_test(tc, s21_pow_test_24);
  tcase_add_test(tc, s21_pow_test_25);
  tcase_add_test(tc, s21_pow_test_26);
  tcase_add_test(tc, s21_pow_test_27);
  tcase_add_test(tc, s21_pow_test_28);
  tcase_add_test(tc, s21_pow_test_29);
  tcase_add_test(tc, s21_pow_test_30);
  tcase_add_test(tc, s21_pow_test_31);
  tcase_add_test(tc, s21_pow_test_32);
  tcase_add_test(tc, s21_pow_test_33);
  tcase_add_test(tc, s21_pow_test_34);
  tcase_add_test(tc, s21_pow_test_35);
  tcase_add_test(tc, s21_pow_test_36);
  tcase_add_test(tc, s21_pow_test_37);
  tcase_add_test(tc, s21_pow_test_38);
  tcase_add_test(tc, s21_pow_test_39);
  tcase_add_test(tc, s21_pow_test_40);
  tcase_add_test(tc, s21_pow_test_41);
  tcase_add_test(tc, s21_pow_test_42);
  tcase_add_test(tc, s21_pow_test_43);
  tcase_add_test(tc, s21_pow_test_44);
  tcase_add_test(tc, s21_pow_test_45);
  tcase_add_test(tc, s21_pow_test_46);
  tcase_add_test(tc, s21_pow_test_47);
  tcase_add_test(tc, s21_pow_test_48);
  tcase_add_test(tc, s21_pow_test_49);
  tcase_add_test(tc, s21_pow_test_50);
  tcase_add_test(tc, s21_pow_test_51);
  tcase_add_test(tc, s21_pow_test_52);
  tcase_add_test(tc, s21_pow_test_53);
  tcase_add_test(tc, s21_pow_test_54);
  tcase_add_test(tc, s21_pow_test_55);
  tcase_add_test(tc, s21_pow_test_56);
  tcase_add_test(tc, s21_pow_test_57);
  tcase_add_test(tc, s21_pow_test_58);
  tcase_add_test(tc, s21_pow_test_59);
  tcase_add_test(tc, s21_pow_test_60);
  tcase_add_test(tc, s21_pow_test_61);
  tcase_add_test(tc, s21_pow_test_62);
  tcase_add_test(tc, s21_pow_test_63);
  tcase_add_test(tc, s21_pow_test_64);
  tcase_add_test(tc, s21_pow_test_65);
  tcase_add_test(tc, s21_pow_test_66);
  tcase_add_test(tc, s21_pow_test_67);
  tcase_add_test(tc, s21_pow_test_68);
  tcase_add_test(tc, s21_pow_test_69);
  tcase_add_test(tc, s21_pow_test_70);
  tcase_add_test(tc, s21_pow_test_71);
  tcase_add_test(tc, s21_pow_test_72);
  tcase_add_test(tc, s21_pow_test_73);
  tcase_add_test(tc, s21_pow_test_74);
  tcase_add_test(tc, s21_pow_test_75);
  tcase_add_test(tc, s21_pow_test_76);
  tcase_add_test(tc, s21_pow_test_77);
  tcase_add_test(tc, s21_pow_test_78);
  tcase_add_test(tc, s21_pow_test_79);
  tcase_add_test(tc, s21_pow_test_80);
  tcase_add_test(tc, s21_pow_test_81);
  tcase_add_test(tc, s21_pow_test_82);
  tcase_add_test(tc, s21_pow_test_83);
  tcase_add_test(tc, s21_pow_test_84);
  tcase_add_test(tc, s21_pow_test_85);
  tcase_add_test(tc, s21_pow_test_86);
  tcase_add_test(tc, s21_pow_test_87);
  tcase_add_test(tc, s21_pow_test_88);
  tcase_add_test(tc, s21_pow_test_89);
  tcase_add_test(tc, s21_pow_test_90);
  tcase_add_test(tc, s21_pow_test_91);
  tcase_add_test(tc, s21_pow_test_92);
  tcase_add_test(tc, s21_pow_test_93);
  tcase_add_test(tc, s21_pow_test_94);
  tcase_add_test(tc, s21_pow_test_95);
  tcase_add_test(tc, s21_pow_test_96);
  tcase_add_test(tc, s21_pow_test_97);
  tcase_add_test(tc, s21_pow_test_98);
  tcase_add_test(tc, s21_pow_test_99);
  tcase_add_test(tc, s21_pow_test_100);
  tcase_add_test(tc, s21_pow_test_101);
  tcase_add_test(tc, s21_pow_test_102);
  tcase_add_test(tc, s21_pow_test_103);
  tcase_add_test(tc, s21_pow_test_104);
  tcase_add_test(tc, s21_pow_test_105);
  tcase_add_test(tc, s21_pow_test_106);
  tcase_add_test(tc, s21_pow_test_107);
  tcase_add_test(tc, s21_pow_test_108);
  tcase_add_test(tc, s21_pow_test_109);
  tcase_add_test(tc, s21_pow_test_110);
  tcase_add_test(tc, s21_pow_test_111);
  tcase_add_test(tc, s21_pow_test_112);
  tcase_add_test(tc, s21_pow_test_113);
  tcase_add_test(tc, s21_pow_test_114);
  tcase_add_test(tc, s21_pow_test_115);
  tcase_add_test(tc, s21_pow_test_116);
  tcase_add_test(tc, s21_pow_test_117);
  tcase_add_test(tc, s21_pow_test_118);
  tcase_add_test(tc, s21_pow_test_119);
  tcase_add_test(tc, s21_pow_test_120);
  tcase_add_test(tc, s21_pow_test_121);
  tcase_add_test(tc, s21_pow_test_122);
  tcase_add_test(tc, s21_pow_test_123);
  tcase_add_test(tc, s21_pow_test_124);
  tcase_add_test(tc, s21_pow_test_125);
  tcase_add_test(tc, s21_pow_test_126);
  tcase_add_test(tc, s21_pow_test_127);
  tcase_add_test(tc, s21_pow_test_128);
  tcase_add_test(tc, s21_pow_test_129);
  tcase_add_test(tc, s21_pow_test_130);
  tcase_add_test(tc, s21_pow_test_131);
  tcase_add_test(tc, s21_pow_test_132);
  tcase_add_test(tc, s21_pow_test_133);
  tcase_add_test(tc, s21_pow_test_134);
  tcase_add_test(tc, s21_pow_test_135);
  tcase_add_test(tc, s21_pow_test_136);
  tcase_add_test(tc, s21_pow_test_137);
  tcase_add_test(tc, s21_pow_test_138);
  tcase_add_test(tc, s21_pow_test_139);
  tcase_add_test(tc, s21_pow_test_140);
  tcase_add_test(tc, s21_pow_test_141);
  tcase_add_test(tc, s21_pow_test_142);
  tcase_add_test(tc, s21_pow_test_143);
  tcase_add_test(tc, s21_pow_test_144);
  tcase_add_test(tc, s21_pow_test_145);
  tcase_add_test(tc, s21_pow_test_146);
  tcase_add_test(tc, s21_pow_test_147);
  tcase_add_test(tc, s21_pow_test_148);
  tcase_add_test(tc, s21_pow_test_149);
  tcase_add_test(tc, s21_pow_test_150);
  tcase_add_test(tc, s21_pow_test_151);
  tcase_add_test(tc, s21_pow_test_152);
  tcase_add_test(tc, s21_pow_test_153);
  tcase_add_test(tc, s21_pow_test_154);
  tcase_add_test(tc, s21_pow_test_155);
  tcase_add_test(tc, s21_pow_test_156);
  tcase_add_test(tc, s21_pow_test_157);
  tcase_add_test(tc, s21_pow_test_158);
  tcase_add_test(tc, s21_pow_test_159);
  tcase_add_test(tc, s21_pow_test_160);
  tcase_add_test(tc, s21_pow_test_161);
  tcase_add_test(tc, s21_pow_test_162);
  tcase_add_test(tc, s21_pow_test_163);
  tcase_add_test(tc, s21_pow_test_164);
  tcase_add_test(tc, s21_pow_test_165);
  tcase_add_test(tc, s21_pow_test_166);
  tcase_add_test(tc, s21_pow_test_167);
  tcase_add_test(tc, s21_pow_test_168);
  tcase_add_test(tc, s21_pow_test_169);
  tcase_add_test(tc, s21_pow_test_170);
  tcase_add_test(tc, s21_pow_test_171);
  tcase_add_test(tc, s21_pow_test_172);
  tcase_add_test(tc, s21_pow_test_173);
  tcase_add_test(tc, s21_pow_test_174);
  tcase_add_test(tc, s21_pow_test_175);
  tcase_add_test(tc, s21_pow_test_176);
  tcase_add_test(tc, s21_pow_test_177);
  tcase_add_test(tc, s21_pow_test_178);
  tcase_add_test(tc, s21_pow_test_179);
  tcase_add_test(tc, s21_pow_test_180);
  tcase_add_test(tc, s21_pow_test_181);
  tcase_add_test(tc, s21_pow_test_182);
  tcase_add_test(tc, s21_pow_test_183);
  tcase_add_test(tc, s21_pow_test_184);
  tcase_add_test(tc, s21_pow_test_185);
  tcase_add_test(tc, s21_pow_test_186);
  tcase_add_test(tc, s21_pow_test_187);
  tcase_add_test(tc, s21_pow_test_188);
  tcase_add_test(tc, s21_pow_test_189);
  tcase_add_test(tc, s21_pow_test_190);

  suite_add_tcase(s, tc);
  return s;
}