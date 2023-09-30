#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strncmp_test1) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 3),
                   strncmp(string, string2, 3));
}

END_TEST

START_TEST(s21_strncmp_test2) {
  char string[] = "Hello";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 5),
                   strncmp(string, string2, 5));
}

END_TEST

START_TEST(s21_strncmp_test3) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST

START_TEST(s21_strncmp_test4) {
  char string[] = "";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST

START_TEST(s21_strncmp_test5) {
  char string[] = "\0";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST

START_TEST(s21_strncmp_test6) {
  char *string = "";
  char *string2 = "";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST

START_TEST(s21_strncmp_test7) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST
START_TEST(s21_strncmp_test8) {
  char string[] = "tretre";
  char string2[] = "\0";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST
START_TEST(s21_strncmp_test10) {
  char string[] = "tytuty";
  char string2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(string, string2, 0),
                   strncmp(string, string2, 0));
}

END_TEST
START_TEST(s21_strncmp_test11) {
  char string[] = "a";
  char string2[] = "a\203";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST
START_TEST(s21_strncmp_test12) {
  char string[] = "a\003";
  char string2[] = "a\203";
  ck_assert_int_eq(s21_strncmp(string, string2, 8),
                   strncmp(string, string2, 8));
}

END_TEST

Suite *

strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strncmp");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncmp_test1);
  tcase_add_test(tc_core, s21_strncmp_test2);
  tcase_add_test(tc_core, s21_strncmp_test3);
  tcase_add_test(tc_core, s21_strncmp_test4);
  tcase_add_test(tc_core, s21_strncmp_test5);
  tcase_add_test(tc_core, s21_strncmp_test6);
  tcase_add_test(tc_core, s21_strncmp_test7);
  tcase_add_test(tc_core, s21_strncmp_test8);
  tcase_add_test(tc_core, s21_strncmp_test10);
  tcase_add_test(tc_core, s21_strncmp_test11);
  tcase_add_test(tc_core, s21_strncmp_test12);
  suite_add_tcase(s, tc_core);
  return s;
}
