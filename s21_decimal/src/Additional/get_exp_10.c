#include "../s21_decimal.h"

int get_exp_10(s21_decimal dst) {
  int exp = 0;
  for (int i = _MAX_DECIMAL_DIGIT_INT * 32 + 23;
       i >= _MAX_DECIMAL_DIGIT_INT * 32 + 16; i--) {
    exp += ((dst.bits[i / 32] >> (i % 32)) & 1) *
           pow(2, i - _MAX_DECIMAL_DIGIT_INT * 32 - 16);
  }
  return exp;
}