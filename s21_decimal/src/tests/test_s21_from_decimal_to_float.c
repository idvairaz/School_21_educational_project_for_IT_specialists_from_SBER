#include "test_s21_decimal.h"

START_TEST(test1) {
  /**
   * валидный decimal, тест проверяет код ошибки, ожидается код = 0
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 6789;
  src.bits[2] = 524;
  src.bits[3] = 0;
  set_exp(&src, 13);
  set_sign(&src, 1);
  float dst = 0.0;
  int result = s21_from_decimal_to_float(src, &dst);
  int expected = 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test2) {
  /**
   * валидный decimal, тест проверяет преобразованный float,
   * ожидается float dst = 966609408.0 (положительный float);
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 6789;
  src.bits[2] = 524;
  src.bits[3] = 0;
  int exp = 13;
  set_exp(&src, exp);
  set_sign(&src, 0);
  float dst = 0.0;
  s21_from_decimal_to_float(src, &dst);
  int expected =
      (src.bits[0] + src.bits[1] * pow(2, 32) + src.bits[2] * pow(2, 64)) *
      pow(10, (-exp));

  ck_assert_float_eq(dst, expected);
}
END_TEST

START_TEST(test3) {
  /**
   * валидный decimal, тест проверяет преобразованный float,
   * ожидается float dst = -1.63955e+06 (отрицательный float);
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 9999;
  src.bits[2] = 8888;
  src.bits[3] = 0;
  int exp = 17;
  set_exp(&src, exp);
  set_sign(&src, 1);
  float dst = 0.0;
  s21_from_decimal_to_float(src, &dst);
  float expected =
      -1.0 *
      (src.bits[0] + src.bits[1] * pow(2, 32) + src.bits[2] * pow(2, 64)) *
      pow(10, (-exp));

  ck_assert_float_eq(dst, expected);
}
END_TEST

START_TEST(test4) {
  /**
   * НЕ валидный decimal (src.bits[3] != 0), тест проверяет код ошибки,
   * ожидается код = 1
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 6789;
  src.bits[2] = 524;
  src.bits[3] = 222;
  int exp = 17;
  set_exp(&src, exp);
  set_sign(&src, 1);
  float dst = 0.0;
  int result = s21_from_decimal_to_float(src, &dst);
  int expected = 1;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test5) {
  /**
   * НЕ валидный decimal (exp > 28), тест проверяет код ошибки, ожидается код =
   * 1
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 6789;
  src.bits[2] = 524;
  src.bits[3] = 0;
  int exp = 30;
  set_bad_exp(&src, exp);
  set_sign(&src, 1);
  float dst = 0.0;
  int result = s21_from_decimal_to_float(src, &dst);
  int expected = 1;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test6) {
  /**
   * НЕ валидный decimal (> 79,228,162,514,264,337,593,543,950,335),
   * тест проверяет код ошибки, ожидается код = 1
   */
  s21_decimal src;
  src.bits[0] = 0xFFFFFFFF;
  src.bits[1] = 0xFFFFFFFF;
  src.bits[2] = 0xFFFFFFFF;
  src.bits[3] = 0;
  int exp = 0;
  set_exp(&src, exp);
  set_sign(&src, 1);
  float dst = 0.0;
  int result = s21_from_decimal_to_float(src, &dst);
  int expected = 0;

  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test7) {
  /**
   * НЕ валидный decimal (exp > 28), тест проверяет, что при коде ошибки = 1,
   * значение dst = 0,0
   */
  s21_decimal src;
  src.bits[0] = 12345;
  src.bits[1] = 6789;
  src.bits[2] = 524;
  src.bits[3] = 0;
  int exp = 30;
  set_bad_exp(&src, exp);
  set_sign(&src, 1);
  float dst = 0.0;
  s21_from_decimal_to_float(src, &dst);
  float expected = 0.0;

  ck_assert_float_eq(dst, expected);
}
END_TEST

START_TEST(test8) {
  /**
   * валидный decimal, тест проверяет преобразованный float,
   * ожидается float dst = 0.0000000018446744132205.....;
   */
  s21_decimal src;
  src.bits[0] = 1;
  src.bits[1] = 1;
  src.bits[2] = 1;
  src.bits[3] = 0;
  int exp = 28;
  set_exp(&src, exp);
  set_sign(&src, 0);
  float dst = 0.0;
  s21_from_decimal_to_float(src, &dst);
  float expected =
      (src.bits[0] + src.bits[1] * pow(2, 32) + src.bits[2] * pow(2, 64)) *
      pow(10, (-exp));

  ck_assert_float_eq(dst, expected);
}
END_TEST

START_TEST(test9) {
  /**
   * валидный decimal, тест проверяет преобразованный float,
   * ожидается float dst = 966609408.0 (положительный float);
   */
  s21_decimal src;
  src.bits[0] = 0xFFFFFFFF;
  src.bits[1] = 0xFFFFFFFF;
  src.bits[2] = 0xFFFFFFFF;
  src.bits[3] = 0;

  set_sign(&src, 0);
  float dst = 0.0;
  s21_from_decimal_to_float(src, &dst);
  float max_f = 7.92281577919e+28;

  ck_assert_float_eq(dst, max_f);
}
END_TEST

Suite *test_s21_from_decimal_to_float() {
  Suite *s = suite_create("\033[45m-=s21_from_decimal_to_float=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_float_tc");

  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test3);
  tcase_add_test(tc, test4);
  tcase_add_test(tc, test5);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, test7);
  tcase_add_test(tc, test8);
  tcase_add_test(tc, test9);

  suite_add_tcase(s, tc);
  return s;
}