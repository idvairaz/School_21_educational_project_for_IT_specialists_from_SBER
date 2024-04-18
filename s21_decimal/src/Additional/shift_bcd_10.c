#include "../s21_decimal.h"

void shift_bcd_10(t_bcd *bcd10, short shift_10) {
  if (shift_10 < 0) {
    bcd10->bits[_MAX_BCD_INT - 1] <<= 4;
    for (int i = _MAX_BCD_INT - 2; i >= _BEGIN_BCD_10; i--) {
      bcd10->bits[i + 1] |=
          ((bcd10->bits[i] & _HIGH_4BIT_INT) >> (_SIZE_INT_BITS - 4));
      bcd10->bits[i] <<= 4;
    }
    shift_10++;
  }
  if (shift_10 > 0) {
    bcd10->bits[_BEGIN_BCD_10] >>= 4;
    for (int i = _BEGIN_BCD_10 + 1; i < _MAX_BCD_INT; i++) {
      bcd10->bits[i - 1] |=
          ((bcd10->bits[i] & _LOW_4BIT_INT) << (_SIZE_INT_BITS - 4));
      bcd10->bits[i] >>= 4;
    }
    shift_10--;
  }
  if (shift_10) shift_bcd_10(bcd10, shift_10);
}