#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_memcmp_test1) {
  char string[] = "School21 string. Just an example";
  char symbols[] = "school21 ";
  for (size_t l = 0; l < strlen(string) / 2; ++l) {
    for (size_t i = 0; i < strlen(string); ++i) {
      for (size_t j = 0; j < strlen(symbols) / 2; ++j) {
        for (size_t k = 0; k < strlen(string); ++k) {
          ck_assert_int_eq(memcmp(string + l, symbols + j, k),
                           s21_memcmp(string + l, symbols + j, k));
        }
      }
    }
  }
}

END_TEST
START_TEST(s21_memcmp_test2) {
  char string[] = "THERE IS SOMETHING IN THE DARK. HELP ME!!!";
  char symbols[] = "DARK! ";
  for (size_t l = 0; l < strlen(string) / 3; l += 3) {
    for (size_t i = 0; i < strlen(string); ++i) {
      for (size_t j = 0; j < strlen(symbols); ++j) {
        for (size_t k = 0; k < strlen(string) / 2; ++k) {
          ck_assert_int_eq(memcmp(string + l, symbols + j, k),
                           s21_memcmp(string + l, symbols + j, k));
        }
      }
    }
  }
}

END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("memcmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memcmp_test1);
  tcase_add_test(tc_core, s21_memcmp_test2);
  suite_add_tcase(s, tc_core);
  return s;
}