#include "../headers/s21_common.h"

long double s21_atof(const char *str) {
  long double number, rank;
  int sign = 1;
  while (*str && isspace(*str)) ++str;
  if (*str == '+') ++str;
  if (*str == '-') {
    sign = -1;
    ++str;
  }
  for (number = 0; *str && isdigit(*str); ++str)
    number = number * 10 + (*str - '0');
  if (*str == '.') ++str;
  for (rank = 1.; *str && isdigit(*str); ++str, rank *= 10.)
    number = number * 10. + (*str - '0');
  return (number * sign / rank);
}