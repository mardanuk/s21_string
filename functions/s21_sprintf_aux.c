#include "../headers/s21_sprintf.h"

void compilePatternSpecifier_c(IPattern *pattern, int ch) {
  pattern->value[0] = (char)ch;
}

int getShiftSizeValue(IPattern *pattern, int isNegative) {
  int shiftValue = 0;
  if ((pattern->flag & PatternFlag_null) &&
      ((pattern->flag & (PatternFlag_plus | PatternFlag_space)) || isNegative))
    shiftValue = 1;
  return shiftValue;
}

int makeWidthTransform(char *src, IPattern *pattern, int sourceLength,
                       int *errorCode, int isNegative) {
  int spaceCount = pattern->width - sourceLength;
  char spaceChar = getSpaceChar(pattern);
  if (spaceCount > 0) {
    spaceCount = pattern->width - sourceLength;
    char *buffer = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
    s21_memset(buffer, spaceChar, spaceCount);
    if (!(pattern->flag & PatternFlag_minus)) {
      int shiftValue = getShiftSizeValue(pattern, isNegative);
      s21_strncat(buffer, src + shiftValue, s21_strlen(src + shiftValue));
      s21_strncpy(src + shiftValue, buffer, s21_strlen(buffer));
    } else
      s21_strncat(src, buffer, s21_strlen(buffer));
    free(buffer);
  } else
    spaceCount = 0;
  return spaceCount;
}

void scientificNotation(IPattern *pattern, double number, int width,
                        char *string) {
  int rank = 0, shift = 0;
  char mantissaSymbol = getMantissaSymbol(pattern);
  if (number < 0) {
    s21_sprintf(string, "-");
    number = -number;
    shift = 1;
  }
  if (number != 0) {
    while (number > S21_VALUE_LESS_THAN_10) {
      number /= 10.0;
      rank++;
    }
    while (number < S21_VALUE_LESS_THAN_1) {
      number *= 10.f;
      rank--;
    }
  }
  s21_sprintf(string + shift, S21_FORMAT_MANTISSA_STRING, width, number,
              mantissaSymbol, rank);
}

void compilePatternSpecifier_s(IPattern *pattern, va_list args,
                               int *errorCode) {
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
  char *inputString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
  if (pattern->length & PatternLength_l)
    wcstombs(inputString, va_arg(args, wchar_t *), S21_BUFFER_SIZE_1024);
  else
    s21_strncpy(inputString, va_arg(args, char *), S21_BUFFER_SIZE_1024);
  s21_strncpy(tempString, inputString, s21_strlen(inputString));
  makeWidthTransform(tempString, pattern, (int)s21_strlen(inputString),
                     errorCode, 0);
  s21_strncpy(pattern->value, tempString, s21_strlen(tempString));
  free(inputString);
  free(tempString);
}

void setSign(IPattern *pattern, int isNegative, char *tempString) {
  if (!isNegative) {
    if (pattern->flag & PatternFlag_plus)
      tempString[0] = '+';
    else if (pattern->flag & PatternFlag_space)
      tempString[0] = ' ';
  }
}

void applyWidthTransform(IPattern *pattern, char *tempString,
                         int lengthTempString, int isNegative, int *errorCode) {
  int countSpaceCharacters = makeWidthTransform(
      tempString, pattern, lengthTempString, errorCode, isNegative);
  s21_strncpy(pattern->value, tempString,
              lengthTempString + countSpaceCharacters);
}

void compilePatternSpecifier_integer(IPattern *pattern, long int num, int base,
                                     int *errorCode) {
  int isNegative = num < 0;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
  int shift = 0;
  if ((pattern->flag & (PatternFlag_plus | PatternFlag_space)) && !isNegative)
    shift = 1;
  s21_itoa(num, tempString + shift, base);
  setSign(pattern, isNegative, tempString);
  int lengthTempString = (int)s21_strlen(tempString);
  applyWidthTransform(pattern, tempString, lengthTempString, isNegative,
                      errorCode);
  free(tempString);
}

void compilePatternSpecifier_float(IPattern *pattern, long double num,
                                   int *errorCode) {
  int isNegative = num < 0;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_4096, errorCode);
  int shift = 0;
  if ((pattern->flag & (PatternFlag_plus | PatternFlag_space)) && !isNegative)
    shift = 1;
  s21_ftoa(num, tempString + shift, pattern->accuracy);
  setSign(pattern, isNegative, tempString);
  int lengthTempString = (int)s21_strlen(tempString);
  applyWidthTransform(pattern, tempString, lengthTempString, isNegative,
                      errorCode);
  free(tempString);
}

