#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  if (needle == S21_NULL || !*needle) res = (char *)haystack;
  for (int i = 0; haystack[i] != '\0' && !res; i++) {
    int k = i;
    for (int j = 0; needle[j] != '\0' && !res && haystack[k] == needle[j];
         j++, k++) {
      if (needle[j + 1] == '\0') res = (char *)(haystack + i);
    }
  }
  return res;
}