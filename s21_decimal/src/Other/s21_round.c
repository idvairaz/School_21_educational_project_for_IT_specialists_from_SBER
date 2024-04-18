#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  short error = _NO_ERROR;
  int point = get_exp_10(value);
  bool sign = get_sign(value);
  if (result)
    memset(result, 0, sizeof(s21_decimal));
  else
    error = _ERR_CALCULATE;
  if (!error) {
    if (point > 0) {
      t_bcd bcd = {0};
      decimal_to_bcd2(&bcd, &value);
      bcd_2_to_10(&bcd);
      shift_bcd_10(&bcd, point - 1);
      short last_digit0 = bcd.bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0;
      int next_10razryad = (last_digit0 >= 5);
      shift_bcd_10(&bcd, 1);
      from_bcd_10_to_decimal(&bcd, result, 0);
      if (next_10razryad) {
        s21_decimal add1 = {{1, 0, 0, 0}};
        error |= s21_add(*result, add1, result);
      }
    } else
      *result = value;
    set_sign(result, sign);
  }
  return error;
}