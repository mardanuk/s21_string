#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_to_lower_test1) {
  char s1[] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test2) {
  char s1[] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test3) {
  char s1[] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test4) {
  char s1[] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test5) {
  char s1[] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test6) {
  char s1[] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

Suite *

to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("to_lower");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_to_lower_test1);
  tcase_add_test(tc_core, s21_to_lower_test2);
  tcase_add_test(tc_core, s21_to_lower_test3);
  tcase_add_test(tc_core, s21_to_lower_test4);
  tcase_add_test(tc_core, s21_to_lower_test5);
  tcase_add_test(tc_core, s21_to_lower_test6);
  tcase_add_test(tc_core, s21_to_lower_test7);

  suite_add_tcase(s, tc_core);
  return s;
}
