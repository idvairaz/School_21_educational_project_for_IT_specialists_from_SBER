#include "../s21_decimal.h"

short bcd_2_to_10_align_point(s21_decimal value_1, s21_decimal value_2,
                              t_bcd *bcd2_1, t_bcd *bcd2_2) {
  int point1 = get_exp_10(value_1);
  int point2 = get_exp_10(value_2);
  decimal_to_bcd2(bcd2_1, &value_1);
  decimal_to_bcd2(bcd2_2, &value_2);
  bcd_2_to_10(bcd2_1);
  bcd_2_to_10(bcd2_2);
  int max_point = point1;
  if (point1 > point2) shift_bcd_10(bcd2_2, point2 - point1);
  if (point1 < point2) {
    max_point = point2;
    shift_bcd_10(bcd2_1, point1 - point2);
  }
  return max_point;
}