#include "s21_test_memcpy.h"

int main() {
  int errcode = 0;
  case_test(memcpy_suite(), &errcode);
  return 0;
}
