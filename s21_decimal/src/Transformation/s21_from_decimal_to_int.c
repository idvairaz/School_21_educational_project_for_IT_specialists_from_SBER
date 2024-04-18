#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_decimal src2 = {0};
  int error = s21_truncate(src, &src2);
  if (!error) error = src2.bits[1] || src2.bits[2];
  if (!error) {
    *dst = src2.bits[0];
    if (get_sign(src2)) {
      *dst = -(*dst);
    }
  }
  return error;
}