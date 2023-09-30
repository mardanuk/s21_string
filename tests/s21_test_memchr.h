#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_memchr_test1) {
  char string[] = "School21 string. Just an example";
  char *symbols = "school21 ";
  for (size_t i = 0; i < strlen(string); ++i) {
    for (size_t j = 0; j < strlen(symbols); ++j) {
      ck_assert_ptr_eq(s21_memchr(string, symbols[j], i),
                       memchr(string, symbols[j], i));
    }
  }
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("memchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memchr_test1);
  suite_add_tcase(s, tc_core);
  return s;
}
