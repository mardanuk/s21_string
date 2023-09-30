#ifndef TEST_HEADER_
#define TEST_HEADER_

#include "../s21_string.h"
#include "s21_test.h"

#endif

START_TEST(s21_insert_test1) {
  char src[30] = "hello, world!";
  char str[] = "hELLO, WORLD!";
  char orig_result[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test2) {
  char src[30] = "";
  char str[] = "";
  char *orig_result = S21_NULL;
  s21_size_t num = 7;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test3) {
  char *src = S21_NULL;
  char str[] = "";
  char *orig_result = S21_NULL;
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test4) {
  char src[30] = "abcdefghij";
  char str[] = "\'I WAS HERE\'";
  char orig_result[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test5) {
  char src[30] = "abc";
  char str[] = "333";
  char *orig_result = S21_NULL;
  s21_size_t num = 10;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test6) {
  char src[30] = "hello, world!";
  char str[] = "hELLO, WORLD!";
  char *orig_result = S21_NULL;
  s21_size_t num = -1;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test7) {
  char *src = S21_NULL;
  char *str = S21_NULL;
  char *orig_result = S21_NULL;
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test8) {
  char src[30] = "";
  char str[] = "";
  char orig_result[] = "";
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test9) {
  char src[] = "wtf";
  char *str = S21_NULL;
  char *orig_result = S21_NULL;
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(orig_result, my_res);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test10) {
  char src[] = "";
  char *str = S21_NULL;
  char *orig_result = S21_NULL;
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(my_res, orig_result);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test11) {
  char src[] = "sad";
  char *str = "mad";
  char *orig_result = "madsad";
  s21_size_t num = 0;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(my_res, orig_result);
  if (my_res) free(my_res);
}
END_TEST

START_TEST(s21_insert_test12) {
  char src[] = "sad";
  char *str = "mad";
  char *orig_result = "sadmad";
  s21_size_t num = 3;
  char *my_res = s21_insert(src, str, num);
  ck_assert_pstr_eq(my_res, orig_result);
  if (my_res) free(my_res);
}
END_TEST
Suite *

insert_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("insert");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_insert_test1);
  tcase_add_test(tc_core, s21_insert_test2);
  tcase_add_test(tc_core, s21_insert_test3);
  tcase_add_test(tc_core, s21_insert_test4);
  tcase_add_test(tc_core, s21_insert_test5);
  tcase_add_test(tc_core, s21_insert_test6);
  tcase_add_test(tc_core, s21_insert_test7);
  tcase_add_test(tc_core, s21_insert_test8);
  tcase_add_test(tc_core, s21_insert_test9);
  tcase_add_test(tc_core, s21_insert_test10);
  tcase_add_test(tc_core, s21_insert_test11);
  tcase_add_test(tc_core, s21_insert_test12);

  suite_add_tcase(s, tc_core);
  return s;
}
