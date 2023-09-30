#include "../headers/s21_common.h"

void *s21_to_lower(const char *str) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    result = calloc(s21_strlen(str) + 1, sizeof(char));
    s21_strncpy(result, str, s21_strlen(str));
    int i = 0;
    for (char *ptr = result; ptr && *ptr; ptr++, i++)
      if (*ptr >= 'A' && *ptr <= 'Z') result[i] = *ptr + ('a' - 'A');
  }
  return (void *)result;
}