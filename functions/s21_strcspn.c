#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *result = s21_strpbrk(str1, str2);
  s21_size_t index;
  if (result != S21_NULL)
    index = result - str1;
  else
    index = s21_strlen(str1);
  return index;
}
