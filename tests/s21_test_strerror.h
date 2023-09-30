#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif
START_TEST(s21_strerror_test1) {
  for (int i = -50; i < 150; i++)
    ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST

Suite *

strerror_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strerror");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strerror_test1);
  suite_add_tcase(s, tc_core);
  return s;
}
