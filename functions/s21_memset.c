#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *dest = str;
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = (char)c;
  }
  return dest;
}
