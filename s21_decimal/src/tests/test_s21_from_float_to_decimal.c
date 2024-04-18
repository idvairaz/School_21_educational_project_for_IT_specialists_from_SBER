#include "test_s21_decimal.h"

START_TEST(test1) {
  s21_decimal dst;
  float src = FLT_MIN;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 1);
}
END_TEST

START_TEST(test2) {
  s21_decimal dst;
  float src = FLT_MAX;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 1);
}
END_TEST

START_TEST(test3) {
  s21_decimal dst;
  float src = 0.0;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test4) {
  s21_decimal dst;
  float src = 1234567.8;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
  s21_from_decimal_to_float(dst, &src);
}
END_TEST

START_TEST(test5) {
  s21_decimal dst;
  float src = 1e-28;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test6) {
  s21_decimal dst;

  ck_assert_int_eq(s21_from_float_to_decimal(NAN, &dst), 1);
}
END_TEST

START_TEST(test7) {
  s21_decimal dst;
  float src = -1.1;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test8) {
  s21_decimal dst;
  float src = FLT_MAX + 0.1;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 1);
}
END_TEST

START_TEST(test9) {
  s21_decimal dst;
  float src = (float)79228162514264337593543950335.0;
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 1);
}
END_TEST

START_TEST(test10) {
  s21_decimal dst;
  s21_decimal dst2 = {{536870912, 3012735514, 4294967159, 0}};
  // 79228160000000000000000000000====point=0
  float src = 7.92281577919e+28;
  s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(dst.bits[0], dst2.bits[0]);
  ck_assert_int_eq(dst.bits[1], dst2.bits[1]);
  ck_assert_int_eq(dst.bits[2], dst2.bits[2]);
  ck_assert_int_eq(s21_from_float_to_decimal(src, &dst), 0);
}
END_TEST

START_TEST(test11) {
  s21_decimal dst;
  s21_decimal dst2 = {{0xf6950, 0x0, 0x0, 0x150000}};
  float src = 1.01e-15;
  int result = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(s21_is_equal(dst, dst2), 1);
}
END_TEST

START_TEST(test12) {
  s21_decimal dst;
  float src = 1.01e-27;
  int result = s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test13) {
  s21_decimal dst;

  int result = s21_from_float_to_decimal(NAN, &dst);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test14) {
  s21_decimal dst;
  float src = -1.0;
  s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(get_sign(dst), 1);
}
END_TEST

START_TEST(test15) {
  s21_decimal dst;
  float src = 1.0;
  s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(get_sign(dst), 0);
}
END_TEST

START_TEST(test16) {
  s21_decimal dst;
  float src = -0.0;
  s21_from_float_to_decimal(src, &dst);
  ck_assert_int_eq(get_sign(dst), 0);
}
END_TEST

Suite *test_s21_from_float_to_decimal() {
  Suite *s = suite_create("\033[45m-=s21_from_float_to_decimal=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);
  tcase_add_test(tc, test9);
  tcase_add_test(tc, test10);
  tcase_add_test(tc, test11);
  tcase_add_test(tc, test12);
  tcase_add_test(tc, test13);
  tcase_add_test(tc, test14);
  tcase_add_test(tc, test15);
  tcase_add_test(tc, test16);

  suite_add_tcase(s, tc);
  return s;
}