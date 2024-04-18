#include "../s21_decimal.h"

bool set_bit(s21_decimal *dst, int bit, bool value) {
  bool err = 0;
  if (bit >= 0 && bit < _MAX_DECIMAL_INT * 32) {
    if (value) {
      dst->bits[bit / 32] |= (1 << bit % 32);
    } else {
      dst->bits[bit / 32] &= ~(1 << bit % 32);
    }
  } else {
    err = 1;
  }
  return err;
}