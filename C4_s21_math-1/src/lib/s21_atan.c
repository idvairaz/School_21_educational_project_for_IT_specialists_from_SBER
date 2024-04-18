#include "../s21_math.h"
/**
 * @brief Функция s21_atan() вычисляет арктангенс x, то есть число, тангенс
 * которого равен x. Значение арктангенса математически определено в диапазоне
 * от -Пи/2 до Пи/2 включительно.
 * @param x тангенс числа
 * @return арктангенс числа в радианах
 */
long double s21_atan(double x) {
  long double res = 0;
  if (S21_IS_NAN(x)) {
    res = x;
  } else if (S21_IS_INF(x)) {
    res = x > 0 ? S21_PI / 2.0 : -S21_PI / 2.0;
  } else if (x < -1.0 || x > 1.0) {
    res = (x > 0 ? S21_PI / 2.0 : -S21_PI / 2.0) - s21_atan(1 / x);
  } else {
    long double row = x;
    int i = 1;
    while (s21_fabs((double)row) > 1e-7) {
      res += row;
      i += 2;
      row *= -x * x * (i - 2) / i;
    }
  }
  return res;
}