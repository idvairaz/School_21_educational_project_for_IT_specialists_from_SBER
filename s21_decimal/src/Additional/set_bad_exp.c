#include "../s21_decimal.h"

void set_bad_exp(s21_decimal *dst, int exp) {
  int i = _MAX_DECIMAL_DIGIT_INT * 32 + 16;
  while (exp > 0) {
    set_bit(dst, i, exp % 2);
    exp = exp / 2;
    i++;
  }
}