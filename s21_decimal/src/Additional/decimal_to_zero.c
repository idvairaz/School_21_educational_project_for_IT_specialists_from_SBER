#include "../s21_decimal.h"

void decimal_to_zero(s21_decimal *dst) {
  for (short i = 0; i < _MAX_DECIMAL_INT; i++) dst->bits[i] = 0;
}