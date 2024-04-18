#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  s21_decimal under_result = {0};
  t_bcd bcd_val = {0};
  decimal_to_zero(result);
  decimal_to_bcd2(&bcd_val, &value);
  bcd_2_to_10(&bcd_val);
  int err = 0;
  shift_bcd_10(&bcd_val, -((_MAX_BCD_INT - _BEGIN_BCD_10) * _SIZE_INT_BYTE * 2 -
                           get_exp_10(value)));
  bool reminder = 0;
  for (int i = 0; i < _MAX_BCD_INT && !reminder; i++) {
    if (bcd_val.bits[i]) reminder = 1;
  }
  bool sign = get_sign(value);
  s21_truncate(value, &under_result);
  set_sign(&under_result, sign);
  if (sign && reminder) {
    s21_decimal one = {{1, 0, 0, 0}};
    err = s21_sub(under_result, one, result);
  } else {
    result->bits[0] = under_result.bits[0];
    result->bits[1] = under_result.bits[1];
    result->bits[2] = under_result.bits[2];
    result->bits[3] = under_result.bits[3];
  }
  return err;
}