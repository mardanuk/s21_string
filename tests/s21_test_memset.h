#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_memset_test1) {
  char orig_str1[1000] = {0};
  char orig_str2[1000] = {0};
  char orig_str3[1000] = {0};
  char orig_str4[1000] = {0};
  char orig_str5[1000] = {0};
  char *origStrings[1000] = {orig_str1, orig_str2, orig_str3, orig_str4,
                             orig_str5};

  char test_str1[1000] = {0};
  char test_str2[1000] = {0};
  char test_str3[1000] = {0};
  char test_str4[1000] = {0};
  char test_str5[1000] = {0};

  char *testStrings[1000] = {test_str1, test_str2, test_str3, test_str4,
                             test_str5};
  char symbols[] = "QWEIJOSADNK!@09ujfon1230-wsad [12";

  int length = 1000;
  for (int h = 0; h < length; h += 14) {
    for (int i = 0; i < 5; ++i) {
      for (size_t j = 0; j < strlen(symbols); ++j) {
        s21_memset(testStrings[i], symbols[j], h);
        memset(origStrings[i], symbols[j], h);
        ck_assert_str_eq(testStrings[i], origStrings[i]);
      }
    }
  }
}

END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("memset");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memset_test1);
  suite_add_tcase(s, tc_core);
  return s;
}
