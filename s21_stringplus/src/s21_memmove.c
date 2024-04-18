#include "s21_string.h"

/*Функция memmove копирует n байт из массива (области памяти), на который
указывает аргумент source, в массив (область памяти), на который указывает
аргумент destination. При этом массивы (области памяти) могут пересекаться.*/

void *s21_memmove(void *destination, const void *source, s21_size_t n) {
  unsigned char *dest = (unsigned char *)destination;
  const unsigned char *src = (const unsigned char *)source;
  if (src < dest && dest < src + n) {
    src += n;
    dest += n;
    while (n--) {
      *(--dest) = *(--src);
    }
  } else {
    while (n--) {
      *dest++ = *src++;
    }
  }
  return destination;
}