#include "../headers/s21_common.h"

void *s21_insert(const char *src, const char *str, s21_size_t startIndex) {
  char *result = S21_NULL;
  if (src && str && startIndex <= s21_strlen(src)) {
    result = calloc((s21_strlen(src) + s21_strlen(str) + 1), sizeof(char));
    s21_strncpy(result, src, startIndex);
    s21_strncpy(result + startIndex, str, s21_strlen(str));
    s21_strncpy(result + s21_strlen(str) + startIndex, src + startIndex,
                s21_strlen(src));
  }
  return (void *)result;
}