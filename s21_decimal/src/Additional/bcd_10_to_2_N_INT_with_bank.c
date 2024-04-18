#include "../s21_decimal.h"

short bcd_10_to_2_N_INT_with_bank(t_bcd *bcd10, short N_INT, short *point,
                                  short next_10razryad, short bank_round) {
  short error = _NO_ERROR;
  t_bcd bcd_save_10 = *bcd10;
  bcd_10_to_2(bcd10);
  if ((!decimal_bcd_is_zero(&bcd10, _MAX_BCD_INT) && (*point > MAX_EXP10)) ||
      ((bcd10->bits[N_INT] & _INT_VALUE) && (*point > 0))) {
    short last_digit0 = bcd_save_10.bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0;
    short last_digit1 = bcd_save_10.bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a1;
    next_10razryad = 0;
    if (last_digit0 > 5) next_10razryad = 1;
    if (last_digit0 < 5) next_10razryad = 0;
    if (last_digit0 == 5) {
      if (bank_round == _BANK_ROUND) next_10razryad = last_digit1 % 2;
      if (bank_round == _NO_BANK_ROUND) next_10razryad = 1;
    }
    if (bank_round == _BANK_ROUND && last_digit0 > 0)
      bank_round = _NO_BANK_ROUND;
    (*point)--;
    shift_bcd_10(&bcd_save_10, 1);
    *bcd10 = bcd_save_10;
    error |= bcd_10_to_2_N_INT_with_bank(bcd10, N_INT, point, next_10razryad,
                                         bank_round);
  } else {
    if (next_10razryad) {
      bcd_2_to_10(bcd10);
      t_bcd add1 = {0};
      add1.bits_4[_BEGIN_BCD_10 * _SIZE_INT_BYTE].a0 = 1;
      bcd_10_add(*bcd10, add1, bcd10);
      error |= bcd_10_to_2_N_INT_with_bank(bcd10, N_INT, point, 0, bank_round);
    }
  }
  return error;
}