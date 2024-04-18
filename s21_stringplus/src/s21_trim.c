#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/*Возвращает новую строку, в которой удаляются все начальные и конечные
вхождения набора заданных символов (trim_chars) из данной строки (src). В
случае какой-либо ошибки следует вернуть значение NULL.*/

void *s21_trim(const char *src, const char *trim_chars) {
  void *return_value = s21_NULL;
  if (src != s21_NULL && trim_chars != s21_NULL) {
    const char *start = src;
    const char *end = src + s21_strlen(src) - 1;

    while (*start && s21_strchr(trim_chars, *start) != s21_NULL) {
      start++;
    }

    while (end >= start && s21_strchr(trim_chars, *end) != s21_NULL) {
      end--;
    }

    s21_size_t result_len = end - start + 1;
    char *result = (char *)calloc(result_len + 1, sizeof(char));
    s21_memcpy(result, start, result_len);
    result[result_len] = '\0';

    return_value = result;
  }

  return return_value;
}