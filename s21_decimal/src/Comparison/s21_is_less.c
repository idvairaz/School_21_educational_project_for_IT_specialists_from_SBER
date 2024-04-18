#include "../s21_decimal.h"

int s21_is_less(s21_decimal a, s21_decimal b) {
  bool result = 0;
  if (get_sign(a) == get_sign(b)) {
    t_bcd a_bcd = {0}, b_bcd = {0};
    bcd_2_to_10_align_point(a, b, &a_bcd, &b_bcd);
    bool brk = 0;
    for (int j = _MAX_BCD_BYTES * 8 - 1; j >= 0 && !brk; j--) {
      bool a_bit = get_bit_bcd(a_bcd, j);
      bool b_bit = get_bit_bcd(b_bcd, j);
      if (a_bit < b_bit) {
        if (!get_sign(a)) {
          result = 1;
        }
        brk = 1;
      }
      if (a_bit > b_bit) {
        if (get_sign(a)) {
          result = 1;
        }
        brk = 1;
      }
    }
  } else if (get_sign(a) > get_sign(b)) {
    result = 1;
  }
  return result;
}