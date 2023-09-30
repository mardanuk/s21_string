#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strrchr_test1) {
  char string[] = "Hello there!";
  char ch = 'l';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test2) {
  char string[] = "Hello there!";
  char ch = '\0';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test3) {
  char string[] = "Hello there!";
  char ch = 'H';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test4) {
  char string[] = "Hello there!";
  char ch = '!';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test5) {
  char string[] = "";
  char ch = '\0';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test6) {
  char string[] = "k";
  char ch = 'k';
  ck_assert_str_eq(s21_strrchr(string, ch), strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test7) {
  char string[] = "\0";
  char ch = 'k';
  ck_assert_ptr_null(s21_strrchr(string, ch));
  ck_assert_ptr_null(strrchr(string, ch));
}

END_TEST

START_TEST(s21_strrchr_test8) {
  char string[] = "\0";
  char subchar = '\0';
  ck_assert_int_eq(strcmp(s21_strrchr(string, subchar), ""), 0);
  ck_assert_int_eq(strcmp(strrchr(string, subchar), ""), 0);
}

END_TEST

Suite *

strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strrchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strrchr_test1);
  tcase_add_test(tc_core, s21_strrchr_test2);
  tcase_add_test(tc_core, s21_strrchr_test3);
  tcase_add_test(tc_core, s21_strrchr_test4);
  tcase_add_test(tc_core, s21_strrchr_test5);
  tcase_add_test(tc_core, s21_strrchr_test6);
  tcase_add_test(tc_core, s21_strrchr_test7);
  tcase_add_test(tc_core, s21_strrchr_test8);
  suite_add_tcase(s, tc_core);
  return s;
}
