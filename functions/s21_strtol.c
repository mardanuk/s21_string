#include "../headers/s21_common.h"

/*
 *  s <=> inputString
 *  a <=> accumulator
 *  neg <=> isNegative
 *  f <=> validFlag
 *  cl <=> cutoffLimit
 *  c <=> currentChar
 */
long long s21_strtol(const char *origInputString, char **endPtr, int b) {
  const char *s = origInputString;
  long long a = 0, cl, f = 0;
  int neg = 0;
  while (isspace((unsigned char)*s)) s++;
  if (*s == '-')
    neg = 1, s++;
  else if (*s == '+')
    s++;
  if ((b == 0 || b == 16) && *s == '0' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
    s += 2, b = 16;
  if (b == 0) b = (*s == '0') ? 8 : 10;
  long cut = neg ? LONG_MIN : LONG_MAX;
  cl = cut % b;
  cut /= b;
  for (; *s; s++) {
    long long c = tolower((unsigned char)*s);
    if (isdigit(c))
      c -= '0';
    else if (isalpha(c))
      c -= 'a' - 10;
    else
      break;
    if (c >= b) break;
    if (f < 0) continue;
    if (neg) {
      if (a < cut || (a == cut && c > cl))
        f = -1, a = LONG_MIN, errno = ERANGE;
      else
        f = 1, a *= b, a -= c;
    } else {
      if (a > cut || (a == cut && c > cl))
        f = -1, a = LONG_MAX, errno = ERANGE;
      else
        f = 1, a *= b, a += c;
    }
  }
  if (endPtr != S21_NULL) *endPtr = (char *)(f ? s - 1 : origInputString);
  return a;
}