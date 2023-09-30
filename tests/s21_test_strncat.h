#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strncat_test1) {
  char string[100] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 3),
                   strncat(string, string2, 3));
}
END_TEST

START_TEST(s21_strncat_test2) {
  char string[100] = "Hello";
  char string2[] = "Hello there";
  ck_assert_str_eq(s21_strncat(string, string2, 3),
                   strncat(string, string2, 3));
}
END_TEST

START_TEST(s21_strncat_test3) {
  char string[100] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 8),
                   strncat(string, string2, 8));
}
END_TEST

START_TEST(s21_strncat_test4) {
  char string[100] = "";
  char string2[] = "";
  ck_assert_str_eq(s21_strncat(string, string2, 0),
                   strncat(string, string2, 0));
}
END_TEST

START_TEST(s21_strncat_test5) {
  char string[100] = "\0";
  char string2[] = "";
  ck_assert_str_eq(s21_strncat(string, string2, 1),
                   strncat(string, string2, 1));
}
END_TEST

START_TEST(s21_strncat_test6) {
  char string[100] = "Hello";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 5),
                   strncat(string, string2, 5));
}
END_TEST

START_TEST(s21_strncat_test7) {
  char string[100] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 3),
                   strncat(string, string2, 3));
}
END_TEST

START_TEST(s21_strncat_test8) {
  char string[100] = "tretre";
  char string2[] = "\0";
  ck_assert_str_eq(s21_strncat(string, string2, 3),
                   strncat(string, string2, 3));
}
END_TEST

START_TEST(s21_strncat_test9) {
  char string[100] = "He\0llo";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 5),
                   strncat(string, string2, 5));
}
END_TEST

START_TEST(s21_strncat_test10) {
  char string[10] = "tytuty";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strncat(string, string2, 0),
                   strncat(string, string2, 0));
}
END_TEST
START_TEST(s21_strncat_test11) {
  char string[100] = "a";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strncat(string, string2, 1),
                   strncat(string, string2, 1));
}
END_TEST
START_TEST(s21_strncat_test12) {
  char string[100] = "a\003";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strncat(string, string2, 2),
                   strncat(string, string2, 2));
}
END_TEST

Suite *

strncat_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strncat");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strncat_test1);
  tcase_add_test(tc_core, s21_strncat_test2);
  tcase_add_test(tc_core, s21_strncat_test3);
  tcase_add_test(tc_core, s21_strncat_test4);
  tcase_add_test(tc_core, s21_strncat_test5);
  tcase_add_test(tc_core, s21_strncat_test6);
  tcase_add_test(tc_core, s21_strncat_test7);
  tcase_add_test(tc_core, s21_strncat_test8);
  tcase_add_test(tc_core, s21_strncat_test9);
  tcase_add_test(tc_core, s21_strncat_test10);
  tcase_add_test(tc_core, s21_strncat_test11);
  tcase_add_test(tc_core, s21_strncat_test12);
  suite_add_tcase(s, tc_core);
  return s;
}
