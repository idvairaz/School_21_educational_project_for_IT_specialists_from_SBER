#include "../s21_math.h"

/**
 * @brief Функция для округдения числа с плавающей запятой сторону
 * плюс бесконечности или минус бесконечности, в зависимости от режима rounding
 * (1 или -1).
 * @param x число с плавающей запятой, которое нужно округлить.
 * @param rounding режим округления: 1 - плюс бесконечность; -1 - минус
 * бесконечность.
 * @return ближайшее целочисленное значение, большее, меньшее или равное
 * входящему числу x.
 */
long double s21_ceil_or_floor(double x, int rounding) {
  long double result = x;
  if (!S21_IS_NAN(x) && !S21_IS_INF(x)) {
    double tmp = x;
    if (x < 0) tmp *= -1;
    result = 0;
    if (tmp > 999999999999999) {
      result = tmp;
    } else {
      unsigned long long mantissa = tmp;
      result = mantissa;
      if (tmp != mantissa &&
          ((rounding == 1 && x > 0) || (rounding == -1 && x < 0))) {
        result += 1;
      }
    }
    if (x < 0) result *= -1;
  }
  return result;
}