#include "../s21_decimal.h"

void print_decimal_10(s21_decimal value) {
  union decimal_bits value_print = {0};
  s21_decimal value_origin;
  printf("\n");
  for (int i = 0; i < _MAX_DECIMAL_DIGIT_INT; i++)
    value_origin.bits[i] = value.bits[i];
  if (value.bits[_MAX_DECIMAL_DIGIT_INT] & _NEGATIVE) printf("-");
  for (int i = 0; i < _SIZE_DECIMAL_BITS; i++) {
    for (int k = 0; k < _SIZE_INT_BYTE * _MAX_DECIMAL_INT; k++) {
      if (value_print.bits_4[k].a0 >= 5) value_print.bits_4[k].a0 += 3;
      if (value_print.bits_4[k].a1 >= 5) value_print.bits_4[k].a1 += 3;
    }
    shift_ints((unsigned int *)&value_print.nums, -1, _MAX_DECIMAL_INT);
    if (value_origin.bits[_MAX_DECIMAL_DIGIT_INT - _NO_HIGH_INT] & _32BIT)
      value_print.nums.bits[0] |= _1BIT;
    shift_ints((unsigned int *)&value_origin, -1, _MAX_DECIMAL_DIGIT_INT);
  }
  bool first = 1;
  for (int i = _MAX_DECIMAL_INT * _SIZE_INT_BYTE - 2; i >= 0; i--) {
    if (first) {
      printf("%d", value_print.bits_4[i].a0);
      first = 0;
    } else {
      printf("%d%d", value_print.bits_4[i].a1, value_print.bits_4[i].a0);
    }
  }
  printf("=point=%u",
         ((value.bits[_MAX_DECIMAL_INT - 1] & _POINT_DECIMAL) >> 16));
}