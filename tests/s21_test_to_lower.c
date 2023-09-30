
#include "s21_test_to_lower.h"

int main() {
  int errcode = 0;
  case_test(to_lower_suite(), &errcode);
  return 0;
}