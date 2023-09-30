#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_trim_test1) {
  char testing_str[30] = "-?hello, world!";
  char delims[] = "!?-";
  char orig_result[] = "hello, world";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test2) {
  char testing_str[30] = "";
  char delims[] = "";
  char *orig_result = "";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test3) {
  char *testing_str = S21_NULL;
  char delims[] = "";
  char *orig_result = S21_NULL;
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test4) {
  char testing_str[30] = "!!!abcdefghij!?!";
  char delims[] = "!?";
  char orig_result[] = "abcdefghij";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test5) {
  char testing_str[30] = "abc";
  char delims[] = "333";
  char *orig_result = "abc";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test6) {
  char testing_str[30] = "hello, world!";
  char delims[] = "?!";
  char *orig_result = "hello, world";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test7) {
  char *testing_str = S21_NULL;
  char *delims = S21_NULL;
  char *orig_result = S21_NULL;
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test8) {
  char testing_str[30] = "";
  char delims[] = "";
  char orig_result[] = "";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test9) {
  char testing_str[] = " wtf ";
  char *delims = S21_NULL;
  char *orig_result = " wtf ";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

START_TEST(s21_trim_test10) {
  char testing_str[] = " wtf ";
  char *delims = "";
  char *orig_result = " wtf ";
  char *my_result = s21_trim(testing_str, delims);
  ck_assert_pstr_eq(orig_result, my_result);
  if (my_result) free(my_result);
}
END_TEST

Suite *

trim_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("trim");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_trim_test1);
  tcase_add_test(tc_core, s21_trim_test2);
  tcase_add_test(tc_core, s21_trim_test3);
  tcase_add_test(tc_core, s21_trim_test4);
  tcase_add_test(tc_core, s21_trim_test5);
  tcase_add_test(tc_core, s21_trim_test6);
  tcase_add_test(tc_core, s21_trim_test7);
  tcase_add_test(tc_core, s21_trim_test8);
  tcase_add_test(tc_core, s21_trim_test9);
  tcase_add_test(tc_core, s21_trim_test10);

  suite_add_tcase(s, tc_core);
  return s;
}
