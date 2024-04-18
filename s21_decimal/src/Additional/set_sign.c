#include "../s21_decimal.h"

void set_sign(s21_decimal *a, bool sign) {
  if (sign == 0) {
    a->bits[_MAX_DECIMAL_DIGIT_INT] &= ~(1u << 31);
  } else {
    a->bits[_MAX_DECIMAL_DIGIT_INT] |= (1u << 31);
  }
}