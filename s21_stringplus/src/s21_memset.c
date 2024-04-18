#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* Заполняет части массива в байтах определенным значением.*/

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char value = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = value;
  }
  return str;
}
/*Возвращаемое значение функции  memset  - указатель на начало блока памяти  str
. Это позволяет использовать результат  memset  для дальнейшей обработки или
передачи другим функциям. */