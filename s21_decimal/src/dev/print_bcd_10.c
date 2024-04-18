#include "../s21_decimal.h"

void print_bcd_10(t_bcd bcd10) {
  printf("\nTemp result from function print_bcd_10: ");
  int first_zero = 1;
  for (int i = _MAX_BCD_BYTES - 1; i >= _BEGIN_BCD_10 * _SIZE_INT_BYTE; i--) {
    if (first_zero) {
      if (bcd10.bits[i / _SIZE_INT_BYTE] != 0) {
        first_zero = 0;
      } else {
        i -= (_SIZE_INT_BYTE - 1);
      }
    }
    if (!first_zero) {
      printf("%d%d", bcd10.bits_4[i].a1, bcd10.bits_4[i].a0);
    }
  }
}