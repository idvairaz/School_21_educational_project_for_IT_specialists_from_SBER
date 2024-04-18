#include "../s21_decimal.h"
#ifndef PRINT_INT
#define PRINT_INT

void print_int_to_bits(unsigned int value, short direction) {
  if (direction == _DIRECT_MEM_VIEW) {
    for (int i = 0; i < _SIZE_BYTE * _SIZE_INT_BYTE; i++) {
      printf("%d", (value & ((unsigned)1 << i)) > 0);
      if (((i + 1) % _SIZE_BYTE) == 0) printf("  ");
    }
  }
  if (direction == _NORMAL_BIT_VIEW) {
    for (int i = _SIZE_BYTE * _SIZE_INT_BYTE - 1; i >= 0; i--) {
      printf("%d", (value & ((unsigned)1 << i)) > 0);
      if (((_SIZE_BYTE * _SIZE_INT_BYTE - i) % _SIZE_BYTE) == 0) printf("  ");
    }
  }
}

#endif