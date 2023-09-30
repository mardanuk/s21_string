
#include "s21_test_strncpy.h"

int main() {
  int errcode = 0;
  case_test(strncpy_suite(), &errcode);
  return 0;
}