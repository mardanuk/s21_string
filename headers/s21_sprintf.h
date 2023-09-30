#include "../s21_string.h"
#include "s21_common.h"

#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#define S21_VALUE_LESS_THAN_10 9.99999f
#define S21_VALUE_LESS_THAN_1 0.99999f

#define S21_RANK_UPPER_BOUND 0
#define S21_RANK_LOWER_BOUND (-6)

#define S21_VALUE_UPPER_BOUND 1.0f
#define S21_VALUE_LOWER_BOUND 0.000001f

#define MAX_HEX_VALUE 0xffffffff
#define S21_HEX_PREFIX_LENGTH (2)

#define S21_FORMAT_MANTISSA_STRING "%.*f%c%+03d\n"

int getShiftSizeValue(IPattern *, int);

int makeWidthTransform(char *, IPattern *, int, int *, int);

void setSign(IPattern *, int, char *);

int calculateActualAccuracy(float, int, int);

void compilePatternSpecifier_c(IPattern *, int);

void compilePatternSpecifier_s(IPattern *, va_list, int *);

void compilePatternSpecifier_integer(IPattern *, long int, int, int *);

void compilePatternSpecifier_float(IPattern *, long double, int *);

void compilePatternSpecifier_e(IPattern *, double, int, int *);

void compilePatternSpecifier_x(IPattern *, long int, int *);

void compilePatternSpecifier_g(IPattern *, float, int *);

void compilePatternSpecifier_n(IPatternsConfig *, int *, int);

void scientificNotation(IPattern *, double, int, char *);

void handleAsterisk(IPattern *, va_list);

void compilePatterns(IPatternsConfig *, va_list, int, int *);

int assignPrintedLengthToValue(IPatternsConfig *, char *, int);

int getEndIndex(IPatternsConfig *, int, const char *);

void appendPatternValue(char *, IPatternsConfig *, int);

int applyAllPatterns(IPatternsConfig *, char *, const char *);

void formatPatternBeforeCompiling(IPattern *);

#endif