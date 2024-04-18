#include "../s21_decimal.h"

int from_bcd_10_to_decimal(t_bcd *bcd10, s21_decimal *value, short point) {
  int error = _NO_ERROR;
  int bank_round = _BANK_ROUND;
  error |= bcd_10_to_2_N_INT_with_bank(bcd10, _MAX_DECIMAL_DIGIT_INT, &point, 0,
                                       bank_round);
  if ((point >= MAX_EXP10) && (bcd10->bits[0] == 0)) error = _ERR_SMALL_NUM;
  if (point == 0 && bcd10->bits[_MAX_DECIMAL_DIGIT_INT] & _INT_VALUE)
    error = _ERR_BIG_NUM;
  if (!error) {
    for (int i = 0; i < _MAX_DECIMAL_DIGIT_INT; i++) {
      value->bits[i] = bcd10->bits[i];
    }
    set_exp(value, point);
  }
  return error;
}