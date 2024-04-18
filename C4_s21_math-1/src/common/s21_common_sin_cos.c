#include "../s21_math.h"

/*computes sinus or cosinus of a double x number (radians)
flag: 1 for sin, -1 for cos
returns: long double computed result*/
long double s21_common_sin_cos(double x, int flag) {
  long double sum_row = 0;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    sum_row = S21_NAN;
  } else {
    if (s21_fabs(x) > 2 * S21_PI) x = (double)s21_fmod(x, 2 * S21_PI);
    long double row = flag == 1 ? x : 1;
    int i = 1;
    while (s21_fabs((double)row) > 1e-9) {
      sum_row += row;
      row = (-1) * row * (x * x) / ((2 * i + flag) * (2 * i));
      i++;
    }
  }
  return sum_row;
}