#include "s21_string.h"

/* Функция strcat добавляет в строку, на которую указывает аргумент destination,
строку, на которую указывает аргумент append. Символ конца строки помещается в
конце объединенных строк. Если строки перекрываются, результат объединения будет
не определен. */

char *s21_strcat(char *dest, const char *src) {
  char *start = dest;
  while (*dest) dest++;
  while (*src) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return start;
}