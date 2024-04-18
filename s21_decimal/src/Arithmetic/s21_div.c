#include "../s21_decimal.h"

int bcd_10_less(t_bcd bcd1, t_bcd bcd2);
int get_next_divided(t_bcd *curr_bcd10, t_bcd bcd1, short *remain_digit,
                     short *point_curr, short N_res_digit, short res_count);
short prepare_digits(t_bcd *bcd1, t_bcd *bcd2, t_bcd *curr_bcd10,
                     s21_decimal value_1, s21_decimal value_2,
                     short *remain_digit);
short start_dividing(t_bcd *res_bcd, t_bcd curr_bcd10, t_bcd bcd1, t_bcd bcd2,
                     short remain_digit);

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = _NO_ERROR;
  if (!result || is_bad_decimal(value_1) || is_bad_decimal(value_2))
    error = _ERR_NUMBER;
  if (decimal_bcd_is_zero(&value_2, _MAX_DECIMAL_DIGIT_INT)) error = _ERR_DIV_0;
  if (!error) {
    memset(result, 0, sizeof(s21_decimal));
    if (!decimal_bcd_is_zero(&value_1, _MAX_DECIMAL_DIGIT_INT)) {
      t_bcd bcd1 = {0}, bcd2 = {0}, curr_bcd10 = {0};
      short remain_digit = 0;
      short start_point = prepare_digits(&bcd1, &bcd2, &curr_bcd10, value_1,
                                         value_2, &remain_digit);
      t_bcd res_bcd = {0};
      short point_curr =
          start_dividing(&res_bcd, curr_bcd10, bcd1, bcd2, remain_digit);
      int res_point = start_point + point_curr;
      if (res_point < 0) {
        shift_bcd_10(&res_bcd, res_point);
        res_point = 0;
      }
      error |= from_bcd_10_to_decimal(&res_bcd, result, res_point);
      set_sign(result, get_sign(value_1) ^ get_sign(value_2));
      if ((error == _ERR_BIG_NUM) && (get_sign(*result) == _MINUS))
        error = _ERR_SMALL_NUM;
      if (error) memset(result, 0, sizeof(s21_decimal));
    }
  }
  return error;
}

short start_dividing(t_bcd *res_bcd, t_bcd curr_bcd10, t_bcd bcd1, t_bcd bcd2,
                     short remain_digit) {
  short N_res_digit = 0, point_curr = 0;
  while (
      (N_res_digit < _MAX_DIGIT_DECIMAL + 4) &&
      (remain_digit >= 0 || !decimal_bcd_is_zero(&curr_bcd10, _MAX_BCD_INT))) {
    short res_count = 0;
    while (bcd_10_less(curr_bcd10, bcd2) != _BCD10_LESS) {
      bcd_10_sub(curr_bcd10, bcd2, &curr_bcd10);
      res_count++;
    }
    shift_bcd_10(res_bcd, -1);
    res_bcd->bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0 = res_count;
    N_res_digit = get_next_divided(&curr_bcd10, bcd1, &remain_digit,
                                   &point_curr, N_res_digit, res_count);
  }
  return point_curr;
}

short prepare_digits(t_bcd *bcd1, t_bcd *bcd2, t_bcd *curr_bcd10,
                     s21_decimal value_1, s21_decimal value_2,
                     short *remain_digit) {
  decimal_to_bcd2(bcd1, &value_1);
  decimal_to_bcd2(bcd2, &value_2);
  bcd_2_to_10(bcd1);
  bcd_2_to_10(bcd2);
  *remain_digit = bcd_10_count_digit(bcd1) - bcd_10_count_digit(bcd2);
  short point_dec1 = get_exp_10(value_1);
  short point_dec2 = get_exp_10(value_2);
  *curr_bcd10 = *bcd1;
  shift_bcd_10(curr_bcd10, *remain_digit);
  if (*remain_digit < 0) {
    point_dec1 -= *remain_digit;
    *remain_digit = 0;
  }
  return point_dec1 - point_dec2;
}

int get_next_divided(t_bcd *curr_bcd10, t_bcd bcd1, short *remain_digit,
                     short *point_curr, short N_res_digit, short res_count) {
  shift_bcd_10(curr_bcd10, -1);
  (*point_curr)++;
  (*remain_digit)--;
  if (*remain_digit >= 0) {
    shift_bcd_10(&bcd1, *remain_digit);
    curr_bcd10->bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0 =
        bcd1.bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0;
  } else {
    if (*remain_digit == -1) *point_curr = 0;
  }
  if (N_res_digit != 0) N_res_digit++;
  if (N_res_digit == 0 && res_count == 0) *point_curr = 0;
  if (N_res_digit == 0 && res_count != 0) N_res_digit = 1;
  return N_res_digit;
}

int bcd_10_less(t_bcd bcd1, t_bcd bcd2) {
  int result = _BCD10_EQUAL;
  for (int i = _MAX_BCD_BYTES - 1;
       (i >= _BEGIN_BCD_10 * _SIZE_INT_BYTE) && (result == _BCD10_EQUAL); i--) {
    short digit1 = bcd1.bits_4[i].a1 * 10 + bcd1.bits_4[i].a0;
    short digit2 = bcd2.bits_4[i].a1 * 10 + bcd2.bits_4[i].a0;
    if (digit1 < digit2) result = _BCD10_LESS;
    if (digit1 > digit2) result = _BCD10_MORE;
  }
  return result;
}