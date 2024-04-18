#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = _NO_ERROR;
  if (!result || is_bad_decimal(value_1) || is_bad_decimal(value_2)) {
    error = _ERR_NUMBER;
  } else
    memset(result, 0, sizeof(s21_decimal));
  if (!error && !decimal_bcd_is_zero(&value_1, _MAX_DECIMAL_DIGIT_INT) &&
      !decimal_bcd_is_zero(&value_2, _MAX_DECIMAL_DIGIT_INT)) {
    t_bcd res_bcd = {0};
    for (unsigned int i2 = 0; i2 < _SIZE_DECIMAL_BITS; i2++) {
      unsigned int shift_bit2 = (unsigned)1 << (i2 % _SIZE_INT_BITS);
      short bit_curr_v2 =
          ((value_2.bits[i2 / _SIZE_INT_BITS] & shift_bit2) > 0);
      short next_bit = 0;
      unsigned int bcd_razryad = i2;
      for (unsigned int i1 = 0; i1 < _SIZE_DECIMAL_BITS; i1++, bcd_razryad++) {
        unsigned int shift_bit1 = (unsigned)1 << (i1 % _SIZE_INT_BITS);
        short bit_curr_v1 =
            ((value_1.bits[i1 / _SIZE_INT_BITS] & shift_bit1) > 0);
        unsigned int shift_ints_bcd = (unsigned)1
                                      << (bcd_razryad % _SIZE_INT_BITS);
        short bcd_int = bcd_razryad / _SIZE_INT_BITS;
        short bit_bcd = ((res_bcd.bits[bcd_int] & shift_ints_bcd) > 0);
        short bit_res = bit_curr_v1 * bit_curr_v2 + bit_bcd + next_bit;
        next_bit = (bit_res >= 2);
        bit_res %= 2;
        if (bit_res == 1)
          res_bcd.bits[bcd_int] |= shift_ints_bcd;
        else
          res_bcd.bits[bcd_int] &= ~shift_ints_bcd;
      }
      res_bcd.bits[bcd_razryad / _SIZE_INT_BITS] |=
          ((unsigned)next_bit << (bcd_razryad % _SIZE_INT_BITS));
    }
    int point = get_exp_10(value_1) + get_exp_10(value_2);
    bcd_2_to_10(&res_bcd);
    error |= from_bcd_10_to_decimal(&res_bcd, result, point);
    set_sign(result, get_sign(value_1) ^ get_sign(value_2));
    if ((error == _ERR_BIG_NUM) && (get_sign(*result) == _MINUS))
      error = _ERR_SMALL_NUM;
    if (error) memset(result, 0, sizeof(s21_decimal));
  }
  return error;
}