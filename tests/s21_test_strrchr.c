#include "s21_test_strrchr.h"

int main() {
  int errcode = 0;
  case_test(strrchr_suite(), &errcode);
  return 0;
}