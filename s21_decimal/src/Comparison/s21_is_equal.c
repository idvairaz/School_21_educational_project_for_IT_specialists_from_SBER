#include "../s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  bool result = 1;
  if (get_sign(a) == get_sign(b)) {
    t_bcd a_bcd = {0}, b_bcd = {0};
    bcd_2_to_10_align_point(a, b, &a_bcd, &b_bcd);
    for (int i = 0; i < _MAX_BCD_INT && result; i++) {
      if (a_bcd.bits[i] != b_bcd.bits[i]) result = 0;
    }
  } else {
    result = 0;
  }
  return result;
}