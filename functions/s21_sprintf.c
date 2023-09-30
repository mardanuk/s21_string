#include "../headers/s21_sprintf.h"

#include <stdio.h>

int s21_sprintf(char *str, const char *format, ...) {
  int errorCode = errorCode_noError;
  if (!str) errorCode = errorCode_nullptrString;
  clearBuffer(str, s21_strlen(str));
  IPatternsConfig *config = initPatternsConfig(&errorCode);
  parseFormatString(config, format);
  va_list args;
  va_start(args, format);
  for (int i = 0; i < config->count; i++)
    compilePatterns(config, args, i, &errorCode);
  applyAllPatterns(config, str, format);
  destroyPatternConfig(config);
  va_end(args);
  int result = (int)s21_strlen(str);
  return result;
}