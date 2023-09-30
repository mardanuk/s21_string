
#include "s21_test_to_upper.h"

int main() {
  int errcode = 0;
  case_test(to_upper_suite(), &errcode);
  return 0;
}