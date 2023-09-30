#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  for (s21_size_t i = 0; i < n && (diff = *(unsigned char *)str1++ -
                                          *(unsigned char *)str2++) == 0;
       i++)
    ;
  return diff;
}