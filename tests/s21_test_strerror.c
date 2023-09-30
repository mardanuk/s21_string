
#include "s21_test_strerror.h"

int main() {
  int errcode = 0;
  case_test(strerror_suite(), &errcode);
  return 0;
}