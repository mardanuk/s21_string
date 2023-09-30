#include "../s21_string.h"
#include "s21_dynamic_arrays.h"

#ifndef S21_COMMON_H_
#define S21_COMMON_H_

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <regex.h>
#include <stdarg.h>
#include <stdlib.h>

#define S21_MAX_GROUPS 15

#define S21_BUFFER_SIZE_4096 4096
#define S21_BUFFER_SIZE_1024 1024
#define S21_INIT_COUNT 4
#define S21_APPEND_COUNT 4
#define S21_MAX_PRECISION 1000
#define S21_COMMAND_SYMBOL_UPPER_BOUND ' '

#define REG_EXPRESSION_FORMAT                                                \
  "(%([-+ "                                                                  \
  "#0]{0,20})(([1-9][0-9]{0,9})|\\*)?(\\.([0-9]{0,10}|\\*))?([hlL]{0,10})([" \
  "cdieEfgGosuxXpn]))"

#define GET_SUBSTRING_CODE(INDEX, FIELD)                          \
  s21_memset(tempString, 0, s21_strlen(tempString));              \
  getSubstringFromString(regCompiled, format, INDEX, tempString); \
  config->patterns[patternIndex].FIELD = fromStringToCode(tempString);

#define GET_SUBSTRING_VALUE(INDEX, FIELD)                                  \
  s21_memset(tempString, 0, s21_strlen(tempString));                       \
  getSubstringFromString(regCompiled, format, INDEX, tempString);          \
  code = tempString[0] == '*' ? SymbolCode_asterisk                        \
                              : (int)s21_strtol(tempString, S21_NULL, 10); \
  config->patterns[patternIndex].FIELD = code;

#define S21_OCTAL_SYMBOLS "+01234567"
#define S21_DECIMAL_SYMBOLS "-+0123456789"
#define S21_UNSIGNED_DECIMAL_SYMBOLS "+0123456789"
#define S21_FLOAT_SYMBOLS "-+0123456789.e"
#define S21_HEX_SYMBOLS "+-0123456789ABCDEFabcdefxX"

#define IS_ACCEPTABLE_SYMBOL(CORRECT_SYMBOLS, SYMBOL) \
  s21_strchr(CORRECT_SYMBOLS, SYMBOL)

int getSubstringFromString(regex_t *regexp, const char *inputString,
                           int groupNumber, char *string);

int isStrDelim(char ch, const char *delim);

long double getRounder(int index);

int isEmptyString(const char *string);

int isSpaceSymbol(char c);

void reverseString(char str[], int length);

void clearDecimalPart(char *decimal);

void handleMantissaInString(char *token, char *decimal, char *mantissa,
                            char *mantissaString);

char *getMantissaString(IPattern *pattern);

char getMantissaSymbol(IPattern *pattern);

char getSpaceChar(IPattern *pattern);

int getStartIndex(IPattern *, int index);

void handleUpperCase(IPattern *pattern, char *tempString);

void removeTrailingZeros(IPattern *pattern, char *string);

char *allocBuffer(size_t length, int *errorCode);

int isOctal(const char *string);

int isHex(const char *string);

int fromCharToCode(int code, int ch);

int strncpyType(char *dest, const char *src, s21_size_t n,
                char *correctSymbols);

int strncpyString(char *dest, const char *src, s21_size_t n);

void clearBuffer(char *buffer, size_t size);

int skipCommandSymbols(const char *buffer);

int fromStringToCode(const char *string);

void parseFormatString(IPatternsConfig *config, const char *format);

int fillPatternInfo(IPatternsConfig *config, regex_t *regCompiled,
                    const char *format);

#endif
