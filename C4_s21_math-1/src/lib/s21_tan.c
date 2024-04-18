#include "../s21_math.h"

/*computes tan of a double x number (radians)
returns: long double computed result*/
long double s21_tan(double x) {
  long double tan = 0;

  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    tan = S21_NAN;
  } else {
    tan = s21_sin(x) / s21_cos(x);
  }
  return tan;
}