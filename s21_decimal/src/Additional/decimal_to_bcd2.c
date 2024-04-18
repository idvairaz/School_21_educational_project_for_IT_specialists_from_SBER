#include "../s21_decimal.h"

void decimal_to_bcd2(t_bcd* bcd2, s21_decimal* value) {
  for (int i = 0; i < _MAX_DECIMAL_DIGIT_INT; i++)
    bcd2->bits[i] = value->bits[i];
}