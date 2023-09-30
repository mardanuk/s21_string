#include "s21_structs.h"

#ifndef S21_DYNAMIC_ARRAYS_H_
#define S21_DYNAMIC_ARRAYS_H_

void destroyPatternConfig(IPatternsConfig *);

void reallocPatternMemory(IPatternsConfig *, int *);

IPatternsConfig *initPatternsConfig(int *);

void initPatterns(IPattern *, int *, int, int);

#endif
