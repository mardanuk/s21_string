#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_memcpy_test1) {
  char src1[] =
      "qwertyuiopasdfghjklzxcvbnm,QWERTYUIOP{ASDFGHJKL:zxcvbnm<>"
      "sdFGHJK234567890$!@%&^#&**(()";
  int len = s21_strlen(src1);
  char test_dest1[100] = {0};
  char test_dest2[100] = {0};
  char test_dest3[100] = {0};
  char test_dest4[100] = {0};
  char test_dest5[100] = {0};
  char test_dest6[100] = {0};
  char test_dest7[100] = {0};
  char test_dest8[100] = {0};
  char test_dest9[100] = {0};
  char test_dest10[100] = {0};
  char *testStrings[100] = {test_dest1, test_dest2, test_dest3, test_dest4,
                            test_dest5, test_dest6, test_dest7, test_dest8,
                            test_dest9, test_dest10};
  char orig_dest1[100] = {0};
  char orig_dest2[100] = {0};
  char orig_dest3[100] = {0};
  char orig_dest4[100] = {0};
  char orig_dest5[100] = {0};
  char orig_dest6[100] = {0};
  char orig_dest7[100] = {0};
  char orig_dest8[100] = {0};
  char orig_dest9[100] = {0};
  char orig_dest10[100] = {0};
  char *origStrings[100] = {orig_dest1, orig_dest2, orig_dest3, orig_dest4,
                            orig_dest5, orig_dest6, orig_dest7, orig_dest8,
                            orig_dest9, orig_dest10};
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < len; ++k) {
        s21_memcpy(testStrings[j], src1 + len, len);
        memcpy(origStrings[j], src1 + len, len);
        ck_assert_str_eq(testStrings[j], origStrings[j]);
      }
    }
  }
}

END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("memcpy");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, s21_memcpy_test1);

  suite_add_tcase(s, tc_core);
  return s;
}
