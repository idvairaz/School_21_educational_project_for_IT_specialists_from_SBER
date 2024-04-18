#include "../s21_decimal.h"

void bcd_2_to_10(t_bcd *bcd2) {
  int count_shift = _BEGIN_BCD_10 * _SIZE_INT_BITS;
  for (int i = 0; i < count_shift; i++) {
    for (int k = _BEGIN_BCD_10 * _SIZE_INT_BYTE; k < _MAX_BCD_BYTES; k++) {
      if (bcd2->bits_4[k].a0 >= 5) bcd2->bits_4[k].a0 += 3;
      if (bcd2->bits_4[k].a1 >= 5) bcd2->bits_4[k].a1 += 3;
    }
    shift_ints((unsigned int *)bcd2, -1, _MAX_BCD_INT);
  }
}