#include "../s21_string.h"
#include "s21_common.h"

#ifndef S21_SSCANF_H_
#define S21_SSCANF_H_

#define MAX_WIDTH_VALUE 1000

void prepareDataForSearch(IPatternsConfig *config, const char *format);

void assignInt(IPattern *, char *, va_list, int);

void assignFloat(IPattern *, char *, va_list);

void assignString(char *, va_list, s21_size_t);

int parseBufferString(IPatternsConfig *, const char *, s21_size_t, va_list,
                      int *);

int strncpyString(char *dest, const char *src, s21_size_t n);

int getValuesFromBuffer(IPatternsConfig *config, char *valueString,
                        s21_size_t index, va_list args);
#endif