
#include "s21_test_strtok.h"

int main() {
  int errcode = 0;
  case_test(strtok_suite(), &errcode);
  return 0;
}