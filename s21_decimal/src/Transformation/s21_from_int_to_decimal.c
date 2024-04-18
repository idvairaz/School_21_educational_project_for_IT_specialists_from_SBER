#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int err = 0;
  decimal_to_zero(dst);
  if (src < 0) {
    set_sign(dst, 1);
    dst->bits[0] = -src;
  } else {
    dst->bits[0] = src;
  }
  return err;
}