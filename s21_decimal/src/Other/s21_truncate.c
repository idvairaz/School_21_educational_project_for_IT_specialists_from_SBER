#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (!result || is_bad_decimal(value)) error = 1;
  if (!error) {
    decimal_to_zero(result);
    t_bcd bcd_val = {0};
    decimal_to_bcd2(&bcd_val, &value);
    bcd_2_to_10(&bcd_val);
    shift_bcd_10(&bcd_val, get_exp_10(value));
    from_bcd_10_to_decimal(&bcd_val, result, 0);
    set_sign(result, get_sign(value));
  }
  return error;
}