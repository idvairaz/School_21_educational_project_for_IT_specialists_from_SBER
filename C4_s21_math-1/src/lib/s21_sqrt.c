#include "../s21_math.h"

/*computes square root of x*/
long double s21_sqrt(double x) {
  if (x < 0) {
    return S21_NAN;
  }
  return x == 0 ? 0.0 : s21_pow(x, 0.5);
}