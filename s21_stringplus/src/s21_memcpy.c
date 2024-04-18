#include "s21_string.h"

/*latinato pennytrg 26/02/2024*/

/* копирует n байт в указанную область. */

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

/*Функция  memcpy  возвращает указатель на начало блока памяти  dest , куда были
скопированы данные. Это позволяет использовать результат  memcpy  для
дальнейшей обработки или передачи другим функциям. */