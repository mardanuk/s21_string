#include "../headers/s21_common.h"

int isStrDelim(char ch, const char *delim) {
  int result = 0;
  for (; delim && *delim != '\0'; delim++)
    if (*delim == ch) result = 1;
  return result;
}

int isEmptyString(const char *string) { return *string == 0; }

long double getRounder(int index) {
  long double resultValue = 0.5;
  for (int i = 0; i < index; ++i) {
    resultValue /= 10;
  }
  return resultValue;
}

int isSpaceSymbol(char c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' ||
          c == '\v');
}

int strncpyType(char *dest, const char *src, s21_size_t n,
                char *correctSymbols) {
  s21_size_t i = 0;
  char *tempSrc = (char *)src;
  for (; i < n && IS_ACCEPTABLE_SYMBOL(correctSymbols, *src) &&
         (*(dest++) = *(src++));
       i++) {
  };
  int length = src - tempSrc;
  return length;
}

int strncpyString(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  char *tempSrc = (char *)src;
  for (; i < n && !isSpaceSymbol(*src) && (*(dest++) = *(src++)); i++) {
  };
  int length = src - tempSrc;
  return length;
}

void handleUpperCase(IPattern *pattern, char *tempString) {
  if (pattern->specifier & PatternSpecifier_X) {
    char *upperCasedString = s21_to_upper(tempString);
    s21_strncpy(tempString, upperCasedString, s21_strlen(tempString));
    free(upperCasedString);
  }
}

void reverseString(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    end--;
    start++;
  }
}

void clearDecimalPart(char *decimal) {
  int i;
  for (i = (int)s21_strlen(decimal) - 1; decimal[i] == '0'; --i) decimal[i] = 0;
  if (decimal[i] == '.') decimal[i] = 0;
}

void handleMantissaInString(char *token, char *decimal, char *mantissa,
                            char *mantissaString) {
  if (token) {
    s21_strncpy(decimal, token, s21_strlen(token));
    token = s21_strtok(S21_NULL, mantissaString);
    if (token) {
      s21_strncat(mantissa, mantissaString, 1);
      s21_strncat(mantissa, token, s21_strlen(token));
    }
    if (s21_strchr(decimal, '.') != S21_NULL) {
      clearDecimalPart(decimal);
    }
  }
}

char *getMantissaString(IPattern *pattern) {
  return pattern->specifier & (PatternSpecifier_e | PatternSpecifier_g) ? "e"
                                                                        : "E";
}

char getMantissaSymbol(IPattern *pattern) {
  return pattern->specifier & (PatternSpecifier_e | PatternSpecifier_g) ? 'e'
                                                                        : 'E';
}

char getSpaceChar(IPattern *pattern) {
  return ((pattern->flag & PatternFlag_null) &&
          !(pattern->flag & PatternFlag_minus))
             ? '0'
             : ' ';
}

int getStartIndex(IPattern *patterns, int index) {
  return index != 0 ? patterns[index - 1].endIndexInFormat : 0;
}

void removeTrailingZeros(IPattern *pattern, char *string) {
  char *mantissaString = getMantissaString(pattern);
  char *token = s21_strtok(string, mantissaString);
  char decimal[100] = {0};
  char mantissa[6] = {0};
  handleMantissaInString(token, decimal, mantissa, mantissaString);
  clearBuffer(string, s21_strlen(string));
  s21_strncat(string, decimal, s21_strlen(decimal));
  if (mantissa[0] == mantissaString[0])
    s21_strncat(string, mantissa, s21_strlen(mantissa));
}

char *allocBuffer(s21_size_t length, int *errorCode) {
  char *tempString = calloc(length + 1, sizeof(char));
  if (!tempString) *errorCode = errorCode_allocBuffer;
  return tempString;
}

int isOctal(const char *string) {
  return *string == '0' && *(string + 1) > '0' && *(string + 1) < '8';
}

int isHex(const char *string) {
  return *string == '0' && (*(string + 1) == 'x' || *(string + 1) == 'X');
}

void clearBuffer(char *buffer, s21_size_t size) {
  for (s21_size_t i = 0; i < size; ++i) buffer[i] = 0;
}

