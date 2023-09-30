#include "s21_test_atof.h"

int main() {
  int errcode = 0;
  case_test(atof_suite(), &errcode);
  return 0;
}