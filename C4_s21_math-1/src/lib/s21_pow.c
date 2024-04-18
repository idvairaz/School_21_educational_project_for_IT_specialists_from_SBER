#include "../s21_math.h"
/*raises a number (base) to the given power (exponent)*/
long double s21_pow(double base, double exponent) {
  long double result;
  int sign = 0;
  if ((S21_IS_NAN(base) && exponent != 0) ||
      (S21_IS_NAN(exponent) && base != 1.0)) {
    result = S21_NAN;
  } else if (exponent == 0.0) {
    result = 1.0;
  } else if (s21_fabs(base) == 1.0 && !(exponent > 0 && exponent < 1)) {
    if (S21_IS_INF(exponent) || s21_fabs(exponent) == 1.0 ||
        S21_IS_NAN(exponent) ||
        (((double)((long long int)exponent) - exponent == 0) &&
         (long long int)exponent % 2 == 0)) {
      result = 1;
    } else
      result = S21_NAN;
  } else if ((base == 0.0 && exponent < 0) || (base > 1 && exponent >= 9999) ||
             (S21_IS_INF(base) && exponent > 0) ||
             (s21_fabs(base) > 1 && S21_IS_INF(exponent) && exponent > 0)) {
    result = S21_IS_INF(base) && exponent == 1.0 ? base : S21_INF;
  } else if ((S21_IS_INF(exponent) && exponent < 0 && s21_fabs(base) > 1) ||
             (exponent < -9999 && s21_fabs(base) > 1) ||
             (S21_IS_INF(base) && exponent < 0) ||
             (base != 0 && s21_fabs(base) < 1 && S21_IS_INF(exponent) &&
              exponent > 0)) {
    result =
        base > 0 || S21_IS_INF(exponent) ||
                (!(S21_IS_INF(exponent) && base != 0 && s21_fabs(base) < 1) &&
                 exponent != -1)
            ? 0.0
            : -0.0;
  } else if (S21_IS_INF(exponent) && exponent < 0 && base != 0 &&
             s21_fabs(base) < 1) {
    result = S21_INF;
  } else {
    if (base < 0) {
      if ((exponent - (double)(long long)exponent) == 0) {
        if ((long long)exponent % 2 != 0) sign = 1;
        result = s21_exp(exponent * (double)s21_log(-base));
      } else
        result = S21_NAN;
    } else {
      if ((exponent - (double)(long long)exponent) == 0) {
        result = base;
        if (exponent > 0)
          for (int i = 0; i < exponent - 1; i++) result *= base;
        else
          for (int i = 0; i < -exponent + 1; i++) result /= base;
      } else
        result = s21_exp(exponent * (double)s21_log(base));
    }
  }
  return sign ? -result : result;
}