#include "../s21_decimal.h"

bool get_sign(s21_decimal dst) {
  return (dst.bits[_MAX_DECIMAL_DIGIT_INT] >> 31) & 1;
}