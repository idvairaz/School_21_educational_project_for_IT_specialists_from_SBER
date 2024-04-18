#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = _NO_ERROR;
  short sign1 = get_sign(value_1);
  short sign2 = get_sign(value_2);
  if (!result || is_bad_decimal(value_1) || is_bad_decimal(value_2))
    error = _ERR_NUMBER;
  if (!error) {
    memset(result, 0, sizeof(s21_decimal));
    if ((sign1 ^ sign2) == 0) {  // + +, - -, =>add
      t_bcd bcd1 = {0};
      t_bcd bcd2 = {0};
      t_bcd res_bcd = {0};
      short res_point = bcd_2_to_10_align_point(value_1, value_2, &bcd1, &bcd2);
      error |= bcd_10_add(bcd1, bcd2, &res_bcd);
      error |= from_bcd_10_to_decimal(&res_bcd, result, res_point);
      if ((sign1 + sign2) == 2) set_sign(result, _MINUS);
    } else {  // + -, - + => sub
      if (sign2 == _MINUS) set_sign(&value_2, _PLUS);
      if (sign1 == _MINUS) {
        set_sign(&value_1, _PLUS);
        s21_decimal temp = value_1;
        value_1 = value_2;
        value_2 = temp;
      }
      error |= s21_sub(value_1, value_2, result);
    }
    if ((error == _ERR_BIG_NUM) && (get_sign(*result) == _MINUS))
      error = _ERR_SMALL_NUM;
    if (error) memset(result, 0, sizeof(s21_decimal));
  }
  return error;
}