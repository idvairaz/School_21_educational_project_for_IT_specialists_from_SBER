#include "../s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  return (s21_is_not_equal(a, b) && !s21_is_less(a, b));
}