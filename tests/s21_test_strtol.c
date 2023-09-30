#include "s21_test_strtol.h"

int main() {
  int errcode = 0;
  case_test(strtol_suite(), &errcode);
  return 0;
}