#include "../headers/s21_sscanf.h"

int getLengthStringBeforeSpecifier(IPattern *pattern, int startStringIndex,
                                   int skipValue) {
  return pattern->startIndexInFormat - (startStringIndex + skipValue);
}

void prepareDataForSearch(IPatternsConfig *config, const char *format) {
  IPattern *patterns = config->patterns;
  for (int i = 0; i < config->count; ++i) {
    int startStringIndex = getStartIndex(patterns, i);
    format += startStringIndex;
    int skipValue = skipCommandSymbols(format);
    format -= startStringIndex;
    format += startStringIndex + skipValue;
    int length = getLengthStringBeforeSpecifier(&patterns[i], startStringIndex,
                                                skipValue);
    s21_strncpy(patterns[i].value, format, length);
    format -= startStringIndex + skipValue;
  }
}

void assignInt(IPattern *pattern, char *tempString, va_list args, int base) {
  if (pattern->length & PatternLength_L)
    *va_arg(args, long long int *) =
        (long long)s21_strtol(tempString, S21_NULL, base);
  else if (pattern->length & PatternLength_l)
    *va_arg(args, long int *) = (long)s21_strtol(tempString, S21_NULL, base);
  else
    *va_arg(args, int *) = (int)s21_strtol(tempString, S21_NULL, base);
}

void assignFloat(IPattern *pattern, char *tempString, va_list args) {
  if (pattern->length & PatternLength_L)
    *va_arg(args, long double *) = s21_atof(tempString);
  else if (pattern->length & PatternLength_l)
    *va_arg(args, double *) = (double)s21_atof(tempString);
  else
    *va_arg(args, float *) = (float)s21_atof(tempString);
}

void assignString(char *tempString, va_list args, s21_size_t length) {
  s21_strncpy(va_arg(args, char *), tempString, length);
}

int getValuesFromBuffer(IPatternsConfig *config, char *valueString,
                        s21_size_t index, va_list args) {
  int assignStatus = 0;
  IPattern *pattern = &config->patterns[index];
  if (!(pattern->isSkippable) && !isEmptyString(valueString)) {
    assignStatus = 1;
    if (pattern->specifier & (PatternSpecifier_d | PatternSpecifier_u))
      assignInt(pattern, valueString, args, 10);
    else if (pattern->specifier == PatternSpecifier_o)
      assignInt(pattern, valueString, args, 8);
    else if (pattern->specifier == PatternSpecifier_i) {
      int base = isOctal(valueString) ? 8 : 10;
      base = isHex(valueString) ? 16 : base;
      assignInt(pattern, valueString, args, base);
    } else if (pattern->specifier & (PatternSpecifier_x | PatternSpecifier_X)) {
      assignInt(pattern, valueString, args, 16);
    } else if (pattern->specifier == PatternSpecifier_f) {
      assignFloat(pattern, valueString, args);
    } else if (pattern->specifier & (PatternSpecifier_s | PatternSpecifier_c)) {
      assignString(valueString, args, s21_strlen(valueString));
    } else
      assignStatus = 0;
  }
  return assignStatus;
}
int getSubstringValueFromBuffer(char *tempString, IPattern *pattern,
                                const char *buffer, int widthToParse,
                                int indexOfActualValue) {
  int actualWidth = 0;
  if (pattern->specifier & (PatternSpecifier_i))
    actualWidth = strncpyType(tempString, buffer + indexOfActualValue,
                              widthToParse, S21_HEX_SYMBOLS);
  else if (pattern->specifier & (PatternSpecifier_d | PatternSpecifier_u))
    actualWidth = strncpyType(tempString, buffer + indexOfActualValue,
                              widthToParse, S21_DECIMAL_SYMBOLS);
  else if (pattern->specifier & PatternSpecifier_o)
    actualWidth = strncpyType(tempString, buffer + indexOfActualValue,
                              widthToParse, S21_OCTAL_SYMBOLS);
  else if (pattern->specifier & (PatternSpecifier_x | PatternSpecifier_X))
    actualWidth = strncpyType(tempString, buffer + indexOfActualValue,
                              widthToParse, S21_HEX_SYMBOLS);
  else if (pattern->specifier &
           (PatternSpecifier_f | PatternSpecifier_e | PatternSpecifier_E |
            PatternSpecifier_g | PatternSpecifier_G))
    actualWidth = strncpyType(tempString, buffer + indexOfActualValue,
                              widthToParse, S21_FLOAT_SYMBOLS);
  else if (pattern->specifier & PatternSpecifier_s) {
    actualWidth =
        strncpyString(tempString, buffer + indexOfActualValue, widthToParse);
  } else if (pattern->specifier & PatternSpecifier_c) {
    actualWidth = strncpyString(tempString, buffer + indexOfActualValue, 1);
  }
  return actualWidth;
}

int parseBufferString(IPatternsConfig *config, const char *buffer,
                      s21_size_t index, va_list args, int *actualIndex) {
  int errorCode = errorCode_noError;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, &errorCode);
  IPattern *pattern = &config->patterns[index];
  int indexOfActualValue = s21_strlen(pattern->value);
  int widthToParse = pattern->width == 0 ? MAX_WIDTH_VALUE : pattern->width;
  if (pattern->width == SymbolCode_asterisk) pattern->isSkippable = 1;
  while (isSpaceSymbol(buffer[indexOfActualValue])) indexOfActualValue++;
  int actualWidth = getSubstringValueFromBuffer(
      tempString, pattern, buffer, widthToParse, indexOfActualValue);
  *actualIndex += actualWidth;
  *actualIndex += indexOfActualValue;
  int assignStatus = getValuesFromBuffer(config, tempString, index, args);
  free(tempString);
  return assignStatus;
}