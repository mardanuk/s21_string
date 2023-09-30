
#include "s21_test_strstr.h"

int main() {
  int errcode = 0;
  case_test(strstr_suite(), &errcode);
  return 0;
}