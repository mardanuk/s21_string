#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strtol_test1) {
  char *strings[] = {"1231",   "1231", "-123", "00",   "0001",  "9999",
                     "101010", "11",   "15",   "-15",  "-150",  "",
                     "1",      "0",    "000",  "0x12", "0x150", "0x00000"};
  int count = 18;
  for (int indexBase = 2; indexBase < 35; ++indexBase) {
    for (int i = 0; i < count; ++i) {
      ck_assert_int_eq(s21_strtol(strings[i], NULL, indexBase),
                       strtol(strings[i], NULL, indexBase));
    }
  }
}

END_TEST

Suite *strtol_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strtol");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strtol_test1);
  suite_add_tcase(s, tc_core);
  return s;
}
