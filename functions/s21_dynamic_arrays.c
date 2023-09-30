#include "../headers/s21_common.h"

void initPatterns(IPattern *patterns, int *errorCode, int startIndex,
                  int endIndex) {
  for (int i = startIndex; i < endIndex; ++i) {
    patterns[i].value = allocBuffer(S21_BUFFER_SIZE_4096, errorCode);
    patterns[i].specifier = -1;
    patterns[i].flag = -1;
    patterns[i].width = -1;
    patterns[i].isSkippable = 0;
    patterns[i].accuracy = -1;
    patterns[i].length = -1;
    patterns[i].startIndexInFormat = -1;
    patterns[i].endIndexInFormat = -1;
  }
}

IConfigSpecifierN *initConfigSpecifierN(int *errorCode) {
  IConfigSpecifierN *configSpecifierN = calloc(1, sizeof(IConfigSpecifierN));
  if (!configSpecifierN) *errorCode = errorCode_allocConfig;
  int *indexes = calloc(S21_INIT_COUNT, sizeof(int));
  if (!indexes) *errorCode = errorCode_allocConfig;
  int **pointerArray = calloc(S21_INIT_COUNT, sizeof(int *));
  if (!pointerArray) *errorCode = errorCode_allocConfig;
  configSpecifierN->indexes = indexes;
  configSpecifierN->pointersArray = pointerArray;
  configSpecifierN->count = 0;
  return configSpecifierN;
}

IPatternsConfig *initPatternsConfig(int *errorCode) {
  IPatternsConfig *config = calloc(1, sizeof(IPatternsConfig));
  if (!config) *errorCode = errorCode_allocConfig;
  IPattern *patterns = calloc(S21_INIT_COUNT, sizeof(IPattern));
  if (!patterns) *errorCode = errorCode_allocPatterns;
  config->patterns = patterns;
  if (!*errorCode) {
    initPatterns(config->patterns, errorCode, 0, S21_INIT_COUNT);
    config->count = 0;
    config->allocatedCount = S21_INIT_COUNT;
    config->shiftValue = 0;
  }
  IConfigSpecifierN *configSpecN = initConfigSpecifierN(errorCode);
  config->configSpecifierN = configSpecN;
  return config;
}

void reallocPatternMemory(IPatternsConfig *config, int *errorCode) {
  IPattern *tempArray =
      realloc(config->patterns,
              (config->allocatedCount + S21_APPEND_COUNT) * sizeof(IPattern));
  if (!tempArray)
    *errorCode = errorCode_reallocPatterns;
  else {
    config->patterns = tempArray;
    initPatterns(config->patterns, errorCode, config->allocatedCount,
                 config->allocatedCount + S21_APPEND_COUNT);
    config->allocatedCount = config->allocatedCount + S21_APPEND_COUNT;
  }
}

void destroyPatternConfig(IPatternsConfig *config) {
  for (int i = 0; i < config->allocatedCount; ++i)
    free(config->patterns[i].value);
  free(config->patterns);
  free(config->configSpecifierN->pointersArray);
  free(config->configSpecifierN->indexes);
  free(config->configSpecifierN);
  free(config);
}
