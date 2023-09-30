
#include "s21_test_strchr.h"

int main() {
  int errcode = 0;
  case_test(strchr_suite(), &errcode);
  return 0;
}