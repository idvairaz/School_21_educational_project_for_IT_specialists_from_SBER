#include "../dev/print_int_to_bits.c"
#include "../s21_decimal.h"

void print_decimal_2(unsigned int *value, short direction, short COUNT_INT) {
  // in memory: (0 1 2 3) 0-11 bytes -> 0:01234 1:01234 ... 0-95 bits ->
  // 0:012345678...31 1:012345678...31 2:0:012345678...31
  if (direction == _DIRECT_MEM_VIEW) {
    for (int j = 0; j < COUNT_INT; j++, value++) {
      print_int_to_bits(*value, direction);
      printf("\n");
    }
  }
  if (direction == _NORMAL_BIT_VIEW) {
    value = value + (COUNT_INT - 1);
    for (int j = COUNT_INT - 1; j >= 0; j--, value--) {
      print_int_to_bits(*value, direction);
      printf("\n");
    }
  }
}