#include "../s21_math.h"

/**
 * @brief Функция для нахождения остатка от деления чисел с плавающей точкой.
 * @param x делимое (double)
 * @param y делитель (double)
 * @return остаток от деления (long double)
 */
long double s21_fmod(double x, double y) {
  long double res = S21_NAN;
  if (!S21_IS_INF(x) && !S21_IS_NAN(x) && !S21_IS_NAN(y) && y != 0) {
    if (S21_IS_INF(y)) {
      res = (long double)x;
    } else {
      double n = x / y;
      res = (long double)x -
            (n > 0 ? s21_floor(n) : s21_ceil(n)) * (long double)y;
    }
  }
  return res;
}
