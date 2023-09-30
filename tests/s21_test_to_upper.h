#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif
START_TEST(s21_to_upper_test1) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test2) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test3) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper_test7) {
  char *s1 = S21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = S21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST
Suite *

to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("to_upper");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_upper_test1);
  tcase_add_test(tc_core, s21_to_upper_test2);
  tcase_add_test(tc_core, s21_to_upper_test3);
  tcase_add_test(tc_core, s21_to_upper_test4);
  tcase_add_test(tc_core, s21_to_upper_test5);
  tcase_add_test(tc_core, s21_to_upper_test6);
  tcase_add_test(tc_core, s21_to_upper_test7);

  suite_add_tcase(s, tc_core);
  return s;
}
