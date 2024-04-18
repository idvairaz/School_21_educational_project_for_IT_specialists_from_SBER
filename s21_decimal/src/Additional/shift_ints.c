#include "../s21_decimal.h"

int shift_ints(unsigned int *value, short num_direction, short COUNT_INT) {
  int error = 0;
  if (num_direction > 0) {
    *(value) = *(value) >> 1;
    for (int i = 1; i < COUNT_INT; i++) {
      if (*(value + i) & _1BIT)
        *(value + i - 1) |= _32BIT;
      else
        *(value + i - 1) &= ~(_32BIT);
      *(value + i) = *(value + i) >> 1;
    }
    num_direction--;
  }
  if (num_direction < 0) {
    for (int i = COUNT_INT - 1; i >= 1; i--) {
      *(value + i) = *(value + i) << 1;
      if (*(value + i - 1) & _32BIT) *(value + i) |= _1BIT;
    }
    *(value) = *(value) << 1;
    num_direction++;
  }
  if (num_direction) shift_ints(value, num_direction, COUNT_INT);
  return error;
}