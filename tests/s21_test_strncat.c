
#include "s21_test_strncat.h"

int main() {
  int errcode = 0;
  case_test(strncat_suite(), &errcode);
  return 0;
}