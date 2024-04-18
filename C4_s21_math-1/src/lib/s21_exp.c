#include "../s21_math.h"

/*returns e in power of x*/
long double s21_exp(double x) {
  long double result = 1.0;
  if (x > 11355.0) {
    result = S21_INF;
  } else if (x < -11355.0) {
    result = 0;
  } else if (x < 0) {
    result = 1.0 / s21_exp(-x);
  } else {
    long double row = 1.0;
    for (int i = 1; i < 500; i++) {
      row *= x / i;
      result += row;
    }
  }
  return result;
}