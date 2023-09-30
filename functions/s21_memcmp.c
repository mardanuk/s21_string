#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *chr1 = str1;
  const char *chr2 = str2;
  for (s21_size_t i = 0; i < n && !result; i++) {
    if (*(chr1 + i) != *(chr2 + i)) {
      result = (*(chr1 + i) - *(chr2 + i));
    }
  }
  return result;
}