void compilePatternSpecifier_e(IPattern *pattern, double num, int width,
                               int *errorCode) {
  int isNegative = num < 0;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
  int shift = 0;
  if ((pattern->flag & (PatternFlag_plus | PatternFlag_space)) && !isNegative)
    shift = 1;
  setSign(pattern, isNegative, tempString);
  scientificNotation(pattern, num, width, tempString + shift);
  int lengthTempString = (int)s21_strlen(tempString + 1);
  applyWidthTransform(pattern, tempString, lengthTempString, isNegative,
                      errorCode);
  free(tempString);
}

void compilePatternSpecifier_x(IPattern *pattern, long int num,
                               int *errorCode) {
  int isNegative = num < 0;
  if (isNegative) num *= -1;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);
  int shift = 0;
  if (pattern->flag & PatternFlag_hash) shift = S21_HEX_PREFIX_LENGTH;
  if (isNegative) num = MAX_HEX_VALUE - (num - 1);
  if (pattern->flag & PatternFlag_plus) shift++;
  s21_itoa(num, tempString + shift, 16);
  handleUpperCase(pattern, tempString);
  if (pattern->flag & PatternFlag_hash) {
    tempString[0 + shift % S21_HEX_PREFIX_LENGTH] = '0';
    tempString[1 + shift % S21_HEX_PREFIX_LENGTH] =
        pattern->specifier & PatternSpecifier_X ? 'X' : 'x';
  }
  int lengthTempString = (int)s21_strlen(tempString);
  setSign(pattern, isNegative, tempString);
  applyWidthTransform(pattern, tempString, lengthTempString, isNegative,
                      errorCode);
  free(tempString);
}

int calculateActualAccuracy(float value, int precisionValue, int rank) {
  int accuracy =
      (value < S21_VALUE_UPPER_BOUND && value > S21_VALUE_LOWER_BOUND)
          ? precisionValue
          : precisionValue - 1;
  int actualAccuracy = 0;
  if (accuracy >= rank + 1) actualAccuracy = accuracy - rank;
  if (rank > S21_RANK_LOWER_BOUND && rank < S21_RANK_UPPER_BOUND)
    actualAccuracy = precisionValue;
  return actualAccuracy;
}

void fromValueToShortestRepresentation(IPattern *pattern, float value,
                                       char *tempString) {
  char *mantissaString = getMantissaString(pattern);
  char formatMantissaString[10] = "%.*";
  s21_strncat(formatMantissaString, mantissaString, 1);

  int precisionValue = pattern->accuracy;
  int rank = (int)log10f((float)fabsl(value));
  int accuracy = calculateActualAccuracy(value, precisionValue, rank);
  int isFloatForm = rank > -(precisionValue - 1) && rank < precisionValue;
  if (value == 0.f)
    s21_sprintf(tempString, "0");
  else if (isFloatForm)
    s21_sprintf(tempString, "%.*f", accuracy, value);
  else
    s21_sprintf(tempString, formatMantissaString, precisionValue - 1, value);
  removeTrailingZeros(pattern, tempString);
}

void compilePatternSpecifier_g(IPattern *pattern, float value, int *errorCode) {
  int isNegative = value < 0;
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, errorCode);

  fromValueToShortestRepresentation(pattern, value, tempString);

  int lengthTempString = (int)s21_strlen(tempString);
  setSign(pattern, isNegative, tempString);
  applyWidthTransform(pattern, tempString, lengthTempString, isNegative,
                      errorCode);

  free(tempString);
}

void compilePatternSpecifier_n(IPatternsConfig *config, int *pNum, int index) {
  int curIndexInArray = config->configSpecifierN->count;
  config->configSpecifierN->indexes[curIndexInArray] = index;
  config->configSpecifierN->pointersArray[curIndexInArray] = pNum;
  config->configSpecifierN->count++;
}

void handleAsterisk(IPattern *pattern, va_list args) {
  if (pattern->width == SymbolCode_asterisk) pattern->width = va_arg(args, int);
  if (pattern->accuracy == SymbolCode_asterisk)
    pattern->accuracy = va_arg(args, int);
}

