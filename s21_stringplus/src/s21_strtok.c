#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Разбивает строку str на ряд токенов, разделенных delim.*/

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;
  char *result = s21_NULL;
  int found = 0;
  if (delim == s21_NULL) {
    found = 1;
  } else {
    if (str != s21_NULL) {
      // Пропускаем начальные разделители
      while (*str != '\0' && s21_strchr(delim, *str) != s21_NULL) {
        str++;
      }
      last_token = str;
    }
    if (last_token != s21_NULL && *last_token != '\0') {
      // Находим начало следующего токена
      char *token = last_token;
      char *p = s21_strpbrk(token, delim);

      if (p != s21_NULL) {
        *p = '\0';
        last_token = p + 1;
        // Пропускаем последующие разделители, чтобы last_token указывал на
        // начало следующего токена
        while (*last_token != '\0' &&
               s21_strchr(delim, *last_token) != s21_NULL) {
          last_token++;
        }
        // Если после последнего токена идут только разделители, сбрасываем
        // last_token
        if (*last_token == '\0') {
          last_token = s21_NULL;
        }
      } else {
        // Если больше нет разделителей, значит, это последний токен
        last_token = s21_NULL;
      }
      result = token;
    }
  }
  if (found) {
    result = s21_NULL;
  }
  return result;
}

/* Особенности функции: 1) работает до '\0'; 2) Не выводит при повторении delim

Возвращет: NULL – если строку str невозможно разделить на части.
Указатель на первый символ выделенной части строки.*/