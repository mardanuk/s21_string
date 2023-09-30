#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strlen_test1) {
  char string[] = "Hello there!";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}

END_TEST

START_TEST(s21_strlen_test2) {
  char string[] = "H";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}

END_TEST

START_TEST(s21_strlen_test3) {
  char string[] = "Hello0there";
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}

END_TEST

START_TEST(s21_strlen_test4) {
  char string[6000];
  memset(string, 'a', sizeof(string) - 1);
  string[sizeof(string) - 1] = '\0';
  ck_assert_int_eq(s21_strlen(string), strlen(string));
}

END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strlen");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strlen_test1);
  tcase_add_test(tc_core, s21_strlen_test2);
  tcase_add_test(tc_core, s21_strlen_test3);
  tcase_add_test(tc_core, s21_strlen_test4);
  suite_add_tcase(s, tc_core);
  return s;
}
