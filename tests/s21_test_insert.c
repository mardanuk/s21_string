
#include "s21_test_insert.h"

int main() {
  int errcode = 0;
  case_test(insert_suite(), &errcode);
  return 0;
}