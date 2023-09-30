
#include "s21_test_strlen.h"

int main() {
  int errcode = 0;
  case_test(strlen_suite(), &errcode);
  return 0;
}