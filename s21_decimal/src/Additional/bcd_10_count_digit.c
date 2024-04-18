#include "../s21_decimal.h"

short bcd_10_count_digit(t_bcd *bcd10) {
  int first_zero = 1;
  short count_10 = (_MAX_BCD_INT - _BEGIN_BCD_10) * _SIZE_INT_BYTE * 8 / 4;
  for (int i = _MAX_BCD_INT - 1; ((i >= _BEGIN_BCD_10) && first_zero); i--) {
    if (bcd10->bits[i] != 0) {
      unsigned int temp = bcd10->bits[i];
      for (; temp > 0; temp <<= 4) {
        if ((temp & _HIGH_4BIT_INT) == 0)
          count_10--;
        else
          temp = 0;
      }
      first_zero = 0;
    } else {
      count_10 -= (_SIZE_INT_BYTE * 2);
    }
  }
  return count_10;
}