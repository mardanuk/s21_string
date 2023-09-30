#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strchr_test1) {
  char string[] = "Hello there!";
  char subchar = 'l';
  ck_assert_str_eq(s21_strchr(string, subchar), strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test4) {
  char string[] = "k";
  char subchar = 'k';
  ck_assert_str_eq(s21_strchr(string, subchar), strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test5) {
  char string[] = "\0";
  char subchar = 'k';
  ck_assert_ptr_null(s21_strchr(string, subchar));
  ck_assert_ptr_null(strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test6) {
  char string[] = "ytryrtytr";
  char subchar = '\0';
  ck_assert_str_eq(s21_strchr(string, subchar), strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test3) {
  char string[] = "ytryrtytr";
  char subchar = '0';
  ck_assert_ptr_null(s21_strchr(string, subchar));
  ck_assert_ptr_null(strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test7) {
  char string[] = "Hello there!";
  char subchar = 'H';
  ck_assert_str_eq(s21_strchr(string, subchar), strchr(string, subchar));
}
END_TEST

START_TEST(s21_strchr_test8) {
  char string[] = "Hello there!";
  char subchar = '!';
  ck_assert_str_eq(s21_strchr(string, subchar), strchr(string, subchar));
}
END_TEST

Suite *

strchr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strchr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strchr_test1);
  tcase_add_test(tc_core, s21_strchr_test3);
  tcase_add_test(tc_core, s21_strchr_test4);
  tcase_add_test(tc_core, s21_strchr_test5);
  tcase_add_test(tc_core, s21_strchr_test6);
  tcase_add_test(tc_core, s21_strchr_test7);
  tcase_add_test(tc_core, s21_strchr_test8);
  suite_add_tcase(s, tc_core);
  return s;
}
