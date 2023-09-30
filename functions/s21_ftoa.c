#include "../headers/s21_common.h"

void handleFractionalPart(long double inputNum, char **outputPtr,
                          int precision) {
  if (precision) {
    *(*outputPtr)++ = '.';
    while (precision--) {
      inputNum *= 10.0;
      int c = (int)inputNum;
      *(*outputPtr)++ = '0' + c;
      inputNum -= c;
    }
  }
}

void handleIntegerPart(long double intPart, char **outputPtr) {
  char *p, *remPtr;

  if (!intPart) {
    *(*outputPtr)++ = '0';
  } else {
    p = *outputPtr;
    while (intPart >= 1) {
      *p++ = '0' + (int)fmodl(intPart, 10.L);
      intPart /= 10;
    }
    remPtr = p;
    while (p > *outputPtr) {
      int c = *--p;
      *p = *(*outputPtr);
      *(*outputPtr)++ = (char)c;
    }
    *outputPtr = remPtr;
  }
}

char *s21_ftoa(long double inputNum, char *buf, int precision) {
  char *outputPtr = buf;

  if (precision > S21_MAX_PRECISION) precision = S21_MAX_PRECISION;
  if (precision < 0) precision = 0;

  if (inputNum < 0) {
    inputNum = -inputNum;
    *outputPtr++ = '-';
  }

  inputNum += getRounder(precision);

  long double intPart = 0;
  modfl(inputNum, &intPart);
  inputNum -= intPart;

  handleIntegerPart(intPart, &outputPtr);

  handleFractionalPart(inputNum, &outputPtr, precision);

  *outputPtr = 0;
  return buf;
}