#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (; *str && *str != c; str++)
    ;
  if (c != '\0' && *str == '\0') str = S21_NULL;
  return (char *)str;
}