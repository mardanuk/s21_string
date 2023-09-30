#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  for (; *str1 != '\0' && !result; str1++) {
    for (char *substr = (char *)str2; *substr != '\0' && !result; substr++) {
      if (*str1 == *substr) result = (char *)str1;
    }
  }
  return result;
}
