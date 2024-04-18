#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/*Возвращает копию строки (str), преобразованной в нижний регистр. В случае
какой-либо ошибки следует вернуть значение NULL.*/

void *s21_to_lower(const char *str) {
  void *return_value = s21_NULL;
  if (str != s21_NULL) {
    char *result = (char *)calloc(s21_strlen(str) + 1, sizeof(char));

    if (result != s21_NULL) {
      s21_size_t index = 0;
      while (str[index] != '\0') {
        if (str[index] >= 'A' && str[index] <= 'Z') {
          result[index] = str[index] + ('a' - 'A');
        } else {
          result[index] = str[index];
        }
        index++;
      }
      return_value = result;
    }
  }
  return return_value;
}
