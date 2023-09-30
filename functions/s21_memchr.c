#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *result = S21_NULL;
  const char *ptr = str;
  int flag = 1;
  for (s21_size_t i = 0; i < n && flag; i++) {
    if (*(ptr + i) == c) {
      result = (void *)(ptr + i);
      flag = 0;
    }
  }
  return result;
}
