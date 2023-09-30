#include "main_test.h"

int main() {
  int errcode = 0;
  case_test(strlen_suite(), &errcode);
  case_test(memchr_suite(), &errcode);
  case_test(memcmp_suite(), &errcode);
  case_test(memcpy_suite(), &errcode);
  case_test(memset_suite(), &errcode);
  case_test(sprintf_suite(), &errcode);
  case_test(sscanf_suite(), &errcode);
  case_test(strchr_suite(), &errcode);
  case_test(strcspn_suite(), &errcode);
  case_test(strerror_suite(), &errcode);
  case_test(strlen_suite(), &errcode);
  case_test(strncat_suite(), &errcode);
  case_test(strncmp_suite(), &errcode);
  case_test(strncpy_suite(), &errcode);
  case_test(strpbrk_suite(), &errcode);
  case_test(strrchr_suite(), &errcode);
  case_test(strstr_suite(), &errcode);
  case_test(strtok_suite(), &errcode);
  case_test(strtol_suite(), &errcode);
  case_test(atof_suite(), &errcode);
  case_test(insert_suite(), &errcode);
  case_test(to_lower_suite(), &errcode);
  case_test(to_upper_suite(), &errcode);
  case_test(trim_suite(), &errcode);
  return errcode;
}