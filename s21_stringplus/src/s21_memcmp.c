#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* n – размер сравниваемой части массива в байтах. */

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;
  s21_size_t i = 0;

  for (; i < n && s1[i] == s2[i]; i++)
    ;

  return (i == n) ? 0 : (int)(s1[i] - s2[i]);
}
/*Возвращет целочисленный ноль, если равны.*/
/*Если блок  str1  меньше блока  str2  (в лексикографическом порядке), то memcmp
возвращает отрицательное число.

Если блок  str1  больше блока  str2  (в лексикографическом порядке), то  memcmp
возвращает положительное число. */