#include "../s21_string.h"

char *s21_strrchr(const char *s, int c) {
  char *returnChar = 0;
  do {
    if (*s == c) returnChar = (char *)s;
  } while (*s++);
  return returnChar;
}