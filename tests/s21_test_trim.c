
#include "s21_test_trim.h"

int main() {
  int errcode = 0;
  case_test(trim_suite(), &errcode);
  return 0;
}