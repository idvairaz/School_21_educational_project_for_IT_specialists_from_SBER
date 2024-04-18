#include "../s21_math.h"

/**
 * @brief Функция для вычисления абсолютного значения числа с плавающей запятой
 * двойной точности
 * @param x число с плавающей запятой двойной точности типа double, для которого
 * необходимо найти его абсолютное значение.
 * @return абсолютное значение введенного числа x
 */
long double s21_fabs(double x) {
  long double result;
  if (S21_IS_INF(x)) {
    result = S21_INF;
  } else {
    if (S21_IS_NAN(x)) {
      result = S21_NAN;
    } else {
      result = (x < 0) ? -x : x;
    }
  }
  return result;
}