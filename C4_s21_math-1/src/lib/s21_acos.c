#include "../s21_math.h"
/**
 * @brief Функция s21_acos() вычисляет арккосинус от x, то есть величину,
 * косинус которой равен x
 * @param x Функция принимает единственный аргумент (1 ≥ x ≥ -1)
 * @return арккосинус числа в радианах
 */
long double s21_acos(double x) {
  long double res = 0;
  if (x > 0 && x < 1) {
    res = s21_atan((double)s21_sqrt(1 - (x * x)) / x);
  } else if (x >= -1 && x < 0) {
    res = S21_PI + s21_atan((double)s21_sqrt(1 - (x * x)) / x);
  } else if (x == 1) {
    res = 0;
  } else if (x == 0) {
    res = S21_PI / 2;
  } else {
    res = S21_NAN;
  }
  return res;
}