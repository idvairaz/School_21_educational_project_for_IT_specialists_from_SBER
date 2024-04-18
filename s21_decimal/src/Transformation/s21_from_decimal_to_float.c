#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_value = 0;
  int valid_dec = is_bad_decimal(src);
  int exp = get_exp_10(src);
  s21_decimal max_dec = {0};
  s21_decimal min_dec = {0};
  float max_f = 7.92281577919e+28;
  s21_from_float_to_decimal(max_f, &max_dec);
  float min_f = -7.92281577919e+28;
  s21_from_float_to_decimal(min_f, &min_dec);
  if (valid_dec == 1 || dst == NULL) {
    return_value = 1;
  } else if (s21_is_greater_or_equal(src, max_dec)) {
    *dst = max_f;
  } else if (s21_is_less_or_equal(src, min_dec)) {
    *dst = min_f;
  } else {
    bool sign = get_sign(src);
    *dst = 0.0;
    double res = 0.0;
    for (int i = 0; i < _MAX_DECIMAL_DIGIT_INT * 32; i++) {
      res = res + get_bit(src, i) * pow(2, i);
    }
    res = res * pow(10.0, -exp);
    if (sign) {
      res = res * -1.0;
    }
    *dst = (float)res;
  }
  return return_value;
}