#include "../s21_decimal.h"

void bcd_10_to_2(t_bcd *bcd10) {
  int count_shift = _BEGIN_BCD_10 * _SIZE_INT_BITS;
  for (int i = 0; i < count_shift; i++) {
    shift_ints((unsigned int *)bcd10, 1, _MAX_BCD_INT);
    for (int k = _BEGIN_BCD_10 * _SIZE_INT_BYTE; k < _MAX_BCD_BYTES; k++) {
      if (bcd10->bits_4[k].a0 >= 5) bcd10->bits_4[k].a0 -= 3;
      if (bcd10->bits_4[k].a1 >= 5) bcd10->bits_4[k].a1 -= 3;
    }
  }
}