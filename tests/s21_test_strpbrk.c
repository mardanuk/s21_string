
#include "s21_test_strpbrk.h"

int main() {
  int errcode = 0;
  case_test(strpbrk_suite(), &errcode);
  return 0;
}