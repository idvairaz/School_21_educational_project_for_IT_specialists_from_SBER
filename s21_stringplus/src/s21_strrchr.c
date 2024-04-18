#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Выполняет поиск последнего вхождения символа c (беззнаковый тип)
в строке, на которую указывает аргумент str*/

char *s21_strrchr(const char *str, int c) {
  char *result = (char *)s21_NULL;
  do {
    if (*str == (unsigned char)c) {
      result = (char *)str;
    }
  } while (*str++);
  return result;
}

/* Функция strchr ищет последнее вхождения символа, код которого указан
 в аргументе ch, в строке, на которую указывает аргумент str */