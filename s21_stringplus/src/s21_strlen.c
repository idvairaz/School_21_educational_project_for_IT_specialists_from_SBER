#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Вычисляет длину строки str, не включая завершающий нулевой символ.*/

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  for (; str[len]; len++)
    ;
  return len;
}

/* Возвращает переменную типа size_t (длину строки) до \0.*/