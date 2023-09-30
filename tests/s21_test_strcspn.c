
#include "s21_test_strcspn.h"

int main() {
  int errcode = 0;
  case_test(strcspn_suite(), &errcode);
  return 0;
}