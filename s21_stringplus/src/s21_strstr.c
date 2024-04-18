#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Находит первое вхождение всей строки needle (не включая завершающий нулевой
символ), которая появляется в строке haystack..*/

char *s21_strstr(const char *haystack, const char *needle) {
  const char *p1 = haystack;
  const char *p2 = needle;
  const char *temp = s21_NULL;
  int found = 1;

  while (*p1 && *p2) {
    if (*p1 == *p2) {
      if (found) {
        found = 0;
        temp = p1;
      }
      p1++;
      p2++;
    } else {
      if (!found) {
        p1 = temp + 1;
        found = 1;
        p2 = needle;
      } else {
        p1++;
      }
    }
  }
  return (*p2 == '\0') ? (char *)(p1 -= s21_strlen(needle)) : (char *)s21_NULL;
}

/* Особенности функции: strstr() возвращает указатель на первое вхождение в
строку, на которую указывает str1, строки, указанной str2(исключая
завершающий нулевой символ).

Возвращет: указатель на начало найденной подстроки или NULL, если
подстрока не найдена.*/