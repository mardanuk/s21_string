
#include "s21_test_sscanf.h"

int main() {
  int errcode = 0;
  case_test(sscanf_suite(), &errcode);
  return errcode;
}