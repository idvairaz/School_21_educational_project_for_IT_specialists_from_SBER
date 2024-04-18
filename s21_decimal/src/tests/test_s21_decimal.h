#ifndef SRC_TESTS_TEST_s21_DECIMAL_H
#define SRC_TESTS_TEST_s21_DECIMAL_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

Suite *test_s21_add();
Suite *test_s21_sub();
Suite *test_s21_mul();
Suite *test_s21_div();

Suite *test_s21_is_less();
Suite *test_s21_is_less_or_equal();
Suite *test_s21_is_greater();
Suite *test_s21_is_greater_or_equal();
Suite *test_s21_is_equal();
Suite *test_s21_is_not_equal();

Suite *test_s21_from_int_to_decimal();
Suite *test_s21_from_float_to_decimal();
Suite *test_s21_from_decimal_to_int();
Suite *test_s21_from_decimal_to_float();

Suite *test_s21_floor();
Suite *test_s21_round();
Suite *test_s21_truncate();
Suite *test_s21_negate();

#endif  // SRC_TESTS_TEST_DECIMAL_H