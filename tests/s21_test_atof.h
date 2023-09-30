#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_atof_test1) {
  char *strings[] = {
      "1231", "1231", "-123", "00",   "0001", "9999", "101010",
      "11",   "15",   "-15",  "-150", "",     "1",    "0",
  };
  int count = 13;
  for (int i = 0; i < count; ++i) {
    ck_assert_float_eq(s21_atof(strings[i]), atof(strings[i]));
  }
}

END_TEST

Suite *atof_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("atof");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_atof_test1);
  suite_add_tcase(s, tc_core);
  return s;
}
