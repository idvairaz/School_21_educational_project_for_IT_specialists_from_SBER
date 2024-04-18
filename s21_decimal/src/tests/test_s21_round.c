#include "test_s21_decimal.h"

START_TEST(test_round_1) {
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  s21_decimal answer = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_2) {
  s21_decimal value_1 = {{1, 0, 0, 0}};

  s21_decimal answer = {{1, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_3) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal answer = {{12, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_4) {
  s21_decimal value_1 = {{125, 0, 0, 0}};
  set_exp(&value_1, 1);

  s21_decimal answer = {{13, 0, 0, 0}};

  s21_decimal result = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_5) {
  s21_decimal value_1 = {{123, 0, 0, 0}};
  set_sign(&value_1, _MINUS);
  set_exp(&value_1, 1);

  s21_decimal answer = {{12, 0, 0, 0}};
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_6) {
  // 79228162514264337593543950335
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);
  set_exp(&value_1, 28);

  s21_decimal answer = {{8, 0, 0, 0}};
  set_sign(&answer, _MINUS);

  s21_decimal result = {0};

  int error = s21_round(value_1, &result);
  ck_assert_mem_eq(&result, &answer, sizeof(s21_decimal));
  ck_assert_int_eq(error, _NO_ERROR);
}
END_TEST

START_TEST(test_round_7) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&value_1, _MINUS);
  set_exp(&value_1, 28);

  s21_decimal answer = {{8, 0, 0, 0}};
  set_sign(&answer, _MINUS);
  s21_decimal *result = NULL;

  int error = s21_round(value_1, result);
  ck_assert_int_eq(error, _ERR_CALCULATE);
}
END_TEST

Suite *test_s21_round(void) {
  Suite *s = suite_create("\033[45m-=s21_round=-\033[0m");
  TCase *tc = tcase_create("S21 decimal round");

  tcase_add_test(tc, test_round_1);
  tcase_add_test(tc, test_round_2);
  tcase_add_test(tc, test_round_3);
  tcase_add_test(tc, test_round_4);
  tcase_add_test(tc, test_round_5);
  tcase_add_test(tc, test_round_6);
  tcase_add_test(tc, test_round_7);

  suite_add_tcase(s, tc);
  return s;
}