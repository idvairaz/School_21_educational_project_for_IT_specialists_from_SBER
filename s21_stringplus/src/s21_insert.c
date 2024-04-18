#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/*Возвращает новую строку, в которой указанная строка (str)
вставлена в указанную позицию (start_index) в данной строке (src).
В случае какой-либо ошибки возвращает значение NULL.*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *return_value = s21_NULL;
  if (src != s21_NULL && str != s21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    return_value = (char *)calloc(src_length + str_length + 1, sizeof(char));
    if (return_value != s21_NULL) {
      s21_strncpy(return_value, src, start_index);
      return_value[start_index] = '\0';
      s21_strncat(return_value, str, str_length);
      s21_strncat(return_value, src + start_index, src_length);
    }
  }
  return return_value;
}