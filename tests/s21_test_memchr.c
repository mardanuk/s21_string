#include "s21_test_memchr.h"

int main() {
  int errcode = 0;
  case_test(memchr_suite(), &errcode);
  return 0;
}
