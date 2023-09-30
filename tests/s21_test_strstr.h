#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strstr_test1) {
  char string[] = "Hello there!";
  char string2[] = "lo";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test2) {
  char string[] = "Hello there!";
  char string2[] = "!";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test3) {
  char string[] = "Hello there!";
  char string2[] = "H";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test4) {
  char string[] = "!";
  char string2[] = "lo";
  ck_assert_ptr_null(s21_strstr(string, string2));
  ck_assert_ptr_null(strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test5) {
  char string[] = "Hello there!";
  char string2[] = "";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}

END_TEST

START_TEST(s21_strstr_test6) {
  char string[] = "";
  char string2[] = "";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test7) {
  char string[] = "He";
  char string2[] = "He";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}

END_TEST

START_TEST(s21_strstr_test8) {
  char string[] = "Hello there!";
  char string2[] = "ty";
  ck_assert_ptr_null(s21_strstr(string, string2));
  ck_assert_ptr_null(strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test9) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test10) {
  char string[] = "Hello  there";
  char string2[] = " ";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test11) {
  char string[] = " Hello there ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test12) {
  char string[] = "Hellothere  ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test13) {
  char string[] = "Hello there  ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strstr(string, string2), strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test14) {
  char string[] = "a";
  char string2[] = "a\203";
  ck_assert_ptr_null(s21_strstr(string, string2));
  ck_assert_ptr_null(strstr(string, string2));
}
END_TEST

START_TEST(s21_strstr_test15) {
  char string[] = "a\003";
  char string2[] = "a\203";
  ck_assert_ptr_null(s21_strstr(string, string2));
  ck_assert_ptr_null(strstr(string, string2));
}
END_TEST
Suite *

strstr_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strstr");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strstr_test1);
  tcase_add_test(tc_core, s21_strstr_test2);
  tcase_add_test(tc_core, s21_strstr_test3);
  tcase_add_test(tc_core, s21_strstr_test4);
  tcase_add_test(tc_core, s21_strstr_test5);
  tcase_add_test(tc_core, s21_strstr_test6);
  tcase_add_test(tc_core, s21_strstr_test7);
  tcase_add_test(tc_core, s21_strstr_test8);
  tcase_add_test(tc_core, s21_strstr_test9);
  tcase_add_test(tc_core, s21_strstr_test10);
  tcase_add_test(tc_core, s21_strstr_test11);
  tcase_add_test(tc_core, s21_strstr_test12);
  tcase_add_test(tc_core, s21_strstr_test13);
  tcase_add_test(tc_core, s21_strstr_test14);
  tcase_add_test(tc_core, s21_strstr_test15);
  suite_add_tcase(s, tc_core);
  return s;
}
