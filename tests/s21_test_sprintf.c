
#include "s21_test_sprintf.h"

int main() {
  int errcode = 0;
  case_test(sprintf_suite(), &errcode);
  return errcode;
}