void compilePatterns(IPatternsConfig *config, va_list args, int index,
                     int *errorCode) {
  IPattern *pattern = &config->patterns[index];
  formatPatternBeforeCompiling(pattern);
  handleAsterisk(pattern, args);
  int specifier = pattern->specifier;
  if (specifier & (PatternSpecifier_f))
    compilePatternSpecifier_float(pattern, va_arg(args, double), errorCode);
  if (specifier & (PatternSpecifier_g | PatternSpecifier_G))
    compilePatternSpecifier_g(pattern, va_arg(args, double), errorCode);
  if (specifier & (PatternSpecifier_e | PatternSpecifier_E))
    compilePatternSpecifier_e(pattern, va_arg(args, double), pattern->accuracy,
                              errorCode);
  if (specifier & (PatternSpecifier_d | PatternSpecifier_i))
    compilePatternSpecifier_integer(pattern, va_arg(args, int), 10, errorCode);
  if (specifier == PatternSpecifier_u)
    compilePatternSpecifier_integer(pattern, va_arg(args, unsigned int), 10,
                                    errorCode);
  if (specifier == PatternSpecifier_o)
    compilePatternSpecifier_integer(pattern, va_arg(args, unsigned int), 8,
                                    errorCode);
  if (specifier &
      (PatternSpecifier_x | PatternSpecifier_X | PatternSpecifier_p))
    compilePatternSpecifier_x(pattern, va_arg(args, long int), errorCode);
  if (specifier & PatternSpecifier_s)
    compilePatternSpecifier_s(pattern, args, errorCode);
  if (specifier & PatternSpecifier_c)
    compilePatternSpecifier_c(pattern, va_arg(args, int));
  if (specifier == PatternSpecifier_n)
    compilePatternSpecifier_n(config, va_arg(args, int *), index);
}

int assignPrintedLengthToValue(IPatternsConfig *config, char *outputString,
                               int index) {
  IConfigSpecifierN *configSpecifierN = config->configSpecifierN;
  for (int i = 0; i < configSpecifierN->count; ++i)
    if (configSpecifierN->indexes[i] == index &&
        configSpecifierN->pointersArray[i])
      *configSpecifierN->pointersArray[i] = (int)s21_strlen(outputString);
  return 0;
}

int getEndIndex(IPatternsConfig *config, int index, const char *format) {
  return index < config->count ? config->patterns[index].startIndexInFormat
                               : (int)s21_strlen(format);
}

void appendPatternValue(char *outputString, IPatternsConfig *config,
                        int index) {
  index != config->count
      ? s21_strncat(outputString, config->patterns[index].value,
                    s21_strlen(config->patterns[index].value))
      : 0;
}

int applyAllPatterns(IPatternsConfig *config, char *str, const char *format) {
  int errorCode = errorCode_noError;
  char *outputString = allocBuffer(S21_BUFFER_SIZE_1024, &errorCode);
  char *tempString = allocBuffer(S21_BUFFER_SIZE_1024, &errorCode);
  for (int i = 0; i <= config->count; ++i) {
    assignPrintedLengthToValue(config, outputString, i);
    clearBuffer(tempString, S21_BUFFER_SIZE_1024);
    int startIndex = getStartIndex(config->patterns, i);
    int endIndex = getEndIndex(config, i, format);
    format += startIndex;
    s21_strncpy(tempString, format, endIndex - startIndex);
    s21_strncat(outputString, tempString, s21_strlen(tempString));
    appendPatternValue(outputString, config, i);
    format -= startIndex;
  }
  s21_strncpy(str, outputString, s21_strlen(outputString));
  free(outputString);
  free(tempString);
  return errorCode;
}

void formatPatternBeforeCompiling(IPattern *pattern) {
  if (pattern->flag & PatternFlag_plus) pattern->flag &= ~PatternFlag_space;
  if (pattern->specifier & PatternSpecifier_p)
    pattern->flag |= PatternFlag_hash;
  if (pattern->specifier &
      (PatternSpecifier_f | PatternSpecifier_g | PatternSpecifier_G |
       PatternSpecifier_e | PatternSpecifier_E))
    if (pattern->accuracy == 0) pattern->accuracy = 6;
  if (pattern->specifier &
      (PatternSpecifier_u | PatternSpecifier_o | PatternSpecifier_p))
    pattern->flag &= ~PatternFlag_plus;
}