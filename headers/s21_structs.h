#ifndef S21_STRUCTS_H
#define S21_STRUCTS_H

enum {
  errorCode_noError = 0,
  errorCode_allocPatterns = 1,
  errorCode_allocBuffer = 2,
  errorCode_reallocPatterns = 3,
  errorCode_nullptrString = 4,
  errorCode_allocConfig = 5
};
enum { SymbolCode_asterisk = -2 };

typedef enum {
  PatternSpecifier_percent = 1 << 1,
  PatternSpecifier_c = 1 << 2,
  PatternSpecifier_d = 1 << 3,
  PatternSpecifier_i = 1 << 4,
  PatternSpecifier_e = 1 << 5,
  PatternSpecifier_E = 1 << 6,
  PatternSpecifier_f = 1 << 7,
  PatternSpecifier_g = 1 << 8,
  PatternSpecifier_G = 1 << 9,
  PatternSpecifier_o = 1 << 10,
  PatternSpecifier_s = 1 << 11,
  PatternSpecifier_u = 1 << 12,
  PatternSpecifier_x = 1 << 13,
  PatternSpecifier_X = 1 << 14,
  PatternSpecifier_p = 1 << 15,
  PatternSpecifier_n = 1 << 16,
} PatternSpecifier;

typedef enum {
  PatternLength_h = 1 << 1,
  PatternLength_l = 1 << 2,
  PatternLength_L = 1 << 3
} PatternLength;

typedef enum {
  PatternFlag_null = 1 << 1,
  PatternFlag_minus = 1 << 2,
  PatternFlag_plus = 1 << 3,
  PatternFlag_space = 1 << 4,
  PatternFlag_hash = 1 << 5
} PatternFlag;

typedef struct {
  PatternSpecifier specifier;
  PatternFlag flag;
  int width;
  int isSkippable;
  int accuracy;
  PatternLength length;
  char *value;
  int startIndexInFormat;
  int endIndexInFormat;
} IPattern;

typedef struct {
  int *indexes;
  int **pointersArray;
  int count;
} IConfigSpecifierN;

typedef struct {
  IPattern *patterns;
  int count;
  int allocatedCount;
  int shiftValue;
  IConfigSpecifierN *configSpecifierN;
} IPatternsConfig;

typedef enum {
  GroupIndex_specifier = 8,
  GroupIndex_flag = 2,
  GroupIndex_length = 7,
  GroupIndex_width = 3,
  GroupIndex_accuracy = 6
} GroupIndex;

#endif