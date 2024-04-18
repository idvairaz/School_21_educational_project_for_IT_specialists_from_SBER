#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.*/

char *s21_strpbrk(const char *str1, const char *str2) {
  char *temp = s21_NULL;
  char *str1_temp = (char *)str1;
  char *str2_temp = (char *)str2;
  int found = 0;
  for (; *str1_temp && !found; str1_temp++) {
    for (temp = str2_temp; *temp && !found; temp++) {
      if (*str1_temp == *temp) {
        found = 1;
      }
    }
  }
  return found > 0 ? str1_temp - 1 : s21_NULL;
}

/*Возвращет: 1) NULL если не один символ из cтроки str2 не найден в строке str1;
2) Указатель на первый найденный в строке str1 символ из множества символов
строки str2.*/