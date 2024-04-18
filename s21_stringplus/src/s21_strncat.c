#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Добавляет строку, на которую указывает src, в конец строки, на которую
указывает dest, длиной до n символов(в MAN указано в байтах) */

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

/* Функция возвращает указатель на массив, в который добавлена строка
(destination).
Особенности функции: strncat добавляет в строку, на которую указывает
аргумент destination, строку, на которую указывает аргумент append, пока не
встретится символ конца строки(!!!) или пока не будет добавлено n символов.*/