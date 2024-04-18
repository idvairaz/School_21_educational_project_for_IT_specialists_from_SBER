#include "../s21_decimal.h"

short decimal_bcd_is_zero(void *value, short size_int) {
  unsigned int *ptr_data = (unsigned int *)value;
  short zero = 1;
  for (short i = 0; (i < size_int) && zero; i++, ptr_data++)
    zero = (*ptr_data == 0);
  return zero;
}