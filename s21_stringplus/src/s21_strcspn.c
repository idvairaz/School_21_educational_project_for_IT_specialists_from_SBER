#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/*Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2.*/

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  int found = 0;
  for (s21_size_t i = 0; str1[i] && !found; i++) {
    for (s21_size_t j = 0; str2[j] && !found; j++) {
      if (str1[i] == str2[j]) {
        found = 1;
      }
    }
    if (!found) {
      count++;
    }
  }
  return count;
}

/*Функция возвращает: Длина начального участка строки, не содержащая символов
указанных в аргументе str2..
Особенности функции : отрабатывает до '\0'*/