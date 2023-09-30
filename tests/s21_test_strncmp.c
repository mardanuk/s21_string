
#include "s21_test_strncmp.h"

int main() {
  int errcode = 0;
  case_test(strncmp_suite(), &errcode);
  return 0;
}