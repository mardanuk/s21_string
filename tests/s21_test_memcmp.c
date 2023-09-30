#include "s21_test_memcmp.h"

int main() {
  int errcode = 0;
  case_test(memcmp_suite(), &errcode);
  return 0;
}
