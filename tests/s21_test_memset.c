#include "s21_test_memset.h"

int main() {
  int errcode = 0;
  case_test(memset_suite(), &errcode);
  return 0;
}
