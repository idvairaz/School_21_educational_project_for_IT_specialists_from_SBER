#include "../s21_decimal.h"

bool set_exp(s21_decimal *dst, int exp) {
  bool err = 0;
  if (exp >= 0 && exp <= 28) {
    int i = _MAX_DECIMAL_DIGIT_INT * 32 + 16;
    while (exp > 0) {
      set_bit(dst, i, exp % 2);
      exp = exp / 2;
      i++;
    }
  } else {
    err = 1;
  }
  return err;
}