int skipCommandSymbols(const char *buffer) {
  int shift = 0;
  while (*buffer++ <= S21_COMMAND_SYMBOL_UPPER_BOUND) shift++;
  return shift;
}

int fromCharToCode(int resultCode, int ch) {
  int code;
  if (ch == '%' || ch == 'h' || ch == '0')
    code = PatternSpecifier_percent;
  else if (ch == 'c' || ch == 'l' || ch == '-') {
    code = resultCode & PatternLength_l ? PatternLength_L : PatternLength_l;
  } else if (ch == 'd' || ch == 'L' || ch == '+')
    code = PatternSpecifier_d;
  else if (ch == 'i' || ch == ' ')
    code = PatternSpecifier_i;
  else if (ch == 'e' || ch == '#')
    code = PatternSpecifier_e;
  else if (ch == 'E')
    code = PatternSpecifier_E;
  else if (ch == 'f')
    code = PatternSpecifier_f;
  else if (ch == 'g')
    code = PatternSpecifier_g;
  else if (ch == 'G')
    code = PatternSpecifier_G;
  else if (ch == 'o')
    code = PatternSpecifier_o;
  else if (ch == 's')
    code = PatternSpecifier_s;
  else if (ch == 'u')
    code = PatternSpecifier_u;
  else if (ch == 'x')
    code = PatternSpecifier_x;
  else if (ch == 'X')
    code = PatternSpecifier_X;
  else if (ch == 'p')
    code = PatternSpecifier_p;
  else if (ch == 'n')
    code = PatternSpecifier_n;
  else
    code = 0;
  return code;
}

int fromStringToCode(const char *string) {
  int code = 0;
  for (s21_size_t i = 0; i < s21_strlen(string); ++i)
    code |= fromCharToCode(code, string[i]);
  return code;
}

int getSubstringFromString(regex_t *regexp, const char *inputString,
                           int groupNumber, char *string) {
  regmatch_t matches[groupNumber + 1];  // Add 1 for the entire match

  if (regexec(regexp, inputString, groupNumber + 1, matches, 0) == 0) {
    if (matches[groupNumber].rm_so != -1 && matches[groupNumber].rm_eo != -1) {
      int match_start = matches[groupNumber].rm_so;
      int match_end = matches[groupNumber].rm_eo;
      int match_length = match_end - match_start;
      s21_strncpy(string, inputString + match_start, match_length);
      string[match_length] = '\0';
      return 1;
    }
  }
  return 0;
}

int fillPatternInfo(IPatternsConfig *config, regex_t *regCompiled,
                    const char *format) {
  int patternIndex = config->count;
  int errorCode = errorCode_noError;
  char tempString[100] = {0};
  int code;
  if (patternIndex == config->allocatedCount)
    reallocPatternMemory(config, &errorCode);

  GET_SUBSTRING_CODE(GroupIndex_specifier, specifier)
  GET_SUBSTRING_CODE(GroupIndex_flag, flag)
  GET_SUBSTRING_CODE(GroupIndex_length, length)
  GET_SUBSTRING_VALUE(GroupIndex_width, width)
  GET_SUBSTRING_VALUE(GroupIndex_accuracy, accuracy)

  config->count++;
  return patternIndex;
}

void parseFormatString(IPatternsConfig *config, const char *format) {
  regex_t regCompiled;
  regmatch_t regMatches[S21_MAX_GROUPS] = {0};
  regcomp(&regCompiled, REG_EXPRESSION_FORMAT, REG_EXTENDED);
  int shift = 0;

  while ((regexec(&regCompiled, format + shift, S21_MAX_GROUPS, regMatches,
                  0) == 0)) {
    for (int i = 0; i < S21_MAX_GROUPS; ++i) {
      regMatches[i].rm_so += shift;
      regMatches[i].rm_eo += shift;
    }
    int patternIndex = fillPatternInfo(config, &regCompiled, format + shift);

    int startIndex = regMatches[0].rm_so;
    shift = regMatches[0].rm_eo;

    config->patterns[patternIndex].startIndexInFormat = startIndex;
    config->patterns[patternIndex].endIndexInFormat = shift;
  }

  regfree(&regCompiled);
}