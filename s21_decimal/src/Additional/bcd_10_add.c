#include "../s21_decimal.h"

int bcd_10_add(t_bcd bcd1, t_bcd bcd2, t_bcd *res_bcd) {
  int error = _NO_ERROR;
  if (res_bcd)
    memset(res_bcd, 0, sizeof(t_bcd));
  else
    error = _ERR_CALCULATE;
  if (!error) {
    int next_bit = 0, i;
    for (i = _BEGIN_BCD_10 * _SIZE_INT_BYTE; i < _MAX_BCD_BYTES; i++) {
      short res_sum_bits = bcd1.bits_4[i].a0 + bcd2.bits_4[i].a0 + next_bit;
      next_bit = res_sum_bits / 10;
      res_bcd->bits_4[i].a0 = res_sum_bits % 10;
      res_sum_bits = bcd1.bits_4[i].a1 + bcd2.bits_4[i].a1 + next_bit;
      next_bit = res_sum_bits / 10;
      res_bcd->bits_4[i].a1 = res_sum_bits % 10;
    }
    if (next_bit) res_bcd->bits_4[i].a0 = next_bit;
  }
  return error;
}