#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_strpbrk_test1) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char string[] = "Hello there";
  char string2[] = "e";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char string[] = "Hello there";
  char string2[] = "le";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  char string[] = "";
  char string2[] = "Hello";
  ck_assert_ptr_null(s21_strpbrk(string, string2));
  ck_assert_ptr_null(strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test5) {
  char string[] = "\0";
  char string2[] = "Hello";
  ck_assert_ptr_null(s21_strpbrk(string, string2));
  ck_assert_ptr_null(strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test6) {
  char string[] = "";
  char string2[] = "";
  ck_assert_ptr_null(strpbrk(string, string2));
  ck_assert_ptr_null(s21_strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test7) {
  char string[] = "Hello there";
  char string2[] = "Hello";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test8) {
  char string[] = "tretre";
  char string2[] = "\0";
  ck_assert_ptr_null(strpbrk(string, string2));
  ck_assert_ptr_null(s21_strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test9) {
  char string[] = "abcdefe";
  char string2[] = "ei";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test10) {
  char string[] = "tytuty";
  char string2[] = "Hello";
  ck_assert_ptr_null(strpbrk(string, string2));
  ck_assert_ptr_null(s21_strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test11) {
  char string[] = "a";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test12) {
  char string[] = "a\003";
  char string2[] = "a\203";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST
START_TEST(s21_strpbrk_test13) {
  char string[] = "Hello  there";
  char string2[] = " ";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test14) {
  char string[] = " Hello there ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test15) {
  char string[] = "Hellothere  ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

START_TEST(s21_strpbrk_test16) {
  char string[] = "Hello there  ";
  char string2[] = " ";
  ck_assert_str_eq(s21_strpbrk(string, string2), strpbrk(string, string2));
}
END_TEST

Suite *

strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("strpbrk");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_strpbrk_test1);
  tcase_add_test(tc_core, s21_strpbrk_test2);
  tcase_add_test(tc_core, s21_strpbrk_test3);
  tcase_add_test(tc_core, s21_strpbrk_test4);
  tcase_add_test(tc_core, s21_strpbrk_test5);
  tcase_add_test(tc_core, s21_strpbrk_test6);
  tcase_add_test(tc_core, s21_strpbrk_test7);
  tcase_add_test(tc_core, s21_strpbrk_test8);
  tcase_add_test(tc_core, s21_strpbrk_test9);
  tcase_add_test(tc_core, s21_strpbrk_test10);
  tcase_add_test(tc_core, s21_strpbrk_test11);
  tcase_add_test(tc_core, s21_strpbrk_test12);
  tcase_add_test(tc_core, s21_strpbrk_test13);
  tcase_add_test(tc_core, s21_strpbrk_test14);
  tcase_add_test(tc_core, s21_strpbrk_test15);
  tcase_add_test(tc_core, s21_strpbrk_test16);

  suite_add_tcase(s, tc_core);
  return s;
}
