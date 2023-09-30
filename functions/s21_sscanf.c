#include "../headers/s21_sscanf.h"

int s21_sscanf(const char *buffer, const char *format, ...) {
  int errorCode = errorCode_noError;
  int result = 0;
  if (!buffer || !format) errorCode = errorCode_nullptrString;
  if (!errorCode) {
    IPatternsConfig *config = initPatternsConfig(&errorCode);
    int actualIndex = 0;
    parseFormatString(config, format);
    prepareDataForSearch(config, format);
    va_list args;
    va_start(args, format);
    for (int i = 0; i < config->count; i++) {
      result += parseBufferString(config, buffer + actualIndex, i, args,
                                  &actualIndex);
    }
    va_end(args);
    destroyPatternConfig(config);
  }
  return result;
}