#include "../headers/s21_common.h"

char *s21_itoa(long int num, char *str, int base) {
  int index = 0;
  int isNegative = 0;
  if (num == 0) {
    str[index++] = '0';
    str[index] = '\0';
    return str;
  }
  if (num < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }
  while (num != 0) {
    int rem = num % base;
    if (rem > 9)
      str[index++] = (char)((rem - 10) + 'a');
    else
      str[index++] = (char)(rem + '0');
    num = num / base;
  }
  if (isNegative) str[index++] = '-';
  str[index] = '\0';
  reverseString(str, index);
  return str;
}
