#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *concatPosition = dest + s21_strlen(dest);
  for (s21_size_t i = 0; i < n && *src; concatPosition++, i++, src++) {
    *concatPosition = *src;
  }
  *concatPosition = '\0';
  return dest;
}
