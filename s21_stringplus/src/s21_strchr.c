#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str. */

char *s21_strchr(const char *str, int c) {
  const char *p = str;
  char *result = s21_NULL;
  int found = 0;

  while (!found && *p) {
    if (*p == (char)c) {
      result = (char *)p;
      found = 1;
    }
    if (!found) {
      p++;
    }
  }
  if ((char)c == '\0' && !found) {
    result = (char *)p;
  }
  return result;
}

/*Функциb strchr() возвращают указатель на совпадающий символ или
 * NULL, если символ не найден в данной области памяти.*/

/* Особенности функции: ищет пока не встретится символ конца строки(!!!) или не
 * закончится строка*/
