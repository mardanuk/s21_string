#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strncpy_test1) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncpy(string, string2, 3),
                   strncpy(string, string2, 3));
}
END_TEST

START_TEST(s21_strncpy_test2) {
  char string[] = "Hello";
  char string2[] = "Hello there";
  ck_assert_str_eq(s21_strncpy(string, string2, 3),
                   strncpy(string, string2, 3));
}
END_TEST

START_TEST(s21_strncpy_test3) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncpy(string, string2, 8),
                   strncpy(string, string2, 8));
}
END_TEST

START_TEST(s21_strncpy_test4) {
  char string[] = "";
  char string2[] = "";
  ck_assert_str_eq(s21_strncpy(string, string2, 1),
                   strncpy(string, string2, 1));
}
END_TEST

START_TEST(s21_strncpy_test5) {
  char string[] = "\0";
  char string2[] = "";
  ck_assert_str_eq(s21_strncpy(string, string2, 1),
                   strncpy(string, string2, 1));
}
END_TEST

START_TEST(s21_strncpy_test7) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncpy(string, string2, 3),
                   strncpy(string, string2, 3));
}
END_TEST

START_TEST(s21_strncpy_test6) {
  char string[] = "";
  char string2[] = "tertert";
  ck_assert_str_eq(s21_strncpy(string, string2, 1),
                   strncpy(string, string2, 1));
}
END_TEST

START_TEST(s21_strncpy_test8) {
  char string[] = "tretre";
  char string2[] = "\0";
  ck_assert_str_eq(s21_strncpy(string, string2, 3),
                   strncpy(string, string2, 3));
}
END_TEST

START_TEST(s21_strncpy_test9) {
  char string[] = "Hello";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncpy(string, string2, 5),
                   strncpy(string, string2, 5));
}
END_TEST

START_TEST(s21_strncpy_test10) {
  char string[8] = "tytuty";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncpy(string, string2, 1),
                   strncpy(string, string2, 1));
}
END_TEST

START_TEST(s21_strncpy_test11) {
  char string[] = "a";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strncpy(string, string2, 1),
                   strncpy(string, string2, 1));
}
END_TEST

START_TEST(s21_strncpy_test12) {
  char string[] = "a\003";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strncpy(string, string2, 3),
                   strncpy(string, string2, 3));
}
END_TEST

Suite *

strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strncpy");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncpy_test1);
  tcase_add_test(tc_core, s21_strncpy_test2);
  tcase_add_test(tc_core, s21_strncpy_test3);
  tcase_add_test(tc_core, s21_strncpy_test4);
  tcase_add_test(tc_core, s21_strncpy_test5);
  tcase_add_test(tc_core, s21_strncpy_test6);
  tcase_add_test(tc_core, s21_strncpy_test7);
  tcase_add_test(tc_core, s21_strncpy_test8);
  tcase_add_test(tc_core, s21_strncpy_test9);
  tcase_add_test(tc_core, s21_strncpy_test10);
  tcase_add_test(tc_core, s21_strncpy_test11);
  tcase_add_test(tc_core, s21_strncpy_test12);
  suite_add_tcase(s, tc_core);
  return s;
}
